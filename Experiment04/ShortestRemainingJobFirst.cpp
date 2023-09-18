#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../grid_format.h"
#define MAX 10

struct Process {
    std::string name;
    int arrival_time;
    int burst_time;
    bool arrived; // to keep track whether process considered or not....
};
int findLastOccurrenceOf(std::vector <std::pair<std::string, int>> GanttChart, int key) {
    int value;
    for(int i=GanttChart.size(); i>=0; i--) {
        if(GanttChart[i].first == "P"+std::to_string(key)) {
            value = GanttChart[i].second;
            return value; 
        }
    }
}
void computeDetails(int fp, std::vector <std::pair<std::string, int>> GanttChart, std::vector <Process> P) {
    float avgWT = 0;
    float avgTT = 0;
    int burst_time[MAX] = {0};
    int arrival_time[MAX] = {0};
    int waiting_time[MAX] = {0};
    int completion_time[MAX] = {0};
    int turn_around_time[MAX] = {0};

    for(int i{1}; i<=P.size(); i++) { // computation of completion_time for each process....
        completion_time[i-1] = findLastOccurrenceOf(GanttChart, i);
    }
    for(int i{0}; i<P.size(); i++) {
        burst_time[i] = P[i].burst_time; // creating a burst_time array....
        arrival_time[i] = P[i].arrival_time; // creating a arrival_time array(for grid/table display purpose)....
        waiting_time[i] = completion_time[i] - P[i].burst_time - P[i].arrival_time;
        turn_around_time[i] = waiting_time[i] + P[i].burst_time;
        avgWT += waiting_time[i];
        avgTT += turn_around_time[i]; 
    }
    std::vector <std::string> v = {"Process", "WaitingTime", "ArrivalTime", "BurstTime", "TurnAroundTime"};
    
    grid::printDetailsTable(P.size(), v, arrival_time, burst_time, waiting_time, turn_around_time);
    std::cout << "-> Average waiting time     : " << avgWT/P.size()<< std::endl
              << "-> Average turn around time : " << avgTT/P.size();

    grid::printGanttChart(fp, GanttChart);
}
bool cmpBT(const Process& a, const Process& b) { // to sort based on the burst time....
    return a.burst_time < b.burst_time;
}
void sortQueue(std::queue <Process>& Q) {
    std::vector <Process> temp;
    while(!Q.empty()) {
        temp.push_back(Q.front());
        Q.pop();
    }
    std::sort(temp.begin(), temp.end(), cmpBT);
    for(const Process& p : temp) {
        Q.push(p);
    }
}
void checkArrivedProcesses(int time, std::vector <Process>& processes, std::queue <Process>& Q) {
    for(int i{}; i<processes.size(); i++) {
        if((!processes[i].arrived) && (processes[i].arrival_time <= time)) { 
            processes[i].arrived = true;
            Q.push(processes[i]); 
        }
    }
}
void shortestRemainingJobFirst(std::vector <Process>& processes) {
    
    int fp = 100;
    int time = 0;
    std::queue <Process> Q;
    std::vector <std::pair<std::string, int>> GanttChart;
    do {
        checkArrivedProcesses(time, processes, Q);
        sortQueue(Q);
        // showq(Q); /* to display which is next process for execution...

        if(fp == 100) { fp = Q.front().arrival_time; }
        Q.front().burst_time --;
        time ++;
        GanttChart.push_back(std::make_pair(Q.front().name, time));
        if(Q.front().burst_time == 0) { Q.pop(); }

    } while(!Q.empty());
    computeDetails(fp, GanttChart, processes);
}

int main() {

    int n;
    bool useAT = false;
    std::cout << "Enter the no. of processes : "; std::cin >> n;
    std::cout << "Enter arrival times for each process > [1-Yes / 0-No] "; std::cin >> useAT;
    std::vector <Process> processes(n);

    for(int i{}; i<n; i++) {
        std::cout << "Process P" << i+1 << " : " << std::endl;
        if(useAT) { std::cout << "-> Arrival Time : "; std::cin >> processes[i].arrival_time; }
        else { processes[i].arrival_time = 0; }
        std::cout << "-> Burst Time   : "; std::cin >> processes[i].burst_time;
        processes[i].name = "P"+std::to_string(i+1);
    }
    shortestRemainingJobFirst(processes);
    return 0;
}
/* 
    ? To check the actual working of the algorithm....
    *   (line 68) std::cout << "Executing " << Q.front().name << " at time " << time << " and RemTime : " << Q.front().burst_time << std::endl;
    *   (line 71) std::cout << "Now, remTime : " << Q.front().burst_time << " and time : " << time << std::endl;
    *   (line 77) std::cout << "Done with " << Q.front().name << std::endl;
    {"P1", 3, 5, false}, //? works for int values....
    {"P2", 1, 2, false}, //? doesn't work perfectly for fp values(since we increment by 1 each time)...
    {"P3", 2, 1, false},
    {"P4", 0, 4, false},
    {"P5", 2, 3, false}
*/