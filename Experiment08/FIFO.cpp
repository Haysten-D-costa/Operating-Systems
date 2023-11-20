#include <iostream>
#define MAX 100

using namespace std;

int main() {
    int page_found = 0;
    int page_faults = 0;
    int ram_size;
    int no_of_pages;
    int replacement_index = 0;

    int ram[MAX];
    int page_reference[MAX];

    cout << "Enter FRAME Size : ";
    cin >> ram_size;

    cout << "Enter no of pages in the page reference string : ";
    cin >> no_of_pages;

    cout << "Enter the page reference string : ";
    for(int i=0; i<no_of_pages; i++) {
        cin >> page_reference[i];
    }
    for(int j=0; j<ram_size; j++) {
        ram[j] = -1;
    }
    for(int i=0; i<no_of_pages; i++) {
        page_found = 0;
        for(int j=0; j<ram_size; j++) {
            if(page_reference[i] == ram[j]) {
                page_found = 1;
            }
        }
        if(!page_found) {
            page_faults++;
            ram[replacement_index] = page_reference[i];
            replacement_index = (replacement_index + 1) % ram_size;
        }
    }
    cout << endl << "Page Faults : " << page_faults;
    return 0;
}
// 21
// 3 4 3 2 1 2 6 4 5 7 4 1 3 7 7 5 4 1 3 8 5