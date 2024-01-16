#include <iostream>
#define MAX 10
using namespace std;

struct Process {
    int ID;
    int BT;
    int RT;
    int WT;
    int TAT;
};

int n, timeQuantum;
double wt = 0, tat = 0;
Process processes[MAX];

int main() {

    cout << "\nEnter no. of processes : "; cin >> n;
    cout << "Enter time quantum     : "; cin >> timeQuantum;
    for(int i=0; i<n; i++) {
        processes[i].ID = i + 1;
        cout << "\nProcess P" << processes[i].ID << " : \n";
        cout << "BT : "; cin >> processes[i].BT;
        processes[i].RT = processes[i].BT;
    }
    int currentTime = 0;
    int completedProcesses = 0;
    
    while(completedProcesses < n) 
    {
        for(int i=0; i<n; i++) {
            if(processes[i].RT > 0) {
                if(processes[i].RT <= timeQuantum) {
                    currentTime += processes[i].RT;
                    processes[i].RT = 0;
                    completedProcesses++;

                    processes[i].WT = currentTime - processes[i].BT; 
                    processes[i].TAT = processes[i].WT + processes[i].BT;
                }
                else {
                    processes[i].RT -= timeQuantum;
                    currentTime += timeQuantum;
                }
            }
        }
    }

    cout << "\nProcesses\tBurstTime\tWaitingTime\tTurnAroundTime\n";
    for(int i=0; i<n; i++) {
        wt += processes[i].WT;
        tat += processes[i].TAT;
        cout << processes[i].ID << "\t\t" << processes[i].BT << "\t\t" << processes[i].WT << "\t\t" << processes[i].TAT << "\n";
    }
    cout << "\nAverage Waiting Time     : " << wt / n;
    cout << "\nAverage Turn Around Time : " << tat / n;

    return 0;
}