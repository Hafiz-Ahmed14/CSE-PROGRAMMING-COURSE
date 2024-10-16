// //Shortest Job First
#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

void calculateCompletionTime(vector<Process>& processes, vector<int>& completionTime) {
    int currentTime = 0;

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.burstTime < b.burstTime;
    });

    for (int i = 0; i < processes.size(); i++) {
        currentTime = max(currentTime, processes[i].arrivalTime);
        currentTime += processes[i].burstTime;
        completionTime[i] = currentTime;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cin >> processes[i].arrivalTime;
        cin >> processes[i].burstTime;
    }

    vector<int> completionTime(n,0);

    calculateCompletionTime(processes, completionTime);

    vector<int> arrival(n), burst(n), completion(n), turn, waiting, response;
    for (int i = 0; i < n; i++) {
        completion[processes[i].id - 1] = completionTime[i];
        arrival[processes[i].id - 1] = processes[i].arrivalTime;
        burst[processes[i].id - 1] = processes[i].burstTime;
    }

    // Turn Around Time
    for(int i = 0; i < n; i++) {
        turn.push_back(completion[i] - arrival[i]);
    }

    // Waiting time
    for(int i = 0; i < n; i++) {
        waiting.push_back(turn[i] - burst[i]);
    }

    // Response Time
    for(int i = 0; i < n; i++) {
        response.push_back(completion[i] - burst[i]);
    }

    // Display the table
    cout << "I " << "A " << "B " << "C " << "T " << "W " << "R " << nl;
    for(int i = 0; i < n; i++) {
        cout << i + 1 << " " << arrival[i] << " " << burst[i] << " " << completion[i] << " " << turn[i] << " " << waiting[i] << " " << response[i] << nl;
    }

    cout << nl;

    // Gantt Chart
    cout << "Gantt Chart:" << nl;
    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        cout << "| P" << processes[i].id << " ";
        totalTime += processes[i].burstTime;
    }
    cout << "|" << nl;

    // Display the timeline
    cout << "0    ";
    for (int i = 0; i < n; i++) {
        cout << completionTime[i] << "    ";
    }
    cout << nl;

        // Display the table
    cout << "| I |" << " A |" << " B |" << " C |" << " T |" << " W |" << " R |" << nl;
    cout << "-------------------------------------" << nl;
    for(int i = 0; i < n; i++) {
        cout << "\t" << i + 1 << "\t\t" << arrival[i] <<"\t\t"<< burst[i] <<"\t\t" << completion[i] <<"\t\t"<<turn[i] <<"\t\t"<<waiting[i] <<"\t\t"<<response[i] << nl;
    }

    cout << nl;


    cout << "Gantt Chart:" << nl;
    

    vector<int> gantt_chart;
    for (int i = 0; i < n; i++) {
        // Print idle time
        if (i > 0 && processes[i].arrivalTime > completionTime[i - 1]) {
            cout << "| Idle ";
            int idleTime = processes[i].arrivalTime - completionTime[i - 1];
            totalTime += idleTime;
            gantt_chart.push_back(totalTime);
        }

        cout << "| P" << processes[i].id << " ";
        totalTime += processes[i].burstTime;
        gantt_chart.push_back(totalTime);
    }

    // Display the timeline
    cout << "|" << nl;

    cout << 0 << " ";
    for(auto x: gantt_chart) {
        cout << "   "<<x << "   ";
    }
    cout << nl;


    return 0;
}