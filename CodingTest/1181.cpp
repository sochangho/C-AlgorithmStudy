#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;



int main() {

	int n;

	cin >> n;

	vector<string> v;
	set<string> s;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;

		if (s.find(str) != s.end()) {
			continue;
		}

		v.push_back(str);	
		s.insert(str);
	}

	
	sort(v.begin(), v.end(), [](string& a, string& b) {

		if (a.length() == b.length()) {

			return a < b;
		}

		return a.length() < b.length();
		});






	for (int i = 0; i < v.size(); ++i) {

		cout << v[i] << endl;

	}

}