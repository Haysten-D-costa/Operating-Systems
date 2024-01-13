#include <iostream>
#define MAX 10
using namespace std;

int n;
double wt = 0, tat = 0;
int processExeOrder[MAX]{0};
double BT[MAX]{0}, WT[MAX]{0}, TAT[MAX]{0};

void sort() {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if(BT[j] > BT[j+1])
            {
                int temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;

                temp = processExeOrder[j];
                processExeOrder[j] = processExeOrder[j+1];
                processExeOrder[j+1] = temp;
            }
        }
    }
}
void sjf() {
    sort();
    WT[0] = 0;
    for (int i = 1; i < n; i++) {
        WT[i] = WT[i-1] + BT[i-1];
    }
    for(int i=0; i<n; i++) {
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
        processExeOrder[i] = i;
        cin >> BT[i];
    }
    sjf();
    cout << "\nProcess\tBurstTime\tWaitingTime\tTurnAroundTime\n";
    for(int i=0; i<n; i++) {
        cout << "P" << processExeOrder[i] << "\t" << BT[i] << "\t\t" << WT[i] << "\t\t" << TAT[i] << "\n";
    }
    cout << "\nAverage Waiting Time     : " << wt / n;
    cout << "\nAverage Turn Around Time : " << tat / n << "\n\n";
    
    return 0;
}