#include<iostream>
using namespace std;
#define MAX 5
int arr[MAX];
int ans[MAX];
bool visited[MAX];

void dfs(int cnt) {

	if (cnt == 3) {

		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
		return;
	}
	else {

		for (int i = 0; i < MAX; i++) {
			if (!visited[i]) {
				ans[cnt] = arr[i];
				//visited[i] = true;
				dfs(cnt + 1);
				///visited[i] = false;
			}
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
	dfs(0);
	return 0;
}