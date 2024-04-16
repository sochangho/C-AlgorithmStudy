#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main() {

	int N, M;  // N : 단어개수, 길이가 M이상인 단어만
	cin >> N >> M;
	map<string, int> m;

	for(int i = 0; i < N; ++i) {

		string str;

		cin >> str;

		if(str.length() >= M)
		{	
			m[str]++;		
		}
	}
	vector<pair<string, int>> v(m.begin(),m.end());	
	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b)
		{
			if (a.second == b.second) {

				if (a.first.length() == b.first.length()) {

					return a.first < b.first;
				}

				return a.first.length() > b.first.length();
			}
			return a.second > b.second;
		});


	for (auto& val : v) {
		cout << val.first << "\n";
	 }

}