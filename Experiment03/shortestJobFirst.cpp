#include <iostream>
#define MAX 10

void sortProcessesForExecution(int n, double burst_time[], int processOrder[]) {

    for(int i{1}; i<=n; i++) {
        for(int j{1}; j<=n-i; j++) {
            if(burst_time[j] > burst_time[j+1]) {

                double temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;

                temp = processOrder[j];
                processOrder[j] = processOrder[j+1];
                processOrder[j+1] = temp;
            }
        }
    }
}
void printGChart(double ganttChart[], int processOrder[], int n) {
    std::cout << std::endl << std::endl << "Gantt Chart : " << std::endl;
    for(int i{}; i<n; i++) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl << "| ";
    for(int i{1}; i<=n; i++) {
        std::cout << "P" << processOrder[i] << " | ";
    }

    std::cout << std::endl;
    for(int i{}; i<n; i++) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;

    for(int i{}; i<=n; i++) {
        std::cout << ganttChart[i] << "    ";
    }
    std::cout << std::endl;
}

void shortestJobFirst(int n, double burst_time[]) {

    float avgWT {0};
    float avgTT {0};
    int processOrder[MAX] = {0};
    double waiting_time[MAX] = {0};
    double completion_time[MAX] = {0};
    double turn_around_time[MAX] = {0};
    double ganttChartValues[MAX] = {0};

    for(int i{1}; i<=n; i++) {
        processOrder[i] = i; // setting the order of processes for execution....
    }
    sortProcessesForExecution(n, burst_time, processOrder);

    ganttChartValues[0] = 0;
    for(int i{1}; i<=n; i++) {
        ganttChartValues[i] = ganttChartValues[i-1] + burst_time[i]; // calculating the gantt-chart values....
        completion_time[i] = ganttChartValues[i];
    }

    for(int i{1}; i<=n; i++) {
        waiting_time[i] = completion_time[i] - burst_time[i];
        turn_around_time[i] = waiting_time[i] + burst_time[i];
        avgWT += waiting_time[i];
        avgTT += turn_around_time[i];
    }
    avgWT /= n;
    avgTT /= n;
    std::cout << std::endl << "Process\t\tBurstTime\tWaitingTime\tTurnAroundTime" << std::endl;
    for(int i{1}; i<=n; i++) {
        std::cout << std::endl << "P" << processOrder[i] << "\t\t"
                  << burst_time[i] << "\t\t"
                  << waiting_time[i] << "\t\t"
                  << turn_around_time[i];
    }
    std::cout << std::endl << std::endl << "Average waiting time     : " << avgWT;
    std::cout << std::endl << "Average turn around time : " << avgTT;

    printGChart(ganttChartValues, processOrder, n);
}
int main() {

    int n;
    double burst_time[MAX] = {0};

    std::cout << "Enter the no. of processes : ";
    std::cin >> n;
    std::cout << std::endl << "Enter the Burst Times for each process : " << std::endl;

    for(int i{1}; i<=n; i++) {
            std::cout << "Burst Time for P" << i << " : ";
        std::cin >> burst_time[i];
    }
    shortestJobFirst(n, burst_time);
    return 0;
}
