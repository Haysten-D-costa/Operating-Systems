#include <iostream>
#include <vector>
#define MAX 5
using namespace std;

int block_count = 4;
int process_count = 4;
int blockSize[MAX] = {200, 100, 150, 60}, processSize[MAX] = {80, 200, 50, 120};

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
void worstFit() {
    
    for(int i=0; i<block_count; i++) {
        if(processSize[i] <= blockSize[i]) { cout << "P" << i << "(" << processSize[i] << ") : " << "B" << i << "(" << blockSize[i] << ")\n"; }
        else { cout << "Unallocated !\n"; }
    }
}
// void bestFit() {}
// void firstFit() {}

int main() {
    // cout << "\nEnter the no. of blocks : "; cin >> block_count;
    // cout << "Enter the block sizes : \n";
    // for(int i=0; i<block_count; i++) {
    //     cout << "Block " << i << " : ";
    //     cin >> blockSize[i];
    // }
    // cout << "\nEnter the no. of processes : "; cin >> process_count;
    // cout << "Enter the process sizes : \n";
    // for(int i=0; i<process_count; i++) {
    //     cout << "Process " << i << " : ";
    //     cin >> processSize[i];
    // }



    // bestFit();
    // firstFit();
    worstFit();

    return 0;
}