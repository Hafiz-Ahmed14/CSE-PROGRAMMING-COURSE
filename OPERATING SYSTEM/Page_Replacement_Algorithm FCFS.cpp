#include<bits/stdc++.h>
 using namespace std;
 
int n;
bool pageExists(vector<int>& frame, int page) {
    for (int i = 0; i < frame.size(); ++i) {
        if (frame[i] == page)
            return true;
    }
    return false;
}


void FCFS(vector<int>& pages, int frameSize) {
    vector<int> frame;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        
        if (pageExists(frame, pages[i]))
            continue;

        
        if (frame.size() < frameSize) {
            frame.push_back(pages[i]);
        } else {
            frame.erase(frame.begin());
            frame.push_back(pages[i]);
        }

        
        ++pageFaults;


        cout << "Current frame: ";
        for (int j = 0; j < frame.size(); j++) {
            cout << frame[j] << " ";
        }
        cout << endl;
    }
    int hitratio = pages.size() - pageFaults;
    cout << "NO of Hits: "<< hitratio << endl;
    cout << "Total Page Faults: " << pageFaults << endl;
    cout << "Hits Ratio: " << fixed<<setprecision(2) << ((double)hitratio / n) * 100 <<" %"<< endl;
}

int main() {
    cin >> n;
    vector<int> pages;

    int frameSize ;
    cin >> frameSize;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pages.push_back(x);
    }
    cout << "Page Reference String: ";
    for (int i = 0; i < pages.size(); ++i) {
        cout << pages[i] << " ";
    }
    cout << endl;
    cout << "Frame Size: " << frameSize << endl;
    FCFS(pages, frameSize);

    return 0;
}
