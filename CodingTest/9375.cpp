#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {

	int T;

	cin >> T;


	while (T > 0) {

		int n;

		cin >> n;

		map<string, int> m;

		for (int i = 0; i < n; ++i) {
			string value;
			string key;

			cin >> value >> key;


			if (m.find(key) == m.end()) {
				m.insert({key,0});
			}			
			m[key]++;
		}

		int result = 1;

	
		for (map<string,int>::iterator iter = m.begin(); iter != m.end(); iter++) {

			result *= (iter->second+1);
		}

		result--;
						
		cout << result << endl;


		T--;
	}






	return 0;
}