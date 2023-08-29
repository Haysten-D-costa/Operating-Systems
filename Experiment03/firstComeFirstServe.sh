#!/bin/bash

echo -n "Enter no. of processes : "; read n
echo -n "Enter the burst Time for each process : "; read -ra burst_time

for (( i=0; i<n; i++ )); do
    arrival_time[$i]=$i
done

waiting_time[0]=0
for (( i=1; i<n; i++ )); do
    waiting_time[$i]=$(( waiting_time[$i - 1] + burst_time[$i - 1] ))
done

echo -e "\nProcess\t\tBurstTime\tArrivalTime\tWaitingTime\tTurnAroundTime"
for (( i=0; i<n; i++ ))
do
    turn_around_time[$i]=$((waiting_time[$i] + burst_time[$i]))
    echo -e "P$i\t\t${burst_time[$i]}\t\t${arrival_time[$i]}\t\t${waiting_time[$i]}\t\t${turn_around_time[$i]}"
done

sum_w=0
sum_t=0
for (( i=0; i<n; i++ )); do
    sum_w=$(( $sum_w + ${waiting_time[$i]} ))
    sum_t=$(( $sum_t + ${turn_around_time[$i]} ))
done

echo -e "\nAverage waiting time     : $(($sum_w / $n))"
echo -e "Average turn around time : $(($sum_t / $n))"

echo -en "\n\nGantt Chart : ---------------------------------------------------------------------------\n\t|\t"
for (( i=0; i<n; i++ )); do
    echo -en "P$i \t|\t"
done
echo -en "\n\t---------------------------------------------------------------------------------\n"
echo -en "\t${arrival_time[0]}"
for (( i=0; i<n; i++ )); do
    echo -en "\t\t${turn_around_time[$i]}"
done
echo