#include <iostream>
#define MAX 10
using namespace std;

int n;
double wt = 0, tat = 0;
double BT[MAX]{0}, WT[MAX]{0}, TAT[MAX]{0};

void fcfs() {
    WT[0] = 0;
    for(int i=1; i<n; i++) { // computing the WT...
        WT[i] = WT[i-1] + BT[i-1];
    }
    for(int i=0; i<n; i++) { // computing the TAT and sum of tat and wt...
        TAT[i] = WT[i] + BT[i];
        wt += WT[i];
        tat += TAT[i];
    }
}

int main() {
    
    cout << "Enter no. of processes : ";
    cin >> n;

    for(int i=0; i<n; i++) {
        cout << "Enter BT for P" << i << " : ";
        cin >> BT[i];
    }
    fcfs();
    cout << "\nProcess\tBurstTime\tWaitingTime\tTurnAroundTime\n";
    for(int i=0; i<n; i++) {
        cout << "P" << i << "\t" << BT[i] << "\t\t" << WT[i] << "\t\t" << TAT[i] << "\n";
    }
    cout << "\nAverage Waiting Time     : " << wt / n;
    cout << "\nAverage Turn Around Time : " << tat / n << "\n\n";
    
    return 0;
}