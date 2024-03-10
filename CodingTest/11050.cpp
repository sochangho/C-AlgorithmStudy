#include<iostream>

using namespace std;

// 조합공식
//n! / k! * (n-k)!


int Factorial(int value) {

	int f = 1;

	while (value > 0) {

		f *= value;

		value -= 1;
	}



	return f;
}




int main() {

	int n, k;

	cin >> n >> k;

	int ff =  Factorial(n) / (Factorial(k) * Factorial(n - k));


	cout << ff << endl;
}