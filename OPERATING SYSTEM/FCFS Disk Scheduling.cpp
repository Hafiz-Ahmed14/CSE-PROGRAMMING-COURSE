// FCFS disk scheduling
/***************************************************/
/*                  Md. HAFIZ AHMED                */
/*               DEPARTMENT OF CSE,BAUET           */
/***************************************************/
#include<bits/stdc++.h>
using namespace std;

//Define start and end marco
#define BISMILLAH ios_base::sync_with_stdio(0);cin.tie(0);
#define ALHAMDULILLAH return 0
#define ll long long
#define pb push_back
#define nl '\n'



int32_t main()
{
    BISMILLAH
        
    int n; cin >> n;
    ll sum = 0;
    int head = 55;
    cout << "FCFS DISK Scheduling order: " << nl;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        //cout << x << "-" << head << "->";
        int diff = abs(x - head);
        sum += diff;
        if(i < n) {
            cout << "(" << max(x, head) << "-" << min(x,head) <<")"<<"+";
        }
        else cout << "(" << max(x, head) << "-" << min(x,head) <<")" <<"=";
        //cout << "sum is: " << sum << nl;
        head = x;
    } 
    
    cout << "Total Movement: " << sum << nl;


    ALHAMDULILLAH;
}
