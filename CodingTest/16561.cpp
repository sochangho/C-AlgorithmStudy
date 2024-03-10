#include<iostream>

using namespace std;


int main() {

	int n;

	cin >> n;


	// n = a+b+c (1 > a ,b,c)

	int N = n / 3;

	int count = 0;

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			
			if (N - (i + j) > 0) {
				count++;
			}
		}
	 }

	cout << count << endl;
}