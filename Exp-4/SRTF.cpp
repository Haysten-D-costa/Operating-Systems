#include <iostream>
#define MAX 10
using namespace std;

struct Process {
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
        cout << "AT : ";  cin >> processes[i].AT;
        cout << "BT : ";  cin >> processes[i].BT;
        processes[i].RT = processes[i].BT;
    }
    int currentTime = 0;
    int completedProcesses = 0;
    
    while(completedProcesses < n) {
        int shortestRT = 9999;
        int shortestRTProcess = -1;

        for(int i=0; i<n; i++) {
            if(processes[i].AT <= currentTime && processes[i].RT < shortestRT && processes[i].RT > 0) {
                shortestRT = processes[i].RT;
                shortestRTProcess = i;
            }
        }
        if(shortestRTProcess == -1) {
            currentTime++;
        }
        else {
            processes[shortestRTProcess].RT--;
            currentTime++;

            if(processes[shortestRTProcess].RT == 0) {
                completedProcesses++;
                processes[shortestRTProcess].WT = currentTime - processes[shortestRTProcess].BT - processes[shortestRTProcess].AT;
                processes[shortestRTProcess].TAT = processes[shortestRTProcess].BT + processes[shortestRTProcess].WT;
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