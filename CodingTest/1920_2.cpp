#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> v;


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;


	for (int i = 0; i < N; ++i) {
		long long val;

		cin >> val;

		v.push_back(val);
	}


	sort(v.begin(), v.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i) {

		long long val;
		cin >> val;

		bool isFind = binary_search(v.begin(), v.end(), val);
	    
		if (isFind) {
			printf("%d\n", 1);
		}
		else {
			printf("%d\n", 0);
		}
	}


}
