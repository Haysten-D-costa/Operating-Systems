#include <iostream>
#define MAX 10
using namespace std;

int n;
double wt = 0, tat = 0;
int processExeOrder[MAX];
double BT[MAX]{0}, AT[MAX]{0}, WT[MAX]{0}, TAT[MAX]{0};

void sort() {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
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
    for(int i=0; i<n; i++) 
    {
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

    cout << "Enter no. of processes : ";
    cin >> n;

    for(int i=0; i<n; i++) {
        processExeOrder[i] = i;
        cout << "Enter BT for P" << i << " : ";
        cin >> BT[i];
        cout << "Enter AT for P" << i << " : ";
        cin >> AT[i];
    }
    fcfs_a();
    cout << "\nProcess\tBurstTime\tArrivalTime\tWaitingTime\tTurnAroundTime\n";
    for(int i=0; i<n; i++) {
        cout << "P" << processExeOrder[i] << "\t" << AT[i] << "\t\t" << BT[i] << "\t\t" << WT[i] << "\t\t" << TAT[i] << "\n";
    }
    cout << "\nAverage Waiting Time     : " << wt / n;
    cout << "\nAverage Turn Around Time : " << tat / n << "\n\n";
    return 0;
}