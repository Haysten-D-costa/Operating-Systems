#include <iostream>
#define MAX 10
using namespace std;

struct Process {
    int P;
    int ID;
    int BT;
    int RT;
    int AT;
    int WT;
    int TAT;
};

int n;
double wt = 0, tat = 0;
Process processes[MAX];

int main() {

    cout << "\nEnter no. of processes : "; cin >> n;
    for(int i=0; i<n; i++) {
        processes[i].ID = i + 1;
        cout << "\nProcess P" << processes[i].ID << " : \n";
        cout << "BT : ";  cin >> processes[i].BT;
        cout << "AT : ";  cin >> processes[i].AT;
        cout << "P  : ";  cin >> processes[i].P;
        processes[i].RT = processes[i].BT;
        processes[i].WT = 0;
        processes[i].TAT = 0;
    }
    int currentTime = 0;
    int completedProcesses = 0;

    while(completedProcesses < n) 
    {
        int highestPriority = 9999;
        int highestPriorityProcess = -1;

        for(int i=0; i<n; i++) {
            if((processes[i].AT <= currentTime) && (processes[i].P < highestPriority) && (processes[i].RT > 0)) {
                highestPriority = processes[i].P;
                highestPriorityProcess = i;
            }
        }
        if(highestPriorityProcess == -1) {
            currentTime++;
        }
        else {
            processes[highestPriorityProcess].RT--;
            currentTime++;

            if (processes[highestPriorityProcess].RT == 0) {
                processes[highestPriorityProcess].WT = currentTime - processes[highestPriorityProcess].BT - processes[highestPriorityProcess].AT;
                processes[highestPriorityProcess].TAT = processes[highestPriorityProcess].WT + processes[highestPriorityProcess].BT;
                completedProcesses++;
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