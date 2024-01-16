#include <iostream>
#define SIZE 10
using namespace std;

int count = 0;
int n, m, finish[SIZE];
int sequence[SIZE], AVAIL[SIZE], WORK[SIZE];
int MAX[SIZE][SIZE], ALLOC[SIZE][SIZE], NEED[SIZE][SIZE];

void safe_sequence() {
    int isSafe, canGrant;
    for(int i=0; i<m; i++) WORK[i] = AVAIL[i];
    for(int i=0; i<n; i++) finish[i] = 0;

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {

            if(finish[i]) continue;
            
            canGrant = 1;
            for(int j=0; j<m; j++) {
                if(NEED[i][j] > WORK[j]) {
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
            cout << "P" << sequence[i] << " -> ";
        }
    } else {
        cout << "\n No safe sequence Exists !\n";
    }
    
}
void resource_allocation() {
    int process_id, REQ[SIZE];

    cout << "\nEnter requested process id : "; cin >> process_id;
    cout << "Enter requests : ";
    for(int i=0; i<m; i++) {
        cin >> REQ[i];
    }

    int canAllocate = 1;
    for(int i=0; i<m; i++) {
        if(REQ[i] > NEED[process_id][i] || REQ[i] > AVAIL[i]) {
            canAllocate = 0;
        }
    }
    if(canAllocate) cout << "Request can be granted Immediately !";
    else cout << "Request cannot be granted immediately !";
}


int main() {

    cout << "Enter no. of processes : "; cin >> n;
    cout << "Enter no. of resources : "; cin >> m;
    
    cout << "Enter available processes : ";
    for(int i=0; i<m; i++) {
        cin >> AVAIL[i];
    }
    cout << "Enter max resources : \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> MAX[i][j];
        }
    }
    cout << "Enter allocated resources : \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> ALLOC[i][j];
        }
    }
    cout << "Need matrix : \n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            NEED[i][j] = MAX[i][j] - ALLOC[i][j];
            cout << NEED[i][j] << " ";
        }
        cout << "\n";
    }
    safe_sequence();
    resource_allocation();
    return 0;
}