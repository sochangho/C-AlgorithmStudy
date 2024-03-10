#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


#define MAX 1002


vector<int> DFS(vector<int> v[], bool visit[], int start) {
	for (int i = 0; i < MAX; ++i) {
		visit[i] = false;
	}

	visit[start] = true;

	vector<int> result;
	stack<int> st;

	st.push(start);
	result.push_back(start);


	while (!st.empty()) {

	   int value = st.top();
	   st.pop();
	   

	   vector<int>& currentNode = v[value];

	   for (int i = 0; i < currentNode.size(); ++i) {

		   int visitindex = currentNode[i];

		   if (!visit[visitindex]) {

			   visit[visitindex] = true;
			   
			   result.push_back(visitindex);

			   st.push(visitindex);

			   break;
		   }

	   }

	}



	return result;

}


vector<int> BFS(vector<int> v[], bool visit[], int start) {
 
	for (int i = 0; i < MAX; ++i) {
		visit[i] = false;
	}

	
	queue<int> q;
    
	vector<int> result;

	q.push(start);
	
	while (!q.empty()) {

	  int value = q.front();

	  q.pop();

	  result.push_back(value);

	  visit[value] = true;

	  for (int i = 0; i < v[value].size(); ++i) {

		  if (!visit[v[value][i]]) {
			  
			  visit[v[value][i]] = true;
			  q.push(v[value][i]);
			  
		  }
	  }
 
	}

	return result;
}

int main() {

	int N,M, V;

	vector<int> vec[MAX];

	bool visit[MAX];

	cin >> N >> M >> V;
	cout << endl;

	for (int i = 0; i < M; ++i) {

		int from;
		int to;
	
		cin >> from >> to;

		vec[from].push_back(to);
		vec[to].push_back(from);

		cout << endl;
	}


    vector<int> dv = DFS(vec,visit,V);

	vector<int> bv = BFS(vec, visit, V);

	for (int i = 0; i < dv.size(); ++i) {

		cout << dv[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < bv.size(); ++i) {

		cout << bv[i] << " ";
	}

	cout << endl;


	return 0;
}

