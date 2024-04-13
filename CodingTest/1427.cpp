#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int main() {

	string str;
	cin >> str;
	sort(str.begin(), str.end(),
		[](char& a, char& b) {
			return a > b;
		});

	cout << str << endl;         
}