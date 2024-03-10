#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<int>* vec, vector<int>& visit, int S) {

	queue<int> q;

	q.push(S);

	visit[S] = 0;

	while (!q.empty()) {

		int current = q.front();

		q.pop();

		for (int i = 0; i < vec[current].size(); ++i) 
		{
			int next = vec[current][i];
			if (visit[next] == -1) {

				visit[next] = visit[current] + 1;

				q.push(next);

			}
		}
	}
}



int main() {

	int F, S, G, U, D;

	cin >> F >> S >> G >> U >> D;

	vector<int>* vec = new vector<int>[F+1];

	vector<int> visit(F+1, -1);




	for (int i = 1; i <= F; ++i) {

		int up = i + U;
		int down = i - D;

		if (up <= F) {
			vec[i].push_back(up);
		}

		if (down >= 1) {
			vec[i].push_back(down);
		}
	}



	bfs(vec, visit, S);


	int result = visit[G];

	if (result == -1) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << result <<endl;
	}

	delete[] vec;
	

	return 0;
}