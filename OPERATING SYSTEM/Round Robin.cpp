#include<bits/stdc++.h>
using namespace std;

class Input {
public:
    string Pid;
    int AT, BT, CT, TAT, WT, RT;
};

int main() {
    int n, tq;
    cin >> n >> tq;
    vector<Input> inputs(n);
    for (auto &i : inputs) {
        cin >> i.Pid >> i.AT >> i.BT;
    }
    sort(inputs.begin(), inputs.end(), [&](Input a, Input b) {
        if (a.AT == b.AT) {
            return a.Pid < b.Pid;
        }
        return a.AT < b.AT;
    });
    queue<Input> q;
    map<string, int> ct;
    q.push(inputs[0]);
    int time = 0;
    int i = 1;

    cout << "\t\t\t\t\t\t\t\tGantt Chart: \n";
    cout <<"==========================================================================================\n";
    vector<string> id;
    vector<pair<int,int>> tracker;
    while (!q.empty()) {
        Input temp = q.front();
        q.pop();
        if (temp.BT > tq) {
            temp.BT -= tq;
            //cout << time << "-"<< temp.Pid << "-" << time + tq << " | ";
            tracker.push_back({time,time + tq});
            id.push_back(temp.Pid);
            time += tq;
            ct[temp.Pid] = time;
            while (i < n && inputs[i].AT <= time) {
                q.push(inputs[i]);
                i++;
            }
            q.push(temp);
        } else {
            //cout << time << "-"<< temp.Pid << "-" << time + temp.BT << " | ";
            id.push_back(temp.Pid);
            tracker.push_back({time, time + temp.BT});
            time += temp.BT;
            ct[temp.Pid] = time;
        }
    }

    cout << endl;
    cout << "|";
    for(auto x: id) {
        cout << "\t"<< x << "\t|";
    }
    cout << endl;
    cout <<"------------------------------------------------------------------------------------------\n";
    cout <<"0";
    for(auto [x, y]: tracker) {
        cout << "\t\t" << y <<" ";
    }

    for (int i = 0; i < n; i++) {
        inputs[i].CT = ct[inputs[i].Pid];
        inputs[i].TAT = inputs[i].CT - inputs[i].AT;
        inputs[i].WT = inputs[i].TAT - inputs[i].BT;
    }
    sort(inputs.begin(), inputs.end(), [&](Input a, Input b) {
        return a.Pid < b.Pid;
    });
    // Output process details
    cout <<"\n\n\tState Table: \n";
    cout <<"======================\n";
    cout << "\nPid\tAT\tBT\tCT\tTAT\tWT" << endl;
    cout <<"=======================\n";
    for (auto i : inputs) {
        cout << i.Pid << "\t" << i.AT << "\t" << i.BT << "\t" << i.CT << "\t" << i.TAT << "\t" << i.WT << endl;
    }
    return 0;
}
