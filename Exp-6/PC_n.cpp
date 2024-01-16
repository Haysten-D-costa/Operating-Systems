#include <iostream>
#define MAX 10
using namespace std;

int mutex = 1, BUFFER[MAX];
int in = 0, out = 0;
int full = 0, empty = MAX, counter = 0;
int buffSize = MAX, nextProduced, nextConsumed;

int signal(int s) {
    return s++;
} 
int wait(int s) {
    while(s < 0) {
        cout << "DEADLOCK";
        return 0;
    }
    return s--;
}

void producer() {
    mutex = wait(mutex);
    empty = signal(empty);
    if(counter == buffSize) { cout << "Buffer full !"; }
    else {
        cout << "Item to be produced ? "; cin >> nextProduced;
        BUFFER[in] = nextProduced;
        in = (in + 1) % buffSize;
        counter++;
    }
    mutex = wait(mutex);
    full = signal(full);
}

void consumer() {
    mutex = wait(mutex);
    full = signal(full);
    if(counter == 0) {
        cout << "\nBuffer Empty !\n";
    }
    else {
        nextConsumed = BUFFER[out];
        cout << "CONSUMED : " << nextConsumed;
        out = (out + 1) % buffSize;
        counter--;
    }
    mutex = wait(mutex);
    empty = signal(empty);
}

int main() {
    int choice;
    cout << "Enter buffer size : "; cin >> buffSize;
    do {
        cout << "\n1 -> Produce....\n"
             << "2 -> Consume....\n"
             << "0 -> Exit....\n";
        cout << "Choice ? \n";
        cin >> choice;
        
        switch(choice) {
            case 1 : producer();
                     break;
            case 2 : consumer();
                     break;
            case 0 : exit(1);
            default: cout << "\nInvalid Choice\n";
        }
    } while(true);
    return 0;
}