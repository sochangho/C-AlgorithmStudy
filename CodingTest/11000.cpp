#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//문제
//수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다.
//
//김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
//
//참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)
//
//수강신청 대충한 게 찔리면, 선생님을 도와드리자!


//입력
//첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200, 000)
//
//이후 N개의 줄에 Si, Ti가 주어진다. (0 ≤ Si < Ti ≤ 109)

//입력
//강의실의 개수를 출력하라.

//예제
//3
//1 3
//2 4
//3 5



//출력
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