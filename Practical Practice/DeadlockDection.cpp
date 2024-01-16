#include <iostream>
#define SIZE 10
using namespace std;

int count = 0;
int n, m, finish[SIZE];
int sequence[SIZE], AVAIL[SIZE], WORK[SIZE];
int ALLOC[SIZE][SIZE], REQ[SIZE][SIZE];

void deadlock_detection() {
    int isSafe, canGrant;
    for(int i=0; i<m; i++) WORK[i] = AVAIL[i];
    for(int i=0; i<n; i++) finish[i] = 0;

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
                
            if(finish[i]) continue;
            
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
                finish[i] = 1;
            }
        }
        k++;
    }
    for(int i=0; i<n; i++) {
        if(!finish[i]) {
            isSafe = 0;
        }
    }
    if(isSafe) {
        for(int i=0; i<n; i++) {
            cout << " -> P" << sequence[i];
        }
    } else {
        cout << "\nDeadlock Exists !\n";
    }
    
}
void resource_request() {
    int process_id, request[SIZE];

    cout << "Enter requesting process id : "; cin >> process_id;
    cout << "Enter requests : ";
    for(int i=0; i<m; i++) {
        cin >> request[i];
    }
    for(int i=0; i<m; i++) {
        REQ[process_id][i] += request[i];
    }
    cout << "New Request : \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << REQ[i][j] << " ";
        }
        cout << "\n";
    }
    deadlock_detection();
}


int main() {

    cout << "Enter no. of processes : "; cin >> n;
    cout << "Enter no. of resources : "; cin >> m;
    
    cout << "Enter available processes : ";
    for(int i=0; i<m; i++) {
        cin >> AVAIL[i];
    }
    cout << "Enter allocated resources : \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ALLOC[i][j];
        }
    }
    cout << "Enter request matrix : \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> REQ[i][j];
        }
    }
    deadlock_detection();
    resource_request();
    return 0;
}