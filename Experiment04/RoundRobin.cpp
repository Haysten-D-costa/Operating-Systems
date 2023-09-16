#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

struct Process {
    string name; // process identifier....
    int burst_time;
    int arrival_time;
    bool visited; // to keep track whether process considered for execution or not....
};
void checkNextProcess(int n, int time, queue <Process> &readyQueue, vector <Process> &processes, int time_quantum) { // Function checks and adds next process to the readyQueue, for execution....
        int pc = 0; // pc - process counter....
        checkNext: 
        while((processes[pc].arrival_time <= time) && (pc < n) && (!processes[pc].visited)) // if arrival_time of process is less than the time, and not already added to the readyQueue, enter the loop....
        {
            readyQueue.push(processes[pc]); // add process to the readyQueue....
            processes[pc].visited = true; // set the process as visited....
            pc++; // increment the process counter....
        }
        pc++; if(pc < n) { goto checkNext; }
    }
void roundRobinScheduling(vector <Process> &processes, int time_quantum) {

    int time = 0; // main CPU timer....
    int n = processes.size();
    queue <Process> readyQueue; // readyQueue - DS used to hold the processes that are ready to execute....

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
            if(flag) { exit(1); }
        } 
        else {

            Process current_process = readyQueue.front();
            readyQueue.pop(); // pop element from readyQueue for execution....

            int execution_time = min(time_quantum, current_process.burst_time);
            current_process.burst_time -= execution_time;
            time += execution_time;

            cout << "-> " << time << " :: " << current_process.name << "" << endl;

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

    vector <Process> processes = {
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