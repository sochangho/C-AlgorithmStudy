#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define MAXD 10001
#define INF 99999999



// ���ͽ�Ʈ�� �˰���

void d(vector<pair<int, int>>* grap, vector<int>& dists) {


	//first : ����ġ 
	//second : �ε���
	priority_queue<pair<int, int>, vector<pair<int, int>>
		, greater<pair<int, int>>>
		pq;

	pq.push({ 0,0 });
	dists[0] = 0;

	while (!pq.empty()) {

	auto currentNode = pq.top();

	int cur_cost = currentNode.first;
	int cur_index = currentNode.second;

	pq.pop();

	  for (int i = 0; i < grap[cur_index].size(); ++i) 
	  {

		int next_index	= grap[cur_index][i].first;
		int next_cost = grap[cur_index][i].second;

		if (dists[next_index] > cur_cost + next_cost) 
		{
		   dists[next_index] = cur_cost + next_cost;
		   pq.push({ dists[next_index] , next_index });
	    }

	  }

	}


}



int main() {



	// ������, ����ġ


	int N, D;

	cin >> N >> D;


	// ������, ����ġ
	vector<pair<int, int>>* vec_grap =
		new vector<pair<int, int>>[D+1];

	vector<int> vec_dist(D+1, INF);



	for (int i = 0; i < D; ++i) {
		vec_grap[i].push_back({ i + 1 , 1 });
	}


	for (int i = 0; i < N; ++i)
	{
		
		int from;
		int to;
		int cost;

		cin >> from >> to >> cost;

		if (from > D || to > D) {
			continue;
		}

		vec_grap[from].push_back({ to,cost });	
	}

	d(vec_grap, vec_dist);

	cout << vec_dist[D] << endl;

	return 0;
}