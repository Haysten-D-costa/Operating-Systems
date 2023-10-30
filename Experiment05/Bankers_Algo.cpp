#include<iostream>
using namespace std;

int m, n;
int MAX[10][10], ALLOC[10][10], NEED[10][10], AVAI[10];
int isLess(int proc, int WORK[])
{
    for(int i = 0; i < m; i++)
        if(NEED[proc][i] > WORK[i])
            return 0;
    return 1;
}
int isLessVector(int a[], int b[], int n)
{
    for(int i = 0; i < n; i++)
        if(a[i] > b[i])
            return 0;
    return 1;
}
int visited(int finish[])
{
    int i;
    for(i = 0; i < n; i++)
        if(finish[i] == 0)
            break;
    if(i == n)
        return 1;
    return 0;
}
void BankersAlgo()
{
    int finish[10] = {0}, WORK[10], seq[10];
    
    for(int i = 0; i < m; i++) WORK[i] = AVAI[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            NEED[i][j] = MAX[i][j] - ALLOC[i][j];
    
    int j = 0;
    int counter = 0;
    while(counter <= 3)
    {
        for(int i = 0; i < n; i++)
        {
            if(finish[i] == false && isLess(i, WORK))
            {
                finish[i] = true;
                for(int k = 0; k < m; k++) { WORK[k] += ALLOC[i][k]; }
                seq[j++] = i;
            }
        }
        counter++;
        if(visited(finish) == 1)
        {
            cout << "\nSAFE SEQUENCE : ";
            for(int i = 0; i < n; i++)
                cout << "P" << seq[i] << " ";
            return;
        }
    }
    cout << "\nThe system is in DEADLOCK state!!";
}

void resourceReq()
{
    int proc, REQ[10];
    cout << "\n\nRESOURCE - REQUEST";
    cout << "\nEnter the requesting process : "; cin >> proc;

    cout << "Enter the REQUEST Vector : ";
    for(int i = 0; i < m ; i++) { cin >> REQ[i]; }
    
    if(!isLess(proc, REQ))
    {
        if(isLessVector(REQ, AVAI, m))
        {
            for(int i = 0; i < n; i++)
            {
                ALLOC[proc][i] += REQ[i];
                NEED[proc][i] -= REQ[i];
                AVAI[i] -= REQ[i];
            }

            cout << "\nYes! The request will be granted immediately\n";
            BankersAlgo();
            return;
        }
        else
        { cout << "Resources cannot be granted since resources are not available!"; }
    }
    else
    { cout << "Resources cannot be granted since process has exceeded the max limit!"; } 
}

int main()
{
    cout << "Enter the number of processes : "; cin >> n;
    cout << "Enter the number of resources : "; cin >> m;
    cout << "Enter the MAX Matrix : \n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> MAX[i][j];

    cout << "\nEnter the ALLOCATION Matrix : \n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> ALLOC[i][j];
    
    cout << "\nEnter the AVAILABLE Vector : ";
    for(int i = 0; i < m; i++)
            cin >> AVAI[i];
    
    BankersAlgo();
    resourceReq();
}
/*
problem 1:
5
3

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

3 3 2

2
1 0 2

problem 2:
5
4

0 0 1 2
2 7 5 0
6 6 5 6
4 3 5 6
0 6 5 2

0 0 1 2
2 0 0 0
0 0 3 4
2 3 5 4
0 3 3 2

2 1 0 0
3
0 1 1 0
*/
