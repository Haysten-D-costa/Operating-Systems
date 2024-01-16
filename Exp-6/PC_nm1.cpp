#include <iostream>
#define MAX 10
using namespace std;

int buffSize = MAX;
int in = 0, out = 0, nextConsumed, nextProduced;
int BUFFER[MAX], full = 0, empty = MAX, mutex = 1;

int signal(int s) {
    return s++;
}
int wait(int s) {
    while(s < 0) {
        cout << "\nDeadlock\n";
        return 0;
    }
    return s--;
}
void producer() {
    mutex = wait(mutex);
    full = signal(full);
    if((in + 1) % buffSize == out) { cout << "\nBUFFER FULL !\n"; }
    else {
        cout << "Item to be produced ? "; cin >> nextProduced;
        BUFFER[in] = nextProduced;
        in = (in + 1) % buffSize;
    }
    mutex = wait(mutex);
    empty = signal(empty);
}
void consumer() {
    mutex = wait(mutex);
    empty = signal(empty);
    if(in == out) { cout << "\nBUFFER EMPTY !\n"; }
    else {
        nextConsumed = BUFFER[out];
        cout << "Item Consumed : " << nextConsumed;
        out = (out + 1) % buffSize;
    }
    mutex = wait(mutex);
    full = signal(full);
}

int main() {
    cout << "Enter buffer size : "; cin >> buffSize;
    int choice;
    do {
        cout << "\n1.Produce\n2.Consume\n0.Exit\nChoice ? "; cin >> choice;
        switch(choice) 
        {
            case 1 : producer(); break;
            case 2 : consumer(); break;
            case 0 : exit(1);
            default: cout << "\nInvalid choice\n";
        }
    } while(true);
    return 0;
}
