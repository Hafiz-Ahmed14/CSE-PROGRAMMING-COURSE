#include<bits/stdc++.h>

using namespace std;

int Near(vector<int>& queue, int head) {
    int minDistance = 1e9;
    int index = -1;
    
    for (int i = 0; i < queue.size(); ++i) {
        int distance = abs(head - queue[i]);
        if (distance < minDistance) {
            minDistance = distance;
            index = i;
        }
    }
    
    return index;
}

void SSTF(vector<int>& a, int head) {
    vector<int> queue(a);
    int totalMovement = 0;

    cout << "SSTF Disk Scheduling Order: ";
    while (!queue.empty()) {
        int nearestIndex = Near(queue, head);
        int nearestRequest = queue[nearestIndex];
        totalMovement += abs(head - nearestRequest);
        head = nearestRequest;
        cout << head << " ";
        queue.erase(queue.begin() + nearestIndex);
    }
    
    cout << "\nTotal head movement: " << totalMovement << endl;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    int head = 50;

    for(int i = 0; i < n; i++) cin >> a[i];

    SSTF(a, head);

    return 0;
}
