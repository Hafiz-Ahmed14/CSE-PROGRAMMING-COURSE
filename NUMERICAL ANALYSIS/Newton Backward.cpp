#include<bits/stdc++.h>
using namespace std;
	 
int fact(int x) {
	int f = 1;
	for(int i = 1; i <= x; i++) {
		f *= i;
	}
	return f;
}
float backward(int val, int n, float x[], float y[][4]) {
	float sum = y[n - 1][0];
	float u = (val - x[n - 1]) / (x[1] - x[0]);

	for(int i = 1; i < n; i++) {
		int temp = 1;
		for(int j = 0; j < i; j++) {
			temp *= (u + j);
		}
		sum += (temp * y[n - 1][i]) / fact(i);
	}
	return sum;
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
    	for(int j = n - 1; j >= i; j--) {
    		y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    	}
    }  

    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i] << "\t";
        for (int j = 0; j <= i; j++) {
            cout << setw(4) << y[i][j] << "\t";
        }
        cout << endl;
    }	 

    int value = 52;
    float res = backward(value, n, x, y);
    cout << "Value at Sin " << value << " is " << res << endl;

	    		    
	return 0;
}	 
