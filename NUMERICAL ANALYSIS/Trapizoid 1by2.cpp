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
        
 vector<double>x, y;
 int n;
 cin >> n;
 for(int i = 0; i < n; i++) {
     double t; cin >> t;
     x.push_back(t);
 } 

 for(int i = 0; i < n; i++) {
     double t; cin >> t;
     y.push_back(t);
 }

 //cout << x[1] << " "<< x[0] << nl;
 double h = x[1] - x[0];
 //cout << h << nl;

 double sum_of_y0_and_yn = y[0] + y[n - 1];
 double sum_of_y = 0;
 //cout << y[0] << " " << y[n - 1] << nl;
 for(int i = 1; i < n - 1; i ++) {
     //cout << y[i] << " ";
     sum_of_y += y[i];
 }

 cout << (h / 2.00) * (sum_of_y0_and_yn + (2 * sum_of_y)) << nl;
            
 ALHAMDULILLAH;
}
