#include<iostream>
#include<set>
#include<string>

using namespace std;


int main() {

	int n, m;
	int count = 0;

	set<string> s;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {

		string value;

		cin >> value;

		s.insert({ value });

	}

	for (int i = 0; i < m; ++i) {

		string value;

		cin >> value;

		if (s.find(value) != s.end())
		{
			count++;

		}
	}

	cout << count << endl;
}
