#include <iostream>
#define MAX 10

void printGChart(int n, double burst_time[], double arrival_time[], double waiting_time[], double turn_around_time[]) {

    double ganttChart[MAX] = {0};
    std::cout << std::endl << std::endl << "Gantt Chart : " << std::endl;
    for(int i={}; i<n; i++) {
        std::cout << "+----------";
    } std::cout << "+";

    std::cout << std::endl << "|    ";
    for(int i=0; i<n; i++) {
        std::cout << "P" << i << "    |    ";
    }
    std::cout << std::endl;
    for(int i={}; i<n; i++) {
        std::cout << "+----------";
    } std::cout << "+";
    ganttChart[0] = arrival_time[0];
    for(int i=1; i<=n; i++) ganttChart[i] = ganttChart[i-1] + burst_time[i-1];

    std::cout << std::endl << arrival_time[0] << " ";
    for(int i=0; i<n; i++) {
        std::cout << "         " << ganttChart[i];
    }
}
void firstComeFirstServe(int n, double burst_time[], double arrival_time[], double waiting_time[], double turn_around_time[]) {

    waiting_time[0] = 0;
    for(int i=1; i<n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    std::cout << std::endl << "Process\t\tBurstTime\tArrivalTime\tWaitingTime\tTurnAroundTime" << std::endl;
    for(int i={}; i<n; i++) {
        turn_around_time[i] = waiting_time[i] + burst_time[i]; // computing turn_around_time....
        std::cout << std::endl << "P" << i << "\t\t"
                  << burst_time[i] << "\t\t"
                  << arrival_time[i] << "\t\t"
                  << waiting_time[i] << "\t\t"
                  << turn_around_time[i];
    }
    float sum_w = {};
    float sum_t = {};
    for(int i={}; i<n; i++) {
        sum_w += waiting_time[i];
        sum_t += turn_around_time[i];
    }
    std::cout << std::endl << std::endl << "Average waiting time     : " << (sum_w / n);
    std::cout << std::endl << "Average turn around time : " << (sum_t / n);

    printGChart(n, burst_time, arrival_time, waiting_time, turn_around_time);
}

int main() {

    int n = {};
    std::cout << "Enter the no. of processes : ";
    std::cin >> n;

    double burst_time[MAX];
    double arrival_time[MAX];
    double waiting_time[MAX];
    double turn_around_time[MAX];

    std::cout << "Enter the burst time for each process : ";
    for(int i{}; i<n; i++) {
        std::cin >> burst_time[i];
        arrival_time[i] = i;
    }
    firstComeFirstServe(n, burst_time, arrival_time, waiting_time, turn_around_time);
    return 0;
}