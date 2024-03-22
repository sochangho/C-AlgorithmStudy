#include<iostream>
#include<string>
#include<queue>
using namespace std;



//적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다.따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
//
//크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다.그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다.또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
//
//예를 들어, 그림이 아래와 같은 경우에




//RRRBB
//GGBBB
//BBBRR
//BBRRR
//RRRRR



//적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강 - 초록 2, 파랑 1)
//
//그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.




#define MAX 100


string graph[MAX];

bool visit[MAX][MAX];

char cc[3];

int result_a = 0; // 일반
int result_b = 0; // 적녹색약


void CheckPush(queue<pair<int, int>>& q,char& c,int y, int x) {

	if (!visit[y][x] && graph[y][x] == c) 
	{
     visit[y][x] = true;
     q.push({ y,x });
	}
}


void bfs(char& c, int N, int i_index, int j_index) {


	queue<pair<int, int>> q;

	q.push({ i_index,j_index });

	visit[i_index][j_index] = true;

	while (!q.empty()) {

		auto f = q.front();

		int y = f.first;
		int x = f.second;

		q.pop();

		
		if (y + 1 < N)
		{
			CheckPush(q, c, y + 1, x);
		}


		if (y - 1 >= 0)
		{
			CheckPush(q, c, y - 1, x);
		}

		if (x + 1 < N)
		{
			CheckPush(q, c, y, x + 1);
		}


		if (x - 1 >= 0)
		{
			CheckPush(q, c, y, x - 1);
		}

	}


}


int main() {

	int N;

	cin >> N;

	cc[0] = 'R';
	cc[1] = 'G';
	cc[2] = 'B';

	for (int i = 0; i < N; ++i) {

		string v;

		cin >> v;

		graph[i] = v;

	}


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			visit[i][j] = false;

		}
	}



	for (int c_index = 0; c_index < 3; ++c_index) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visit[i][j] && graph[i][j] == cc[c_index]) {
					bfs(cc[c_index], N, i, j);
					result_a++;
				}				
			}
		}
	}


	for (int i = 0; i < N; ++i) {

		for (int j = 0; j < N; ++j) {

			if (graph[i][j] == 'G') {
				graph[i][j] = 'R';
			}
		}

	}





	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			visit[i][j] = false;

		}
	}



	for (int c_index = 0; c_index < 3; ++c_index) {

	

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {


				if (!visit[i][j] && graph[i][j] == cc[c_index]) {
					bfs(cc[c_index], N, i, j);
					result_b++;
				}

			}
		}

	}



	cout << result_a << " " << result_b <<endl;


}