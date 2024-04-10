#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main() {

	vector<string> v= { "c=","c-","dz=","d-","lj","nj","s=","z=" };


	string word;

	cin >> word;


	int index = 0;

	for (int i = 0; i < v.size(); ++i) {

		
		while (1) {

			index = word.find(v[i]);
			if (index == string::npos)
				break;
			word.replace(index, v[i].length(), "#");
		}

	}

	cout << word.length() << endl;


}