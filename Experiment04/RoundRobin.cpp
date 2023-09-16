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
    int fp = 0; // first process that begins with execution....
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
                // printGanttChart(fp, GanttChart, processes); // display the ganttChart....
                displayDetails(fp, GanttChart, processes);
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
        }
    }
}
int main() {

    int n; // no. of processes....
    int time_quantum; // time slice for each process....
    std::cout << "Enter the no. of processes : "; std::cin >> n;
    std::vector <Process> processes(n);

    for(int i{}; i<n; i++) {
        std::cout << "Process P" << i+1 << " : " << std::endl;
        std::cout << "-> Arrival Time : "; std::cin >> processes[i].arrival_time;
        std::cout << "-> Burst Time   : "; std::cin >> processes[i].burst_time;
        processes[i].name = "P"+std::to_string(i+1);
        processes[i].visited = false;
    }
    std::cout << std::endl << "Enter the time quantum : "; std::cin >> time_quantum;
    roundRobinScheduling(processes, time_quantum);
    return 0;
}