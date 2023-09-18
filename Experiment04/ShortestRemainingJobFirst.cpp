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
    // for(Process p : processes) {
    //     std::cout << "\n----------------------"; 
	// 	std::cout << "\nName : " << p.name << "\nArrived : " << p.arrived << "\nBT : " << p.burst_time << "\nExecuted : " << p.executed;
    //     std::cout << "\n----------------------";
    // }
}
void shortestRemainingJobFirst(std::vector <Process>& processes) {
    
    int time = 0;
    std::queue <Process> Q;

    do {
        checkArrivedProcesses(time, processes, Q);
        sortQueue(Q);
        showq(Q);


        std::cout << "Executing " << Q.front().name << " at time " << time << " and RemTime : " << Q.front().burst_time << std::endl;
        Q.front().burst_time--;
        time++;
        std::cout << "Now, remTime : " << Q.front().burst_time << " and time : " << time << std::endl;


        system("pause");
        if(Q.front().burst_time == 0) {
            std::cout << "Done with " << Q.front().name << std::endl;
            Q.front().executed = true;
            Q.pop();
            system("pause");
        }
    } while(!Q.empty());
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