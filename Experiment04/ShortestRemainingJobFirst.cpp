#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10

struct Process {
    std::string name;
    int arrival_time;
    int burst_time;
    bool arrived;
    bool executed;
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
void cAlign(std::string lT, std::string text, int width) {
    int left = (width - text.length())/2;
    int right = width - (left + text.length());
    std::cout << lT;
    std::cout.width(left + text.length());
    std::cout.fill(' ');
    std::cout << text;
    std::cout.width(right);
    std::cout << "";
}
void printGanttChart(int fp, std::vector <std::pair<std::string, int>> GanttChart, std::vector <Process> P) {
    std::cout << std::endl << std::endl << "Gantt Chart : " << std::endl;
    for(int i{}; i<GanttChart.size(); i++) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl << "| ";
    for(int i{}; i<GanttChart.size(); i++) {
        std::cout << GanttChart[i].first << " | ";
    }

    std::cout << std::endl;
    for(int i{}; i<GanttChart.size(); i++) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;

    std::cout << fp;
    for(int i{}; i<GanttChart.size(); i++) {
        if(GanttChart[i].second < 10) std::cout << "    " << GanttChart[i].second;
        else std::cout << "   " << GanttChart[i].second;
    }
    std::cout << std::endl;
    // displayDetails(GanttChart, P);
}
void displayDetails(int fp, std::vector <std::pair<std::string, int>> GanttChart, std::vector <Process> P) {
    float avgWT = 0;
    float avgTT = 0;
    int waiting_time[MAX] = {0};
    int completion_time[MAX] = {0};
    int turn_around_time[MAX] = {0};

    for(int i{1}; i<=P.size(); i++) { // computation of completion_time for each process....
        completion_time[i-1] = findLastOccurrenceOf(GanttChart, i);
    }
    for(int i{0}; i<P.size(); i++) {
        waiting_time[i] = completion_time[i] - P[i].burst_time - P[i].arrival_time;
        turn_around_time[i] = waiting_time[i] + P[i].burst_time;
        avgWT += waiting_time[i];
        avgTT += turn_around_time[i]; 
    }
    std::vector <std::string> v = {"Process", "WaitingTime", "ArrivalTime", "BurstTime", "TurnAroundTime"};
    for(int i{}; i<v.size(); i++) {
        std::cout << "+";
        for(int j{}; j<v[i].length()+6; j++) {
            std::cout << "-";
        }
    } std::cout << "+" << std::endl;

    for(int i{}; i<v.size(); i++) {
        std::cout << "|   " << v[i] << "   ";
    }
    std::cout << "|" << std::endl;
    
    for(int i{}; i<v.size(); i++) {
        std::cout << "+";
        for(int j{}; j<v[i].length()+6; j++) {
            std::cout << "-";
        }
    } std::cout << "+" << std::endl;
    
    for(int i{}; i<P.size(); i++) {

        cAlign("|", P[i].name, v[0].length()+6);
        cAlign("|", std::to_string(waiting_time[i]), v[1].length()+6);
        cAlign("|", std::to_string(P[i].arrival_time), v[2].length()+6);
        cAlign("|", std::to_string(P[i].burst_time), v[3].length()+6);
        cAlign("|", std::to_string(turn_around_time[i]), v[4].length()+6); 
        std::cout << "|" << std::endl;
    }
    for(int i{}; i<v.size(); i++) {
        std::cout << "+";
        for(int j{}; j<v[i].length()+6; j++) {
            std::cout << "-";
        }
    } std::cout << "+" << std::endl;
    std::cout << "-> Average turn around time : " << avgTT/P.size() << std::endl
              << "-> Average waiting time     : " << avgWT/P.size();

    printGanttChart(fp, GanttChart, P);
}

void showq(std::queue<Process> gq) {
	std::queue<Process> g = gq;
	while (!g.empty()) {
        std::cout << "\n----------------------"; 
		std::cout << "\nName : " << g.front().name << "\nArrived : " << g.front().arrived << "\nBT : " << g.front().burst_time << "\nExecuted : " << g.front().executed;
        std::cout << "\n----------------------";
		g.pop();
	}
	std::cout << '\n';
}
bool cmpBT(const Process& a, const Process& b) {
    return a.burst_time < b.burst_time;
}
void sortProcesses(std::vector <Process>& processes) {
    std::sort(processes.begin(), processes.end(), cmpBT);
}
void sortQueue(std::queue <Process>& Q) {
    std::vector <Process> temp;
    while(!Q.empty()) {
        temp.push_back(Q.front());
        Q.pop();
    }
    sortProcesses(temp);

    for(const Process& p : temp) {
        Q.push(p);
    }
}
void checkArrivedProcesses(int time, std::vector <Process>& processes, std::queue <Process>& Q) {

    for(int i{}; i<processes.size(); i++) {
        if((processes[i].arrived == 0) && (processes[i].arrival_time <= time) && (processes[i].executed == 0)) { 
            processes[i].arrived = true;
            Q.push(processes[i]); 
        }
    }
}
void shortestRemainingJobFirst(std::vector <Process>& processes) {
    
    int fp = 999;
    int time = 0;
    std::queue <Process> Q;
    std::vector <std::pair<std::string, int>> GanttChart;

    do {
        checkArrivedProcesses(time, processes, Q);
        sortQueue(Q);
        // showq(Q); /* to display which is next process for execution...

        if(fp == 999) { fp = Q.front().arrival_time; }
        Q.front().burst_time--;
        time++;
        GanttChart.push_back(std::make_pair(Q.front().name, time));

        if(Q.front().burst_time == 0) {
            Q.front().executed = true;
            Q.pop();
        }
    } while(!Q.empty());
    displayDetails(fp, GanttChart, processes);
}

int main() {

    int n;
    // std::cout << "Enter the no. of processes : "; std::cin >> n;
    std::vector <Process> processes {
        {"P1", 3, 5, false, false},
        {"P2", 1, 2, false, false},
        {"P3", 2, 1, false, false},
        {"P4", 0, 4, false, false},
        {"P5", 2, 3, false, false}
    };
    // for(int i{}; i<n; i++) {
    //     std::cout << "Process P" << i+1 << " : " << std::endl;
    //     std::cout << "-> Arrival Time : "; std::cin >> processes[i].arrival_time;
    //     std::cout << "-> Burst Time   : "; std::cin >> processes[i].burst_time;
    //     processes[i].name = "P"+std::to_string(i+1);
    // }
    shortestRemainingJobFirst(processes);
    return 0;
}
/*
    *(line 68) std::cout << "Executing " << Q.front().name << " at time " << time << " and RemTime : " << Q.front().burst_time << std::endl;
    *(line 71) std::cout << "Now, remTime : " << Q.front().burst_time << " and time : " << time << std::endl;
    *(line 77) std::cout << "Done with " << Q.front().name << std::endl;
*/