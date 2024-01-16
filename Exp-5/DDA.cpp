#include <iostream>
#define SIZE 10
using namespace std;

int n, m;
int count = 0;
int isSafe = 1, canGrant, WORK[SIZE], FINISH[SIZE];
int REQ[SIZE][SIZE], ALLOC[SIZE][SIZE], AVAIL[SIZE], sequence[SIZE];

void deadlock_detection() {
    for(int i=0; i<m; i++) WORK[i] = AVAIL[i];
    for(int i=0; i<n; i++) FINISH[i] = 0;
    for(int k=0; k<n; k++) 
    {
        for(int i=0; i<n; i++) {
            
            if(FINISH[i]) continue;

            canGrant = 1;
            for(int j=0; j<m; j++) {
                if(REQ[i][j] > WORK[j]) {
                    canGrant = 0;
                    break;
                }
            }
            if(canGrant) {
                for(int j=0; j<m; j++) {
                    WORK[j] += ALLOC[i][j];
                }
                sequence[count++] = i;
                FINISH[i] = 1;
            }
        }
        k++;
    }
    for(int i=0; i<n; i++) {
        if(!FINISH[i]) {
            isSafe = 0;
        }
    }
    if(isSafe) {
        cout << "\nNo Deadlock exists !\n";
        for(int i=0; i<n; i++) {
            cout << " -> " << sequence[i];
        }
    } else {
        cout << "\nDeadlock Exists !\n";
    }
}

void resource_request() {
    int process_id;
    int request[SIZE];

    cout << "\n\nEnter requesting process id : "; cin >> process_id;
    cout << "Enter request : ";
    for(int i=0; i<m; i++) {
        cin >> request[i];
    }
    for(int i=0; i<m; i++) {
        REQ[process_id][i] += request[i];
    }
    deadlock_detection();
}

int main() {
    cout << "Enter no. processes : "; cin >> n;
    cout << "Enter no. resources : "; cin >> m;
    cout << "Enter available matrix : ";
    for(int i=0; i<m; i++) {
        cin >> AVAIL[i];
    }
    cout << "Enter request matrix : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> REQ[i][j];
        }
    }
    cout << "Enter allocation matrix : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ALLOC[i][j];
        }
    }
    deadlock_detection();
    resource_request();
    return 0;
}