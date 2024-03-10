#include<iostream>
#include<string>

using namespace std;


//c 문자
//d숫자



int main() {

	string str;

	cin >> str;

	int numCount = 10;
	int charCount = 26;

	int result = 1;


	for (int i = 0; i < str.size(); ++i) {

		if (str[i] == 'c') {

			if (i > 0 && str[i - 1] == str[i]) {

				result *= (charCount-1);
			}
			else {
				result *= charCount;
			}

		}
		else {


			if (i > 0 && str[i - 1] == str[i]) {

			   result *=(numCount-1);
			}
			else {
			   result *= numCount;
			}

		}
	}


	cout << result <<endl;


	return 0;

}


