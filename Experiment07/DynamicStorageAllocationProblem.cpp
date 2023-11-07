#include <iostream>
#include <vector>
#define MAX 5
using namespace std;

int block_count = 4;
int process_count = 4;
int blockSize[MAX];
int processSize[MAX];

void sortAsc(int A[MAX], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(A[j] > A[j+1]) 
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
void sortDesc(int A[MAX], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(A[j] < A[j+1]) 
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void bestFit() 
{
    int j=0;
    sortAsc(blockSize, block_count);
    sortAsc(processSize, process_count);

    for(int i=0; i<block_count; i++) {
        if(processSize[i] <= blockSize[i]) { 
            cout << "P" << i+1 << "(" << processSize[i] << ") : " << "B" << i+1 << "(" << blockSize[j] << ")\n"; 
            j++;
        }
        else { cout << "P" << i+1 << "(" << processSize[i] << ") :  Unallocated !\n"; }
    }
}
void firstFit() {
    bool blockAllocated[block_count];
    for(int i=0; i<block_count; i++) { blockAllocated[i] = false; }

    for(int p=0; p<process_count; p++) {
        int b = 0;
        int flag = 0;
        while(b < block_count) {
            if(processSize[p] <= blockSize[b] && !blockAllocated[b]) {
                cout << "P" << p+1 << "(" << processSize[p] << ") : " << "B" << b+1 << "(" << blockSize[b] << ")\n"; 
                blockAllocated[b] = true;
                flag = 1;
                break;
            }
            b++;
        }
        if(flag == 0) { cout << "P" << p+1 << "(" << processSize[p] << ") :  Unallocated !\n"; }
    }
}
void worstFit() {
    int j = 0;
    sortDesc(blockSize, block_count);

    for(int i=0; i<block_count; i++) {
        if(processSize[i] <= blockSize[i]) { 
            cout << "P" << i+1 << "(" << processSize[i] << ") : " << "B" << i+1 << "(" << blockSize[j] << ")\n"; 
            j++;
        }
        else { cout << "P" << i+1 << "(" << processSize[i] << ") :  Unallocated !\n"; }
    }
}

int main() {
    cout << "\nEnter the no. of blocks : "; cin >> block_count;
    cout << "Enter the block sizes : \n";
    for(int i=0; i<block_count; i++) {
        cout << "Block " << i+1 << " : ";
        cin >> blockSize[i];
    }
    cout << "\nEnter the no. of processes : "; cin >> process_count;
    cout << "Enter the process sizes : \n";
    for(int i=0; i<process_count; i++) {
        cout << "Process " << i+1 << " : ";
        cin >> processSize[i];
    }
    int choice;
    cout << "\n1 <- Best Fit Algorithm" 
         << "\n2 <- First Fit Algorithm"
         << "\n3 <- Worst Fit Algorithm";
    cout << "\nchoice ? : ";
    cin >> choice;
    cout << "\n";

    switch(choice) {
        case 1 : bestFit(); break;
        case 2 : firstFit(); break;
        case 3 : worstFit(); break;
        default : cout << "Invalid choice !";
    }
    return 0;
}