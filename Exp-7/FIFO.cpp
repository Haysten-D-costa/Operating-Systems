#include <iostream>
#define MAX 100
using namespace std;

int ramSize, ram[MAX];
int noPages, pageReferenceString[MAX];
int pageFaults = 0, pageFound = 0, replacementIndex = 0;

int main() {
    
    cout << "Enter FRAME Size : "; cin >> ramSize;
    cout << "Enter no. of pages in pageReferenceString : "; cin >> noPages;
    cout << "Enter pageReferenceString : ";
    for(int i=0; i<noPages; i++) {
        cin >> pageReferenceString[i];
    }
    for(int i=0; i<ramSize; i++) {
        ram[i] = -1;
    }
    for(int i=0; i<noPages; i++) {
        pageFound = 0;
        for(int j=0; j<ramSize; j++) {
            if(pageReferenceString[i] == ram[j]) {
                pageFound = 1;
            }
        }
        if(!pageFound) {
            pageFaults++;
            ram[replacementIndex] = pageReferenceString[i];
            replacementIndex = (replacementIndex + 1) % ramSize;
        }
    }
    cout << "Number of faults : " << pageFaults;
    return 0;
}
