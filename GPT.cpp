#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define a structure for processes
struct Process {
    string name;
    int burst_time;
    int arrival_time;
};

// Function to perform Round Robin scheduling with arrival times
void roundRobinWithArrivalTime(vector<Process>& processes, int quantum) {
    int n = processes.size();
    queue<Process> ready_queue;
    int time = 0;
    int total_waiting_time = 0;

    cout << "Gantt Chart:" << endl;
    cout << "-------------" << endl;
    cout << "|  Time  | Process" << endl;
    cout << "-------------" << endl;

    while (!ready_queue.empty() || !processes.empty()) {
        // Enqueue processes that have arrived
        while (!processes.empty() && processes.front().arrival_time <= time) {
            ready_queue.push(processes.front());
            processes.erase(processes.begin());
        }

        if (ready_queue.empty()) {
            time++;
        } else {
            Process current_process = ready_queue.front();
            ready_queue.pop();

            // Execute the process for the quantum time or its remaining time
            int execution_time = min(quantum, current_process.burst_time);
            current_process.burst_time -= execution_time;
            time += execution_time;

            cout << "|   " << time << "   |   " << current_process.name << endl;

            if (current_process.burst_time > 0) {
                ready_queue.push(current_process);
            } else {
                int waiting_time = time - current_process.arrival_time;
                total_waiting_time += waiting_time;
            }
        }
    }

    // Calculate and print the average waiting time
    double avg_waiting_time = static_cast<double>(total_waiting_time) / n;
    cout << "-------------" << endl;
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
}

int main() {
    vector<Process> processes = {
        {"P1", 5, 3},
        {"P2", 2, 1},
        {"P3", 3, 2},
        {"P4", 6, 0},
        {"P5", 2, 8}
    };
    int quantum = 1;

    roundRobinWithArrivalTime(processes, quantum);

    return 0;
}

