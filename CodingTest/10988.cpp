#include<iostream>
#include<string>

using namespace std;


int F(string* s) {

	for (int i = 0; i < s->length() / 2; ++i) {

		if ((*s)[i] != (*s)[s->length() - i - 1]) {

			return 0;
		}
	}

	return 1;
}



int main() {

	string word;

	cin >> word;

	cout << F(&word) << endl;
}