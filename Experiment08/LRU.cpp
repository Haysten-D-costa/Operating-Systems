#include <iostream>
#define MAX 100
using namespace std;

int main() {
    int page_found;
    int page_faults = 0;
    int ram_size;
    int no_of_pages;
    int replacement_index = 0;

    int ram[MAX];
    int page_reference[MAX];
    int frame_index[MAX];

    cout << "Enter the FRAME Size : ";
    cin >> ram_size;

    cout << "Enter the no of pages in the page reference string : ";
    cin >> no_of_pages;

    cout << "Enter the page reference string : ";
    for(int i=0; i<no_of_pages; i++) {
        cin >> page_reference[i];
    }

    for(int j=0; j<ram_size; j++) {
        ram[j] = -1;
        frame_index[j] = -1;
    }

    for(int i=0; i<no_of_pages; i++) {
        page_found = 0;
        for(int j=0; j<ram_size; j++) {
            if(page_reference[i] == ram[j]) {
                page_found = 1;
                frame_index[j] = i;
            }
        }
        if(!page_found) {
            page_faults++;
            replacement_index = 0;
            for(int j=0; j<ram_size; j++) {
                if(frame_index[replacement_index] > frame_index[j]) {
                    replacement_index = j;
                }
            }
            ram[replacement_index] = page_reference[i];
            frame_index[replacement_index] = i;
        }
    }
    cout << endl << "Page Faults : " << page_faults;
    return 0;
}