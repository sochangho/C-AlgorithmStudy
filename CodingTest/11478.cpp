#include<iostream>
#include<string>
#include<set>
using namespace std;


int main() {

	
	string str;

    
	cin >> str;

	set<string> ss;

	for (int i = 0; i < str.length(); ++i) {

		for (int j = i; j < str.length(); ++j) {

		   ss.insert(str.substr(i, j - i + 1));			
		}		
	}

	cout << ss.size() << endl;	
}