#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//����
//������û�� ������ ������ �����Կ��� ���ο� ������ �־�����.
//
//������ ���������״� Si�� �����ؼ� Ti�� ������ N���� ������ �־����µ�, �ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ� �ؾ� �Ѵ�.
//
//�����, ������ ���� ���Ŀ� ���� ������ ������ �� �ִ�. (��, Ti �� Sj �� ��� i ������ j ������ ���� ���� �� �ִ�.)
//
//������û ������ �� �񸮸�, �������� ���͵帮��!


//�Է�
//ù ��° �ٿ� N�� �־�����. (1 �� N �� 200, 000)
//
//���� N���� �ٿ� Si, Ti�� �־�����. (0 �� Si < Ti �� 109)

//�Է�
//���ǽ��� ������ ����϶�.

//����
//3
//1 3
//2 4
//3 5



//���
//2



vector<pair<int, int>> class_time;

priority_queue<int, vector<int>, greater<int>> pq_less;

int main() {

	int N;

	cin >> N;


	for (int i = 0; i < N; ++i) {

		int to;
		int from;

		cin >> to >> from;

		class_time.push_back({ to,from });

	}

	sort(class_time.begin(), class_time.end());
	 

	pq_less.push(class_time[0].second);

	for (int i = 1; i < N; i++) {

		pq_less.push(class_time[i].second);

		if (pq_less.top() <= class_time[i].first) {
			pq_less.pop();
		}

	}

	cout << pq_less.size() << endl;

}