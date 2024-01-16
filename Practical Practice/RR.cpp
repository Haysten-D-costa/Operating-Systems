#include <iostream>
#define MAX 10
using namespace std;

struct Process {
    int PI;
    int BT;
    int RT;
    // int AT;
    int WT;
    int TAT;
};
int n, timeQuantum;
double wt = 0, tat = 0;
Process processes[MAX];

int main() {
    cout << "Enter no. of processes : "; cin >> n;
    cout << "Enter time quantum     : "; cin >> timeQuantum;

    for(int i=0; i<n; i++) {
        processes[i].PI = i + 1;
        // cout << "Enter AT for P" << processes[i].PI << " : "; cin >> processes[i].AT;
        cout << "Enter BT for P" << processes[i].PI << " : "; cin >> processes[i].BT;
        processes[i].RT = processes[i].BT;
        processes[i].WT  = 0;
        processes[i].TAT = 0;
    }
    int currentTime = 0;
    int processesCompleted = 0;

    while(processesCompleted < n) 
    {
        for(int i=0; i<n; i++) {
            if(processes[i].RT > 0) {
                if(processes[i].RT <= timeQuantum) {
                    currentTime += processes[i].RT;
                    processes[i].RT = 0;
                    processesCompleted++;

                    processes[i].WT = currentTime - processes[i].BT;
                    processes[i].TAT = processes[i].WT + processes[i].BT;
                } 
                else {
                    currentTime += timeQuantum;
                    processes[i].RT -= timeQuantum;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        wt += processes[i].WT;
        tat += processes[i].TAT;
    }
    cout << "\nProcess\tBurstTime\tWaitingTime\tTurnAroundTime\n";
    for(int i=0; i<n; i++) {
        cout << "P" << processes[i].PI << "\t" << processes[i].BT << "\t\t" << processes[i].WT << "\t\t" << processes[i].TAT << "\n";
    }
    cout << "\nAverage Waiting Time     : " << wt / n;
    cout << "\nAverage Turn Around Time : " << tat / n << "\n\n";


    return 0;
}