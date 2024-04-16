#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> v;

bool find(int startindex, int endindex ,long long findValue){
	
	if (startindex > endindex) return false;

	
	int mid = (startindex + endindex) / 2;

	if (v[mid] > findValue) {
		return find(startindex, mid - 1,findValue);
	}
	else if (v[mid] < findValue) {

		return find(mid + 1,endindex,findValue);
	}
	else {

		return true;
	}



}





int main() {

	

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
		
		if (find(0, v.size() - 1, val)) {

			printf("%d\n", 1);
		}
		else {
			printf("%d\n", 0);
		}
	}


}
