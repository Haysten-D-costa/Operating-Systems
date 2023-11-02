#include <iostream>
#include <stdlib.h>
#define MAX 10

int buffer[MAX];
int mutex = 1, counter = 0;
int buffSize = 0, in =0, out = 0;
int buffEmpty = 4, buffFull = 0, nextConsumed, nextProduced;

int wait(int s) {
    while(s < 0) { 
        std::cout << "Deadlock !" << std::endl; 
        return 0;    
    }
    return s--;
}
int signal(int s) {
    return s++;
}
int producer() {
    mutex = wait(mutex);
    buffEmpty = wait(buffEmpty);

    if(counter == buffSize) { std::cout << "Buffer Full !"; }
    else {
        std::cout << "Item to be produced ? ";
        std::cin >> nextProduced;
        std::cout << "Item Produced is : " << nextProduced;
        buffer[in] = nextProduced;
        in = (in + 1) % buffSize; 
        counter++;
    }
    mutex = signal(mutex);
    buffFull = signal(buffFull);
}
int consumer() {
    mutex = wait(mutex);
    buffFull = wait(buffFull);

    if(counter == 0) { std::cout << "Buffer Empty !"; }
    else {
        nextConsumed = buffer[out];
        std::cout << "Item consumed : " << nextConsumed;
        out = (out + 1) % buffSize;
        counter--;
    }
    mutex = signal(mutex);
    buffEmpty = signal(buffEmpty);
}

int main() {
    int choice;
    std::cout << "\nEnter the size of buffer : "; 

    std::cin >> buffSize;
    std::cout << std::endl << "1 <- To Produce item...." << std::endl
              << "2 <- To Consume item...." << std::endl
              << "0 <- To Exit....";
    do {
        std::cout << std::endl << "\nChoice ? "; 
        std::cin >> choice;

        switch(choice) {
            case 0 : {
                std::cout << "Program Exited !\n";
                exit(0);
            } break;
            case 1 : producer(); break;
            case 2 : consumer(); break;
            default: std::cout << "Invalid !" << std::endl;
        }
    } while (true);

    return 0;
}