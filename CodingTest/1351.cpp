#include<iostream>
#include<map>
using namespace std;


long long P, Q;

map<long long, long long> m; // 최적화를 위해!!!

long long A(long long n) {

	
	if (m.find(n) != m.end()) {
		return m[n];
	}

	long long result = A(n / P) + A(n/Q);

	m[n] = result;

	return result;
}

int main() {

	long long N;
	
	cin >> N >> P >> Q;

	m[0] = 1;

	if (N == 0) 
	{
		cout<< m[0] <<endl;
	}
	else
	{
		cout << A(N) << endl;
	}
}