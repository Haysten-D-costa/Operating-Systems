#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

int buffer[MAX];
int mutex = 1, counter = 0;
int buffSize = 0, in =0, out = 0;
int buffEmpty = 4, buffFull = 0, nextConsumed, nextProduced;

int signal(int s) {
    return s++;
}
int wait(int s) {
    while(s < 0) { 
        cout << "Deadlock !" << endl; 
        return 0;    
    }
    return s--;
}
int producer() {
    mutex = wait(mutex);
    buffEmpty = wait(buffEmpty);

    if(counter == buffSize) { cout << "Buffer Full !"; }
    else {
        cout << "Item to be produced ? ";
        cin >> nextProduced;
        cout << "Item Produced is : " << nextProduced;
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

    if(counter == 0) { cout << "Buffer Empty !"; }
    else {
        nextConsumed = buffer[out];
        cout << "Item consumed : " << nextConsumed;
        out = (out + 1) % buffSize;
        counter--;
    }
    mutex = signal(mutex);
    buffEmpty = signal(buffEmpty);
}

int main() {
    int choice;
    cout << "\nEnter the size of buffer : "; 

    cin >> buffSize;
    cout << endl << "1 <- To Produce item...." << endl
              << "2 <- To Consume item...." << endl
              << "0 <- To Exit....";
    do {
        cout << endl << "\nChoice ? "; 
        cin >> choice;

        switch(choice) {
            case 0 : {
                cout << "Program Exited !\n";
                exit(0);
            } break;
            case 1 : producer(); break;
            case 2 : consumer(); break;
            default: cout << "Invalid !" << endl;
        }
    } while (true);

    return 0;
}