#include <iostream>

void computeWaitingTime(int n, int burst_time[], int arrival_time[], int waiting_time[], int turn_around_time[]) {
    
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

    std::cout << std::endl << "\t------------------------------------------------------------" << std::endl << "\t|\t";
    for(int i=0; i<n; i++) {
        std::cout << "P" << i << "\t|\t";
    }
    std::cout << std::endl << "\t------------------------------------------------------------" << std::endl;
    std::cout << "\t" << arrival_time[0];
    for(int i=0; i<n; i++) {
        std::cout << "\t\t" << turn_around_time[i];
    }
}

int main() {

    int n = {};
    std::cout << "Enter the no. of processes : ";
    std::cin >> n;

    int burst_time[n];
    int arrival_time[n];
    int waiting_time[n];
    int turn_around_time[n];

    std::cout << "Enter the burst time for each process : ";
    for(int i{}; i<n; i++) {
        std::cin >> burst_time[i];
        arrival_time[i] = i;
    }
    computeWaitingTime(n, burst_time, arrival_time, waiting_time, turn_around_time);
    return 0;
}