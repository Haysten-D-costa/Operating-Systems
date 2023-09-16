#include <iostream>
#include <queue>

#define MAX 10
using namespace std;

queue <int> PO;

int maxAT(int n, double at[]) {
    int max = at[0];
    for(int i{}; i<n; i++) {
        if(at[i] > max) { max = at[i]; }
    }
    return max;
}
void sortProcessesForExecution(double arrival_time[], double burst_time[], int processOrder[], int n) {
    // Bubble sort the processes based on arrival time (arrival_time[])....
    for(int i{1}; i<=n; i++) {
        for(int j{1}; j<=n-i; j++) {
            if(arrival_time[j] > arrival_time[j+1]) {
                // Swap arrival time (arrival_time), burst time (burst_time), and process number (processOrder)....
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j+1];
                arrival_time[j+1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;

                temp = processOrder[j];
                processOrder[j] = processOrder[j+1];
                processOrder[j+1] = temp;
            }
            else if(arrival_time[j] == arrival_time[j+1]) {
                if(burst_time[j] > burst_time[j+1]) {
                    int temp = arrival_time[j];
                    arrival_time[j] = arrival_time[j+1];
                    arrival_time[j+1] = temp;

                    temp = burst_time[j];
                    burst_time[j] = burst_time[j+1];
                    burst_time[j+1] = temp;

                    temp = processOrder[j];
                    processOrder[j] = processOrder[j+1];
                    processOrder[j+1] = temp;
                }
            }
        }
    }
}
void SJF_A(int n, double bt[], double at[]) {
    
    int processOrder[MAX];
    int timer = 0;
    int i = 0;

    while(true) {
        if(timer == at[i]) {
            PO.push(i);
        }  
    }

}

int main() {
    int n;
    double burst_time[MAX] = {0};
    double arrival_time[MAX] = {0};
    
    std::cout << "Enter the no. of processes : "; 
    std::cin >> n;
    std::cout << "Enter the arrival and burst times for each process : " << std::endl;
    for(int i{}; i<n; i++) {
        std::cout << "Process " << i << std::endl;
        std::cout << "-> Arrival Time : "; std::cin >> arrival_time[i];
        std::cout << "-> Burst Time   : "; std::cin >> burst_time[i];
        std::cout << std::endl;
    }
    SJF_A(n, burst_time, arrival_time);
}