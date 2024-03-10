#include<iostream>
#include<vector>
#include<queue>

using namespace std;


#define MAX 99999999

//typedef pair<long long, int> Pair;




void Dijkstra(vector<pair<int,int>>* vec ,vector<int>& costs,
	int* paths, int start) {

	priority_queue<pair<int, int>>
		pq;

	pq.push({ 0 , start });

	costs[start] = 0;

	

	while (!pq.empty()) {

      int current_cost = -pq.top().first;
	  int current_index = pq.top().second;

	  pq.pop();

	  if (costs[current_index] < current_cost) continue;
	  
	  for (int i = 0; i < vec[current_index].size(); ++i) {
		 
		  int next_cost = vec[current_index][i].second + current_cost;
		  int next_index = vec[current_index][i].first;
		  
		  if ( next_cost < costs[next_index]) 
		  {
			  costs[next_index] = next_cost;
			  paths[next_index] = current_index;
			  pq.push({ -costs[next_index] , next_index });
		  }
	  }
	}
}


int main() {


	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int n, m;

	cin >> n;
	cin >> m;


	vector<pair<int, int>>* vec = new vector<pair<int, int>>[m+1];

	int* paths = new int[m+1];

	vector<int> vec_cost(m + 1, MAX);

	for (int i = 0; i < m; ++i) {
		int p1;
		int p2;
		int cost;

		cin >> p1 >> p2 >> cost;

		vec[p1].push_back({ p2,cost });
	}

	int s, d;

	cin >> s >> d;


	vector<int> result;

	Dijkstra(vec, vec_cost, paths,s);


	result.push_back(d);

	int i = d;

	while (true) {

		if (i == s) {
			break;
		}

		int prev = paths[i];
		i = prev;

		result.push_back(i);

	}




	cout<< vec_cost[d] <<endl;
	cout << result.size() << endl;

	for (int i = result.size() - 1; i >= 0; --i) {
		cout << result[i] << " ";
	}
	cout << endl;


	
	return 0;
}