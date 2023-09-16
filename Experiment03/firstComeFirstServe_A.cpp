#include <iostream>
#include <iomanip>
#include <vector>
#define MAX 10

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
// Function to sort processes based on arrival time and update other arrays accordingly....
void sortProcessesForExecution(double arrival_time[], double burst_time[], int processOrder[], int n) {
    // Bubble sort the processes based on arrival time (arrival_time[])....
    for(int i{1}; i<=n; i++) {
        for(int j{1}; j<=n-i; j++) {
            if(arrival_time[j] > arrival_time[j+1]) {
                // Swap arrival time (arrival_time), burst time (burst_time), and process number (processOrder)....
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j+1];
                arrival_time[j+1] = temp;

                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;

                temp = processOrder[j];
                processOrder[j] = processOrder[j+1];
                processOrder[j+1] = temp;
            }
            else if(arrival_time[j] == arrival_time[j+1]) {
                if(burst_time[j] > burst_time[j+1]) {
                    int temp = arrival_time[j];
                    arrival_time[j] = arrival_time[j+1];
                    arrival_time[j+1] = temp;

                    temp = burst_time[j];
                    burst_time[j] = burst_time[j+1];
                    burst_time[j+1] = temp;

                    temp = processOrder[j];
                    processOrder[j] = processOrder[j+1];
                    processOrder[j+1] = temp;
                }
            }
        }
    }
}
// Function to print the Gantt Chart....
void printGChart(double ganttChart[], int processOrder[], int n) {
    std::cout << std::endl << std::endl << "Gantt Chart : " << std::endl;
    for(int i{1}; i<=n; i++) {
        std::cout << "+----------";
    } 
    std::cout << "+" << std::endl << "|    ";
    for(int i{1}; i<=n; i++) {
        std::cout << "P" << processOrder[i] << "    |    ";
    }

    std::cout << std::endl;
    for(int i{1}; i<=n; i++) {
        std::cout << "+----------";
    } 
    std::cout << "+" << std::endl;

    for(int i{}; i<=n; i++) {
        std::cout << ganttChart[i] << "          ";
    }
    std::cout << std::endl;
}

// Function to perform FCFS scheduling....
void firstComeFirstServe(double burst_time[], double arrival_time[], int n) {

    float avgTT {0};
    float avgWT {0};
    int processOrder[MAX] {0};
    double waiting_time[MAX] {0};
    double ganttChartValue[MAX] {0};
    double completion_time[MAX] {0};
    double turn_around_time[MAX] {0};

    for(int i{1}; i<=n; i++) {  // Initialize process numbers in GChartProc[]....
        processOrder[i] = i;
    }
    sortProcessesForExecution(arrival_time, burst_time, processOrder, n); // Sort processes based on arrival time....

    // Calculate Gantt Chart values (completion times)....
    ganttChartValue[0] = arrival_time[1];
    for(int i{1}; i<=n; i++) { 
        ganttChartValue[i] = ganttChartValue[i-1] + burst_time[i]; 
        completion_time[i] = ganttChartValue[i];
    }

    // Calculate waiting time (WT[]) and turnaround time (TT[]) for each process....
    for(int i{1}; i<=n; i++) {
        waiting_time[i] = completion_time[i] - burst_time[i] - arrival_time[i];
        turn_around_time[i] = waiting_time[i] + burst_time[i];
        avgWT += waiting_time[i];
        avgTT += turn_around_time[i];
    }
    avgWT /= n;
    avgTT /= n;

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
    
    for(int i{1}; i<=n; i++) {

        cAlign("|", "P"+std::to_string(i), v[0].length()+6);
        cAlign("|", std::to_string(waiting_time[i]), v[1].length()+6);
        cAlign("|", std::to_string(arrival_time[i]), v[2].length()+6);
        cAlign("|", std::to_string(burst_time[i]), v[3].length()+6);
        cAlign("|", std::to_string(turn_around_time[i]), v[4].length()+6); 
        std::cout << "|" << std::endl;
    }
    for(int i{}; i<v.size(); i++) {
        std::cout << "+";
        for(int j{}; j<v[i].length()+6; j++) {
            std::cout << "-";
        }
    } std::cout << "+" << std::endl;

    std::cout << std::endl 
              << "Average waiting time     : " << avgWT << std::endl
              << "Average turn around time : " << avgTT;

    // Print the Gantt Chart....
    printGChart(ganttChartValue, processOrder, n);
}

int main()
{
    int n = 5;
    double burst_time[MAX];
    double arrival_time[MAX];

    std::cout << "Enter the number of processes : ";
    std::cin >> n;

    std::cout << "Enter the arrival and burst times for each process : " << std::endl;
    for(int i{1}; i<=n; i++) {
        std::cout << "Process " << i << std::endl;
        std::cout << "-> Arrival Time : "; std::cin >> arrival_time[i];
        std::cout << "-> Burst Time   : "; std::cin >> burst_time[i];
        std::cout << std::endl;
    }
    // Perform FCFS scheduling....
    firstComeFirstServe(burst_time, arrival_time, n);

    return 0;
}
