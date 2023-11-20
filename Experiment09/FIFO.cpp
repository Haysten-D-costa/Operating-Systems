#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int ch, n, tdm=0, request[50], i;
    cout << "Enter the current head position : ";
    cin >> ch;
    cout << "Enter the number of request to service : ";
    cin >> n;
    cout << "Enter the requests : ";
    for(i=1;i<=n;i++) {
        cin >> request[i];
    }
    for(i=1;i<=n;i++) {
        tdm=tdm+abs(ch-request[i]);
        ch=request[i];
    }
    cout << "\nTotal disk head movement is " << tdm;
    return 0;
}