#include <iostream>
#define MAX 10

void sortProcessesForExecution(int n, double burst_time[], double arrival_time[], int priority[], int processOrder[]) {
    for(int i{1}; i<=n; i++) {
        for(int j{1}; j<=n-i; j++) {
            if(arrival_time[j] > arrival_time[j+1]) 
            {
                int temp = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;

                temp = processOrder[j];
                processOrder[j] = processOrder[j+1];
                processOrder[j+1] = temp;
            }
            else if(arrival_time[j] == arrival_time[j+1]) 
            {
                if(priority[j] > priority[j+1]) {
                    
                    int temp = priority[j];
                    priority[j] = priority[j+1];
                    priority[j+1] = temp;

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

    for(int i{0}; i<=n; i++) {
        if(ganttChart[i] < 10) { std::cout << ganttChart[i] << "    "; }
        else { std::cout << ganttChart[i] << "   "; }
    }
    std::cout << std::endl;
}
void nonPreemptivePriority(int n, double burst_time[], double arrival_time[], int priority[]) {

    float avgWT {0};    
    float avgTT {0};    
    int processOrder[MAX] = {0};
    double waiting_time[MAX] = {0};
    double completion_time[MAX] = {0};
    double turn_around_time[MAX] = {0};
    double ganttChartValues[MAX] = {0};

    for(int i{1}; i<=n; i++) {
        processOrder[i] = i;
    }
    sortProcessesForExecution(n, burst_time, arrival_time, priority, processOrder);

    ganttChartValues[0] = arrival_time[1];
    for(int i{1}; i<=n; i++) {
        ganttChartValues[i] = ganttChartValues[i-1] + burst_time[i];
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
    std::cout << std::endl << "Process\t\tBurstTime\tArrivalTime\tPriority\tWaitingTime\tTurnAroundTime" << std::endl;
    for(int i{1}; i<=n; i++) {
        std::cout << std::endl << "P" << processOrder[i] << "\t\t"
                  << burst_time[i] << "\t\t"
                  << arrival_time[i] << "\t\t"
                  << priority[i] << "\t\t"
                  << waiting_time[i] << "\t\t"
                  << turn_around_time[i];
    }
    std::cout << std::endl << std::endl << "Average waiting time     : " << avgWT;
    std::cout << std::endl << "Average turn around time : " << avgTT;

    printGChart(ganttChartValues, processOrder, n);
}
int main() {

    int n;
    int priority[MAX] = {0};
    double burst_time[MAX] = {0};
    double arrival_time[MAX] = {0};

    std::cout << "Enter the no. of processes : "; 
    std::cin >> n;
    std::cout << "Enter the burst time, arrival time and priorities for each process : " << std::endl;
    for(int i{1}; i<=n; i++) {
        std::cout << "Process " << i << std::endl;
        std::cout << "-> Burst Time   : "; std::cin >> burst_time[i];
        std::cout << "-> Arrival TIme : "; std::cin >> arrival_time[i];
        std::cout << "-> Priority     : "; std::cin >> priority[i];
        std::cout << std::endl;
    }
    nonPreemptivePriority(n, burst_time, arrival_time, priority);
    return 0;
}