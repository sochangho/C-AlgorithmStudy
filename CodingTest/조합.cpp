#include<iostream>

using namespace std;


#define MAX 5
int arr[MAX];
int ans[MAX];
bool visited[MAX];


void dfs(int cnt, int start) {

	if (cnt == 3) {

		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
		return;

	}
	else {

		for (int i = start; i < MAX; i++) {
			ans[cnt] = arr[i];
			dfs(cnt + 1, i + 1);
		}


	}

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	dfs(0, 0);

	return 0;
}