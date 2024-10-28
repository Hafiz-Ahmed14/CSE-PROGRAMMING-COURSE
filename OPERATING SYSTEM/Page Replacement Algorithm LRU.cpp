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

int findLRUPage(vector<int>& pages, vector<int>& frame, int startIndex) {
    unordered_map<int, int> lastUsedIndex;
    int leastRecent = INT_MAX;
    int lruPage = -1;

    for (int i = 0; i < frame.size(); ++i) {
        // Find the last used index of each page in frame
        for (int j = startIndex - 1; j >= 0; --j) {
            if (frame[i] == pages[j]) {
                lastUsedIndex[frame[i]] = j;
                break;
            }
            if (lastUsedIndex.find(frame[i]) == lastUsedIndex.end()) {
                lastUsedIndex[frame[i]] = -1;
            }
        }
    }

    for (int i = 0; i < frame.size(); ++i) {
        // Identify the page with the least recent usage
        if (lastUsedIndex[frame[i]] < leastRecent) {
            leastRecent = lastUsedIndex[frame[i]];
            lruPage = frame[i];
        }
    }

    return lruPage;
}

void LRUPageReplacement(vector<int>& pages, int frameSize) {
    vector<int> frame;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        if (pageExists(frame, pages[i])) {
            // Move the page to the most recent position in frame
            auto it = find(frame.begin(), frame.end(), pages[i]);
            frame.erase(it);
            frame.push_back(pages[i]);
            continue;
        }

        if (frame.size() < frameSize) {
            frame.push_back(pages[i]);
        }
        else {
            int replacePage = findLRUPage(pages, frame, i);
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
    LRUPageReplacement(pages, frameSize);

    return 0;
}
