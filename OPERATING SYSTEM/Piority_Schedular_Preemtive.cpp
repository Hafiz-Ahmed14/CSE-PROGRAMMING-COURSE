#include<bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
};


struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.priority < p2.priority;
    }
};

map<int,int>mp;
vector<int> a;
void priorityScheduler(vector<Process>& processes) {
    
    sort(processes.begin(), processes.end(), [](const Process& p1, const Process& p2) {
        return p1.arrivalTime < p2.arrivalTime;
    });

    int n = processes.size();
    int currentTime = 0;

    
    priority_queue<Process, vector<Process>, ComparePriority> pq;

    
    int index = 0;

    int sum = 0;
    int counter = 0;
    cout << "Gant Chart: "<<endl;
    
    while (index < n || !pq.empty()) {
        
        while (index < n && processes[index].arrivalTime <= currentTime) {
            pq.push(processes[index]);
            index++;
        }


        if (!pq.empty()) {
            Process currentProcess = pq.top();
            pq.pop();

           
            currentTime += min(currentProcess.burstTime, 1);
            currentProcess.burstTime = max(0, currentProcess.burstTime - 1);
            //currentProcess.burstTime = abs(currentProcess.burstTime - 1);

            
            //cout << "Process " << currentProcess.id -1 << "->" << currentTime << endl;
            cout <<" P"<<currentProcess.id<<" |";
            a.push_back(++counter);

            mp[currentProcess.id] = ++sum ;

            
            if (currentProcess.burstTime > 0) {
                pq.push(currentProcess);
            }
        } 
        else {
            
            currentTime++;
        }
    }
}

int main() {
    
    vector<Process> processes = {
        {1, 3, 5, 2},
        {2, 2, 4, 1},
        {3, 5, 6, 3},
        {4, 1, 7, 4},
        {5, 0, 5, 3}
    };

    cout << "Priority Scheduler (Preemptive)" << endl;
    priorityScheduler(processes);

    cout << "0| ";
    for(auto x: a) {
        cout << x <<" ";
    }

    cout << endl;
    for(auto [x,y]: mp) {
        cout << x <<"->" << y << endl;
    }

    return 0;
}