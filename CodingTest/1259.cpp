#include<iostream>
#include<string>
#include<vector>
using namespace std;


//�Ӹ���Ҽ��� ���������� ���� ���� ���;��Ѵ�.
//ex) reverse;


int main() {


	vector<string> results;

	while (true) {

		string value;

		cin >> value;

		if (value == "0") {

			break;
		}
		
		string copy = "";
		
		for (int i = value.size() - 1; i >= 0; --i) {
			copy += value[i];
		}

		if (copy == value) {

			results.push_back("yes");
		}
		else {
			results.push_back("no");
		}

	}



	for (int i = 0; i < results.size(); ++i) {

		cout << results[i] << endl;
	}


}