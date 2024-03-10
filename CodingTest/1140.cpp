#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define MAX 100

vector<int> vec[MAX];

bool isVisties[MAX];

void DFS(int start) {

	stack<int> st;

	for (int i = 0; i < MAX; ++i) {

		isVisties[i] = false;
	}

	

	st.push(start);


	while (!st.empty()) {

	 	int t =  st.top();
		
		st.pop();

		for (int i = 0; i < vec[t].size(); ++i) {

			if (!isVisties[vec[t][i]]) {
				isVisties[vec[t][i]] = true;
				st.push(t);
				st.push(vec[t][i]);
				break;
			}
		}
	}


}



int main() {

	int N;

	cin >> N;



	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			
			int v;

			cin >> v;

			if (v > 0) {
				vec[i].push_back(j);
			}
		}
	}



	for (int i = 0; i < N; ++i) {

		DFS(i);

		for (int j = 0; j < N; ++j) {

			if (isVisties[j]) {
				cout << 1;
			}
			else {
				cout << 0;
			}

			cout << " ";
		}

		cout << endl;
	}

}