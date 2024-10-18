#include<bits/stdc++.h>
using namespace std;
#define nl '\n';

//x ^ 3 - x -1
double f(double x) {
	return x * x * x - x - 1;
}

void falsi(double a, double b) {
	if(f(a) * f(b) > 0) {
		cout << "Invalid";
		return;
	}
	double xr, xrd, error = 3.00;
	xr = (a * f(b) - b * f(a)) / (f(b) - f(a));
	cout << xr << nl;
	int step = 1;
	while(error > 2.00 or step < 5) {
		if(f(a) * f(xr)) {
			b = xr;
		}
		else if(f(b) * f(xr)) {
			a = xr;
		}
		xrd = (a * f(b) - b * f(a)) / (f(b) - f(a));
		error = ((xrd - xr) / xrd) * 100.00;
		cout << "root: " << xrd << " ";
		cout << "error:" << abs(error) << "%" << nl;
		step++;
		xr = xrd;
	}
}
int main()
{	
	double a, b;
	cin >> a >> b;

	falsi(a, b);
		    
	return 0;
}