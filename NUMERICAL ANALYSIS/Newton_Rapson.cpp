#include<bits/stdc++.h>
#include<cmath>
using namespace std;
 
// Example 2
// double func(double x)
// {
//     return x*sin(x) + cos(x);
// }
 

// double derivFunc(double x)
// {
//     return x * cos(x);
// }

Example 1
double func(double x)
{
    return x * x * x - 2 * x - 5;
}
 

double derivFunc(double x)
{
    return 3 * x * x - 2;
}

// Example 3

// double func(double x) {
// 	return x * exp(x) - 1;
// }

// double derivFunc(double x) {
// 	return x * exp(x) + exp(x);
// }

// Example 4
// double func(double x) {
// 	return (sin(x)) - (x / 2.0);
// }

// double derivFunc(double x) {
// 	return (cos(x)) - (0.5);
// }

// Example 5
// double func(double x) {
// 	return 4 * exp(-x) * (sin(x)) - 1;
// }

// double derivFunc(double x) {
// 	return 4 * exp(-x) * (cos(x)) - 4 * exp(-x) * (sin(x));
// }
 

void Newton_Rapson(double x) {
	double x0 = (x - (func(x) / derivFunc(x)));
	cout << x0 << endl;
	double error = 3.00;
	int step = 1;
	while(error > 2.00 or step <10) {
		double x1 = (x0 - (func(x0) / derivFunc(x0)));
		cout << x1 ;
		error = ((x1 - x0) / x1 ) * 100.00;
		cout << " " << abs(error) <<"%"<< endl;
		x0 = x1;
		step++; 

	}
}
 

int main()
{
    // double x0 = M_PI / 2.00;   
    // // // Newton_Rapson(x0);

     double x0 ; cin >> x0;
     Newton_Rapson(x0);


    return 0;
}