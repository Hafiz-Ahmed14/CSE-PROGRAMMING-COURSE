#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

int fact(int x) {
	int f = 1;
	for(int i = 2; i <= x; i++) {
		f *= i;
	}
	return f;
}
float forward(int val, int n, float x[], float y[][4]) {
	int sum = y[0][0];
	float u = (val - x[0]) / (x[1] - x[0]);

	for(int i = 1; i < n; i++) {
		int temp = 1;
		for(int j = 0; j < i; j++) {
			temp *= (u - j);
		}
		sum += (temp * y[0][i]) * fact(i);
	}

	return sum/ (float)10000;
}

int main()
{	
	int n = 4;
	float x[] = {45, 50, 55, 60};

	float y[][4] = {
        {7071, 0, 0, 0},
        {7660, 0, 0, 0},
        {8192, 0, 0, 0},
        {8660, 0, 0, 0}
    };

    for(int i = 1; i < n; i++) {
    	for(int j = 0; j < n - i; j++) {
    		y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    	}
    }

    for(int i = 0; i < n; i++) {
    	cout << setw(4) << x[i] << '\t';
    	for(int j = 0; j < n - i; j++) {
    		cout << setw(4) << y[i][j] << '\t';
    	}
    	cout << nl;
    }

    float value = 52;

    float res = forward(value, n, x, y);
    cout << "Value at Sin " << value << " is " << res << endl;

		    
	return 0;
}
