#include<iostream>

using namespace std;


// 2 * 5 = 10
// 1 ~ 5
// 

int main() {

	int n;

	cin >> n;


	int result = 1;

	while (n > 0) {

		
		result*= n;
		n--;
	}


	cout <<  result <<endl;

}