#include<iostream>
#define MAX 10
using namespace std;

int n, m, s = 0;
int allocation[MAX][MAX], maxi[MAX][MAX], available[MAX], need[MAX][MAX], work[MAX], count=0, ss[MAX];
int finish[MAX], check1=0, check2=0;

bool resourceRequest() {
    int reqProcess, request[MAX];
    cout << "Enter the process id : "; cin >> reqProcess;
    cout << "Enter the request resources : ";
    for(int j=0; j<m; j++) { cin >> request[j]; }

    for(int j=0; j<m; j++) {
        if(request[j] <= need[reqProcess][j]) {
            if(request[j] <= available[j]) {
                allocation[reqProcess][j] = allocation[reqProcess][j] + request[j];
                need[reqProcess][j] = need[reqProcess][j] - request[j];
                available[reqProcess] = available[reqProcess] - request[j];
            } else { return false; }
        } else {
            cout << "Cannot !"; 
            return false;
        }
    }
    cout << "Can be included...."; 
    return true;
}
void safeseq() {
    for(int j=0; j<m; j++) work[j] = available[j];
    for(int i=0; i<n; i++) finish[i] = 0;
    
    while(count != n) {
        for(int i=0; i<n; i++) {
            
            check1=0;
            for(int j=0; j<m; j++) {
                if(finish[i]==0 && (need[i][j] <= work[j]))
                    check1++;
                if(check1 == m) {
                    for(int j=0; j<m; j++) {
                        work[j] += allocation[i][j];
                        finish[i]=1;
                    }
                    ss[s]=i;
                    s++;
                    count++;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(finish[i]==1) check2++;
        if(check2 == n) {
            cout<<"safe sequence exists"<<endl;
            cout<<"safe sequence: ";
            for(int i=0; i<n; i++) { cout<<"P"<<ss[i]<<"  "; }
        }
        else {
            cout<<"safe sequence doesnt exists"<<endl;
        }
    }
}
int main()
{
    cout<<"enter no. of processes: "; cin>>n;
    cout<<"enter no. of resources:"; cin>>m;

    cout<<"Enter the allocated resources"<<endl;
    for(int i=0; i<n; i++) {
        cout<<"P"<<i<<": "<<endl;
        for(int j=0; j<m; j++) {
            cout<<"==>R"<<j<<": "; cin>>allocation[i][j];
        }
        cout<<endl;
    }
    cout<<"Enter the maxmum resources"<<endl;
    for(int i=0; i<n; i++) {
        cout<<"P"<<i<<": "<<endl;
        for(int j=0; j<m; j++) {
            cout<<"==>R"<<j<<": "; cin>>maxi[i][j];
        }
        cout<<endl;
    }
    cout<<"Enter the available resource: "<<endl;
    for(int j=0; j<m; j++) {
        cout<<"==>R"<<j<<": "; cin>>available[j];
    }
    cout<<endl<<endl;

    cout<<"Need Matrix:"<<endl;
    for(int j=0; j<m; j++) {
        cout<<"R"<<j<<"\t";
    }
    cout<<endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            need[i][j] = maxi[i][j] - allocation[i][j];
            cout<<need[i][j]<<"\t";
        }
        cout<<endl;
    }
    if(resourceRequest()) {
        safeseq();
    } else {
        cout << "not possible, Program Ends !";
    }
    return 0;
}