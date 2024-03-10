#include<iostream>
using namespace std;

long long Factorial(int value , int limit) {

	if (value == limit) {
		return limit;
	}


	return value * Factorial(value - 1 , limit);
}



int main() {

	int n;

	cin >> n;


	//n ~ (n-k)

	int k = n - 5 + 1;


	cout << Factorial(n , k) / Factorial(5,1) << endl;


}