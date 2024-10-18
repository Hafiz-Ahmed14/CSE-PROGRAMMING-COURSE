#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

// double g(double x)
// {
//     return (1-x*x*x);

// }

double g(double x) {
	return 1 / (sqrt(x + 1));
}

void iteration(double a)
{
   double x=g(a);
   double err=3.00;
   int step=1;
   cout<<x<<endl;
    while(step < 10)
    {
        double x1=g(x);
        double err=(abs(x1-x)/x1)*100;
        cout<<x1<<" ";
        double error = ((x1 - x) / x1) * 100.00;
		cout << "error:" << abs(error) << "%" << endl;
		x=x1;
        step++;
    }
}
int main()
{
   double b; cin >> b;
   iteration(b);

}