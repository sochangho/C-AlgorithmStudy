#include<iostream>

using namespace std;



int main() {

	int cnt;

	cin >> cnt;


	for (int i = 0; i < cnt; ++i) {

		long long result = 1;

		int m, n;

		cin >> n >> m;
        
		int r = 1;
		for (int j = m; j > m - n; j--) {

			result = result * j;
			result = result / r;
			r++;
		}
		cout << result << endl;
	}



}