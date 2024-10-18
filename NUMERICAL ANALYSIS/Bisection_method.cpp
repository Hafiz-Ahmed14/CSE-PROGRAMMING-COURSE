#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

double f(double x) {
	return x * x * x - x - 1;
}
void bisection(double a, double b) {
	if(f(a) * f(b) > 0) {
		cout << "Invalid" << nl;
		return;
	}
	double xr, xrd, error = 3.00;
	xr = (a + b) / 2;
	cout << xr << nl;
	int step = 1;
	while(error > 2 or step < 5) {
		if(f(b) * f(xr) < 0.0) {
			b = xr;
		}
		else if(f(a) * f(xr) < 0.0) {
			a = xr;
		}

		xrd = (a + b) / 2;
		cout << "Root : " << xrd <<" ";
		error = ((xrd - xr) / xrd) * 100;
		cout << "Error: " << abs(error) << nl;
		xr = xrd;
		step++;
	}
}

int32_t main()
{
		
	double a, b;
	cin >> a >> b;

	bisection(a, b); 
		    
	return 0;
} 