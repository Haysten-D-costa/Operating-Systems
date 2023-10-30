#include<iostream>
using namespace std;

int m, n;
int REQ[10][10], ALLOC[10][10], NEED[10][10], AVAI[10];
int isLess(int proc, int WORK[])
{
    for(int i=0; i<m; i++)
        if(REQ[proc][i] > WORK[i])
            return 0;
    return 1;
}
int isLessVector(int a[], int b[], int n)
{
    for(int i=0; i<n; i++)
        if(a[i] > b[i])
            return 0;
    return 1;
}
int visited(int finish[])
{
    int i;
    for(i=0; i<n; i++)
        if(finish[i] == 0)
            break;
    if(i == n)
        return 1;
    return 0;
}
void deadlockDetection()
{
    int j = 0;
    int counter = 0;
    int finish[10] = {0}, WORK[10], seq[10];

    for(int i=0; i<m; i++) WORK[i] = AVAI[i];
    while(counter <= 3)
    {
        int found = 0;
        for(int i=0; i<n; i++)
        {
            if(finish[i] == false && isLess(i, WORK))
            {
                finish[i] = true;
                for(int k=0; k<m; k++) { WORK[k] += ALLOC[i][k]; }
                seq[j++] = i;
                found++;
            }
        }
        if(found == 0) { break; }
        counter++;
        if(visited(finish) == 1)
        {
            cout << "\nThe system is NOT in DEADLOCK STATE!!";
            cout << "\nSAFE SEQUENCE : ";
            for(int i=0; i<n; i++)
                cout << "P" << seq[i] << " ";
            return;
        }
    }
    cout << "\nThe system is in DEADLOCK state!!";

}

int main()
{
    cout << "Enter the number of processes : "; cin >> n;
    cout << "Enter the number of resources : "; cin >> m;
    cout << "Enter the REQUEST Matrix : \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> REQ[i][j];

    cout << "\nEnter the ALLOCATION Matrix : \n";
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> ALLOC[i][j];
    
    cout << "\nEnter the AVAILABLE Vector : ";
    for(int i=0; i<m; i++)
            cin >> AVAI[i];
    
    deadlockDetection();
}
