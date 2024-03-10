#include<iostream>
#include<vector>
using namespace std;


int result[13];

void dfs(vector<int>& v,int count, int start) {

	if (count == 6) {

		for (int i = 0; i < 6; ++i) {

			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}
	else {

		for (int j = start; j < v.size(); ++j) {

			result[count] = v[j];
			
			dfs(v,count+1, j + 1);
		}


	}




}



int main() {

	while (true) {



		int k;

		cin >> k;
		
		if (k == 0) {
			break;
		}


		vector<int> vec(k,0);


		for (int i = 0; i < k; ++i) {
			cin >> vec[i];
		}

		dfs(vec ,0, 0);
		cout << endl;
	}



	return 0;
}