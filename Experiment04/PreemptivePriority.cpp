#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../grid_format.h"
#define MAX 10

struct Process {
    std::string name;
    double arrival_time;
    double burst_time;
    int priority;
    bool arrived;
};
int findLastOccurrenceOf(std::vector <std::pair<std::string, double>> GanttChart, int key) {
    int value;
    for(int i=GanttChart.size(); i>=0; i--) {
        if(GanttChart[i].first == "P"+std::to_string(key)) {
            value = GanttChart[i].second;
            return value; 
        }
    }
}
void computeDetails(int fp, std::vector <std::pair<std::string, double>> GanttChart, std::vector <Process> P) {
    float avgWT = 0;
    float avgTT = 0;
    int priority[MAX] = {0};
    double burst_time[MAX] = {0};
    double arrival_time[MAX] = {0};
    double waiting_time[MAX] = {0};
    double completion_time[MAX] = {0};
    double turn_around_time[MAX] = {0};

    for(int i{1}; i<=P.size(); i++) { // computation of completion_time for each process....
        completion_time[i-1] = findLastOccurrenceOf(GanttChart, i);
    }
    for(int i{0}; i<P.size(); i++) {
        priority[i] = P[i].priority;
        burst_time[i] = P[i].burst_time; // creating a burst_time array....
        arrival_time[i] = P[i].arrival_time; // creating a arrival_time array(for grid/table display purpose)....
        waiting_time[i] = completion_time[i] - P[i].burst_time - P[i].arrival_time;
        turn_around_time[i] = waiting_time[i] + P[i].burst_time;
        avgWT += waiting_time[i];
        avgTT += turn_around_time[i]; 
    }
    std::vector <std::string> v = {"Process", "WaitingTime", "ArrivalTime", "BurstTime", "TurnAroundTime", "Priority"};
    
    grid::printDetailsTable(P.size(), v, arrival_time, burst_time, waiting_time, turn_around_time, priority);
    std::cout << "-> Average waiting time     : " << avgWT/P.size()<< std::endl
              << "-> Average turn around time : " << avgTT/P.size();

    grid::printGanttChart(fp, GanttChart);
}
bool cmpBT(const Process& a, const Process& b) { // to sort based on the priorities of the processes....
    return a.priority < b.priority;
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
void checkArrivedProcesses(double time, std::vector <Process>& processes, std::queue <Process>& Q) {
    for(int i{}; i<processes.size(); i++) {
        if((!processes[i].arrived) && (processes[i].arrival_time <= time)) { 
            processes[i].arrived = true;
            Q.push(processes[i]); 
        }
    }
}
// double findMinT(std::vector <Process> P) {
//     double min = P[0].burst_time;
//     for(Process p : P) {
//         if(p.burst_time < min) { min = p.burst_time; }
//     }
//     return min;
// }
void preemptivePriority(std::vector <Process>& processes) {
    int fp = 100;
    int count = 0;
    double time = 0;
    std::queue <Process> Q;
    std::vector <std::pair<std::string, double>> GanttChart;
    do {
        checkArrivedProcesses(time, processes, Q);
        sortQueue(Q);

        // double min_time = findMinT(processes);
        if(fp == 100) { fp = Q.front().arrival_time; }
        Q.front().burst_time --;
        time ++;
        GanttChart.push_back(std::make_pair(Q.front().name, time));

        /* 
        ! This is just to compress the GanttChart, logic correct, but it doesnt work....
        if(GanttChart.back().first == Q.front().name) { GanttChart.back().second += min_time; } 
        else { GanttChart.push_back(std::make_pair(Q.front().name, time)); }
        */ 

        if(Q.front().burst_time == 0) { Q.pop(); }

    } while(!Q.empty());
    computeDetails(fp, GanttChart, processes);
}
int main() {

    int n;
    bool useAT = false;
    // std::cout << "Enter the no. of processes : "; std::cin >> n;
    // std::cout << "Enter arrival times for each process > [1-Yes / 0-No] "; std::cin >> useAT;
    // std::vector <Process> processes(n);
    std::vector <Process> processes {
        {"P1", 0, 10, 3, false}, //? works with int not with double values....
        {"P2", 1, 1, 1, false},
        {"P3", 2, 2, 1, false},
        {"P4", 3, 1, 2, false}
    };
    
    // for(int i{}; i<n; i++) {
    //     std::cout << "Process P" << (i+1) << std::endl;
    //     if(useAT) { std::cout << "-> Arrival Time : "; std::cin >> processes[i].arrival_time; }
    //     else { processes[i].arrival_time = 0; }
    //     std::cout << "  -> Burst Time   : "; std::cin >> processes[i].burst_time;
    //     std::cout << "  -> Priority     : "; std::cin >> processes[i].priority;
    //     processes[i].name = "P"+std::to_string(i+1);
    //     processes[i].arrived = false;
    // }
    preemptivePriority(processes);
    return 0;
}
/*
    {"P1", 0, 10, 3, false}, //? works with int not with double values....
    {"P2", 1, 1, 1, false},
    {"P3", 2, 2, 1, false},
    {"P4", 3, 1, 2, false}
*/