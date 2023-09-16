#include <iostream>
#include <vector>
#include <queue>
#define MAX 20

struct Process { // Process Structure....
    std::string name; // process idf....
    int burst_time;
    int arrival_time;
    bool visited; // to keep track whether process considered for execution or not....
};
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
void printGanttChart(std::vector <std::pair<std::string, int>> GanttChart, std::vector <Process> processes, int fp) {
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
    for(int i{0}; i<GanttChart.size(); i++) {
        if(GanttChart[i].second < 10) std::cout << "    " << GanttChart[i].second;
        else std::cout << "   " << GanttChart[i].second;
    }
    std::cout << std::endl;
}
void checkNextProcess(int n, int time, std::queue <Process> &readyQueue, std::vector <Process> &processes, int time_quantum) { // Function checks and adds next process to the readyQueue, for execution....
    int pc = 0; // pc - process counter....
    checkNext: 
    while((processes[pc].arrival_time <= time) && (pc < n) && (!processes[pc].visited)) // if arrival_time of process is less than the time, and not already added to the readyQueue, enter the loop....
    {
        readyQueue.push(processes[pc]); // add process to the readyQueue....
        processes[pc].visited = true;   // set the process as visited....
        pc++; // increment the process counter....
    }
    pc++; if(pc < n) { goto checkNext; }
}
void roundRobinScheduling(std::vector <Process> &processes, int time_quantum) {

    int time = 0; // main CPU timer....
    int n = processes.size();
    int fp; // first process that begins with execution....
    std::queue <Process> readyQueue; // readyQueue - DS used to hold the processes that are ready to execute....
    std::vector <std::pair<std::string, int>> GanttChart; // GanttChart - stores the sequence of processes(execution)....
    
    while(!readyQueue.empty() || !processes.empty()) // while processes available, and waiting to execute(not in readyQueue)....
    { 
        checkNextProcess(n, time, readyQueue, processes, time_quantum); // check arrived processes and add to readyQueue....
        if(readyQueue.empty() ) { // If readyQueue == empty, we can exit....
            bool flag = false;
            time++;
            for(int i=0; i<n; i++) {
                if(processes[i].visited) { flag = true; }   // (flag == true)  => all processes considered for execution....
                if(!processes[i].visited) { flag = false; } // (flag == false) => processes left to be considered for execution....
            }
            if(flag) { 
                printGanttChart(GanttChart, processes, fp); // display the ganttChart....
                exit(1); //! EXIT PROGRAM !!
            }
        } 
        else {
            static int first = 0;
            Process current_process = readyQueue.front();
            readyQueue.pop(); // pop element from readyQueue for execution....

            int execution_time = std::min(time_quantum, current_process.burst_time);
            current_process.burst_time -= execution_time;
            time += execution_time;

            if(first == 0) { fp = current_process.arrival_time; first++; } // to store the first process that enters....
            GanttChart.push_back(std::make_pair(current_process.name, time)); // create a gantt chart....

            if(current_process.burst_time > 0) { // if the current_process is remaining to execute (not completed),  
                checkNextProcess(n, time, readyQueue, processes, time_quantum); // first check which processes arrive at the current time....
                readyQueue.push(current_process); // then push the current process again to the readyQueue....
            }
            else {
                int waiting_time = time - current_process.arrival_time;
                int avg_waiting_time;
                avg_waiting_time += waiting_time;
            }
        }
    }
}
int main() {

    std::vector <Process> processes = {
        /*
        {"P1", 5, 3, false}, // works with correct output....
        {"P2", 2, 1, false},
        {"P3", 3, 2, false},
        {"P4", 6, 0, false},
        {"P5", 8, 2, false} 
        */
        {"P1", 12, 0, false}, // works with correct output....
        {"P2", 3, 1, false},
        {"P3", 5, 2, false}    
    };
    int time_quantum = 2;
    roundRobinScheduling(processes, time_quantum);
    return 0;
}