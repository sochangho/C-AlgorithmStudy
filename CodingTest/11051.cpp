#include<iostream>

using namespace std;

// C(n,k) = C(n-1,k) + C(n-1,n-k)
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 

// d[n][k] = d[n-1][k-1] + d[n-1][k];

#define MAX 1001

int d[MAX][MAX];

int main() {

	int N, K;

	cin >> N >> K;

	for (int i = 0; i <= N; ++i) 
	{
  		for (int j = 0; j <= i; ++j) {

			if (j == 0 || j == i) {
			
				d[i][j] = 1;
				continue;
			}
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}

	
	cout << d[N][K] << endl;
	
	return 0;
}