#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;


// 1 2 4 8 9 

vector<int> router;



int find_max_dist(int n, int c)
{
	int l_dist = 0; // 첫번째 공유기에서 첫번째 공유기까지의 간격
	int r_dist = router[n - 1] - router[0]; // 첫 번째 공유기에서 마지막 공유기 까지 간격

	int result_dist;

	while (l_dist <= r_dist) {

		int install_router = 1;

		int mid_dist = (l_dist + r_dist) / 2;

		int start = router[0];

		for (int i = 0; i < n; ++i) {
			
			int end = router[i];


			if (end - start >= mid_dist) {
				install_router += 1;
				start = end;
			}
		}

		if (install_router >= c) {

			result_dist = mid_dist;
			l_dist = mid_dist + 1;

		}
		else {
			r_dist = mid_dist - 1;
		}

	}

	return  result_dist;
}


 

int main() {

	int N, C;
	
	cin >> N >> C;

	int coordinate_x;
	for (int i = 0; i < N; ++i) {

		
		cin >> coordinate_x;
		router.push_back(coordinate_x);
	}


	sort(router.begin(), router.end());

    

	cout << find_max_dist(N, C);
}