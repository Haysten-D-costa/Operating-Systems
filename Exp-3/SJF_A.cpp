#include <iostream>
#define MAX 10
using namespace std;

int n;
double wt = 0, tat = 0;
int processExeOrder[MAX]{0}, completed[MAX]{0};
double AT[MAX]{0}, BT[MAX]{0}, WT[MAX]{0}, TAT[MAX]{0};

void sjf_a() {
    int currentTime = 0;
    int completedProcesses = 0;

    while(completedProcesses < n) {
        int shortestProcess = -1;
        int shortestBurstTime = 9999;
        for(int i=0; i<n; i++) {
            if(AT[i] <= currentTime && !completed[i] && BT[i] < shortestBurstTime) {
                shortestProcess = i;
                shortestBurstTime = BT[i];
            }
        }
        if(shortestProcess == -1) {
            currentTime++;
        }
        else {
            WT[shortestProcess] = currentTime - AT[shortestProcess];
            TAT[shortestProcess] = WT[shortestProcess] + BT[shortestProcess];
            currentTime += BT[shortestProcess];
            completed[shortestProcess] = 1;
            completedProcesses++;
        }
    }
    for(int i=0; i<n; i++) {
        wt += WT[i];
        tat += TAT[i];
    }
}

int main() {

    cout << "\nEnter no. of processes : "; cin >> n;
    for(int i=0; i<n; i++) {
        processExeOrder[i] = i + 1;
        completed[i] = 0;
        cout << "\nProcess P" << processExeOrder[i] << " : \n";
        cout << "BT : "; cin >> BT[i];
        cout << "AT : "; cin >> AT[i];
    }
    sjf_a();
    cout << "\nProcesses\tBurstTime\tArrivalTime\tWaitingTime\tTurnAroundTime\n";
    for(int i=0; i<n; i++) {
        cout << processExeOrder[i] << "\t\t" << BT[i] << "\t\t" << AT[i] << "\t\t" << WT[i] << "\t\t" << TAT[i] << "\n";
    }
    cout << "\nAverage Waiting Time     : " << wt / n;
    cout << "\nAverage Turn Around Time : " << tat / n;

    return 0;
}