#include<iostream>
#include<string>
#include<queue>
using namespace std;



//���ϻ����� �������� �ʷϻ��� ���̸� ���� ������ ���Ѵ�.����, ���ϻ����� ����� ���� �׸��� �ƴ� ����� ���� �׸����� �� �ٸ� �� �ִ�.
//
//ũ�Ⱑ N��N�� �׸����� �� ĭ�� R(����), G(�ʷ�), B(�Ķ�) �� �ϳ��� ��ĥ�� �׸��� �ִ�.�׸��� �� ���� �������� �������� �ִµ�, ������ ���� ������ �̷���� �ִ�.��, ���� ������ �����¿�� ������ �ִ� ��쿡 �� ���ڴ� ���� ������ ���Ѵ�. (������ ���̸� ���� ������ ���ϴ� ��쵵 ���� �����̶� �Ѵ�)
//
//���� ���, �׸��� �Ʒ��� ���� ��쿡




//RRRBB
//GGBBB
//BBBRR
//BBRRR
//RRRRR



//���ϻ����� �ƴ� ����� ���� �� ������ ���� �� 4���̴�. (���� 2, �Ķ� 1, �ʷ� 1) ������, ���ϻ����� ����� ������ 3�� �� �� �ִ�. (���� - �ʷ� 2, �Ķ� 1)
//
//�׸��� �Է����� �־����� ��, ���ϻ����� ����� ���� ���� �ƴ� ����� ���� �� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.




#define MAX 100


string graph[MAX];

bool visit[MAX][MAX];

char cc[3];

int result_a = 0; // �Ϲ�
int result_b = 0; // �������


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