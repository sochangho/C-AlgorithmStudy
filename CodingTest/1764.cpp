#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;



int main() {

	int n, m;

	cin >> n >> m;

	set<string> s;
	vector<string> v;
	for (int i = 0; i < n; ++i) {

		string people;

		cin >> people;

		s.insert(people);		
	}



	for (int i = 0; i < m; ++i) {

		string people;

		cin >> people;

		auto f =  s.find(people);

		if (f != s.end()) {
			v.push_back(*f);
		}

	}

	sort(v.begin(), v.end());


	cout << v.size() << endl;

	for (auto iter = v.begin(); iter != v.end(); iter++) {		
		cout << *iter << " " <<endl;
	}


}

