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

int findOptimalPage(vector<int>& pages, vector<int>& frame, int startIndex) {
    //unordered_map<int, int> nextIndex;
    map<int,int>nextIndex;
    int farthest = -1;
    int optimalPage = -1;

    for (int i = 0; i < frame.size(); ++i) {  // 1 2 3
        for (int j = startIndex; j < pages.size(); ++j) {
            if (frame[i] == pages[j]) {
                nextIndex[frame[i]] = j;
                break;
            }
            if (nextIndex.find(frame[i]) == nextIndex.end()) {
                nextIndex[frame[i]] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < frame.size(); ++i) {
        if (nextIndex[frame[i]] > farthest) {
            farthest = nextIndex[frame[i]];
            optimalPage = frame[i];
        }
    }

    return optimalPage;
}

void optimalPageReplacement(vector<int>& pages, int frameSize) {
    vector<int> frame;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        if (pageExists(frame, pages[i]))
            continue;

        if (frame.size() < frameSize) {
            frame.push_back(pages[i]);
        }
        else {
            int replacePage = findOptimalPage(pages, frame, i + 1);
            for (int j = 0; j < frame.size(); ++j) {
                if (frame[j] == replacePage) {
                    frame[j] = pages[i];
                    break;
                }
            }
        }

        ++pageFaults;

        cout << "Current frame: ";
        for (int j = 0; j < frame.size(); ++j) {
            cout << frame[j] << " ";
        }
        cout << endl;
    }
    int miss = pageFaults;
    int hit = n - miss;
    cout << "Total Page Miss: " << miss << endl;
    cout << "Total Page Hit: " << hit << endl;

    cout << "Hits Ratio: " << fixed << setprecision(2) << ((double)hit / n) * 100 << " %" << endl;
    cout << "Miss Ratio: " << fixed << setprecision(2) << ((double)miss / n) * 100 << " %" << endl;
}

int main() {
    cin >> n;
    int frameSize;
    cin >> frameSize;
    vector<int> pages(n);
    cout << "Page Reference String: ";

    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    for (int i = 0; i < pages.size(); ++i) {
        cout << pages[i] << " ";
    }
    cout << endl;
    cout << "Frame Size: " << frameSize << endl;
    optimalPageReplacement(pages, frameSize);

    return 0;
}
