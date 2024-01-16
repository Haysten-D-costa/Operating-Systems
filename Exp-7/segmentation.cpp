#include <iostream>
#define MAX 10
using namespace std;

int processes, blocks;
int flag, index, diff, occupied[MAX], allocated[MAX];
int pSize[MAX], bSize[MAX];

void firstFit() {
    for(int i=0; i<processes; i++) allocated[i] = -1;
    for(int i=0; i<blocks; i++) occupied[i] = 0;

    for(int i=0; i<processes; i++) {
        for(int j=0; j<blocks; j++) {
            if(!occupied[j] && pSize[i] <= bSize[j]) {
                allocated[i] = j;
                occupied[j] = 1;
                break;
            }
        }
    }
    cout << "Process\t\tProcessSize\tBlock\n";
    for(int i=0; i<processes; i++) {
        cout << "P" << (i + 1) << "\t\t" << pSize[i] << "\t\t";
        if(allocated[i] != -1) {
            cout << "B" << allocated[i]+1 << "\t\t" << "\n";
        } else {
            cout << "Unallocated !\n";
        }
    }
}

void bestFit() {
    for(int i=0; i<processes; i++) allocated[i] = -1;
    for(int i=0; i<blocks; i++) occupied[i] = 0;

    for(int i=0; i<processes; i++) {
        diff = 1000;
        for(int j=0; j<blocks; j++) {
            if(!occupied[j] && pSize[i] <= bSize[j]) {
                if(bSize[j] - pSize[i] < diff) {
                    diff = bSize[j] - pSize[i];
                    index = j;
                }
            }
        }
        allocated[i] = index;
        occupied[index] = 1;
    }
    cout << "Process\t\tProcessSize\tBlock\n";
    for(int i=0; i<processes; i++) {
        cout << "P" << (i + 1) << "\t\t" << pSize[i] << "\t\t";
        if(allocated[i] != -1) {
            cout << "B" << allocated[i]+1 << "\t\t" << "\n";
        } else {
            cout << "Unallocated !\n";
        }
    }
}

void worstFit() {
    for(int i=0; i<processes; i++) allocated[i] = -1;
    for(int i=0; i<blocks; i++) occupied[i] = 0;

    for(int i=0; i<processes; i++) {
        flag = 0;
        diff = 0;
        for(int j=0; j<blocks; j++) {
            if(!occupied[j] && pSize[i] <= bSize[j]) {
                if(bSize[j] - pSize[i] > diff) {
                    diff = bSize[j] - pSize[i];
                    index = j;
                    flag = 1;
                }
            }
        }
        if(flag) {
            allocated[i] = index;
            occupied[index] = 1;
        }
    }
    cout << "Process\t\tProcessSize\tBlock\n";
    for(int i=0; i<processes; i++) {
        cout << "P" << (i + 1) << "\t\t" << pSize[i] << "\t\t";
        if(allocated[i] != -1) {
            cout << "B" << allocated[i]+1 << "\t\t" << "\n";
        } else {
            cout << "Unallocated !\n";
        }
    }
}

int main() {
    cout << "Enter no. of processes : "; cin >> processes;
    cout << "Enter process sizes    : ";
    for(int i=0; i<processes; i++) {
        cin >> pSize[i];
    }
    cout << "Enter no. of blocks : "; cin >> blocks;
    cout << "Enter block sizes   : ";
    for(int i=0; i<blocks; i++) {
        cin >> bSize[i];
    }
    cout << "\nFIRST FIT : \n"; firstFit();
    cout << "\nBEST FIT  : \n"; bestFit();
    cout << "\nWORST FIT : \n"; worstFit();
    return 0;
}