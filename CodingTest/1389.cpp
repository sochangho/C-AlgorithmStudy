#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int bfs(vector<int>* vec ,int* isVisits, int startindex, int N) {


	int sum = 0;



	queue<int> q;

	for (int i = 0; i < N; ++i) {
		isVisits[i] = -1;
	}

	q.push(startindex);

	isVisits[startindex] = 0;

	while (!q.empty()) {

		int v =  q.front();

		q.pop();
	
	    
		for (int i = 0; i < vec[v].size(); ++i) {

			int next = vec[v][i];

			if ( isVisits[next] == -1) {

				isVisits[next] = isVisits[v] + 1;

				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		sum += isVisits[i];
	}



	return sum;
}






int main() {

	int N, M; 

	cin >> N >> M;


	vector<int>* vecArray = new vector<int>[N+1];

	int* isVisit = new int[N + 1];

	for (int i = 0; i < M; ++i) {

		int p1;
		int p2;

		cin >> p1 >> p2;


		vecArray[p1].push_back(p2);
		vecArray[p2].push_back(p1);

	}

	int min = 0;
	int index = 0;


	for (int i = N; i >= 1; --i) {

		int result = bfs(vecArray,isVisit ,i,N+1);

		if (i == N) {
			min = result;
			index = i;
		}
		else {

			if (min >= result) {

				min = result;
				index = i;
			}
		}		 
	}

	cout << index << endl;

	delete[] vecArray;
	delete[] isVisit;

	return 0;
}