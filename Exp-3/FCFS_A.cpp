#include <iostream>
#define MAX 10
using namespace std;

int n;
double wt = 0, tat = 0;
int processExeOrder[MAX]{0};
double AT[MAX]{0}, BT[MAX]{0}, WT[MAX]{0}, TAT[MAX]{0};

void sort() {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(AT[j] > AT[j+1])
            {
                int temp = AT[j];
                AT[j] = AT[j+1];
                AT[j+1] = temp;

                temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;

                temp = processExeOrder[j];
                processExeOrder[j] = processExeOrder[j+1];
                processExeOrder[j+1] = temp;
            }
        }
    }
}

void fcfs_a() {
    sort();
    int currentTime = 0;

    for(int i=0; i<n; i++) {
        if(AT[i] > currentTime) {
            currentTime = AT[i];
        }
        WT[i] = currentTime - AT[i];
        TAT[i] = WT[i] + BT[i];
        currentTime += BT[i];

        wt += WT[i];
        tat += TAT[i];
    }
}

int main() {

    cout << "\nEnter no. of processes : "; cin >> n;
    for(int i=0; i<n; i++) {
        processExeOrder[i] = i + 1;
        cout << "\nProcess P" << processExeOrder[i] << " : \n";
        cout << "AT : "; cin >> AT[i];
        cout << "BT : "; cin >> BT[i];
    }
    fcfs_a();
    cout << "\nProcesses\tBurstTime\tArrivalTime\tWaitingTime\tTurnAroundTime\n";
    for(int i=0; i<n; i++) {
        cout << processExeOrder[i] << "\t\t" << BT[i] << "\t\t" << AT[i] << "\t\t" << WT[i] << "\t\t" << TAT[i] << "\n";
    }
    cout << "\nAverage Waiting Time     : " << wt / n;
    cout << "\nAverage Turn Around Time : " << tat / n;

    return 0;
}