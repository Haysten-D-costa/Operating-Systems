#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int ch,n,tdm=0,request[50],i,count=0,index,dist;
    cout << "Enter the current head position : ";
    cin >> ch;
    cout << "Enter the number of request to service : ";
    cin >> n;
    cout << "Enter the requests : ";
    for(i=1; i<=n; i++) {
        cin >> request[i];
    }
    while(count != n)
    {
        int min = 9999;
        for(i=1; i<=n; i++)
        {
            dist = abs(ch - request[i]);
            if(min > dist)
            {
                min = dist;
                index = i;
            }
        }
        tdm = tdm + min;
        ch = request[index];
        request[index] = 9999;
        count++;
    }
    cout << "\nTotal disk head movement is " << tdm;
    return 0;
}
