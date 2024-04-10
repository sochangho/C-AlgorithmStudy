#include<iostream>
#include<string>

using namespace std;


//a : 98
//z: 122
// 


bool check(string& word) {

	
	int a = static_cast<int>('a');
	int z = static_cast<int>('z');

	int leng = z - a + 1;

	int* arr = new int[leng];

	for (int i = 0; i < leng; ++i) {
		arr[i] = -1;
	}

	
	for (int i = 0; i < word.length(); ++i) {

		int index = static_cast<int>(word[i]) - a;

		

		if (arr[index] == -1) {

			arr[index] = i;
		}
		else {

			if ((i - arr[index]) > 1) {
				
				return false;
			}
			
			arr[index] = i;

		}
	}


	return true;
}





int main()
{
	int n;

	cin >> n;

	int count = 0;

	for (int i = 0; i < n; ++i) {

		string word;

		cin >> word;


		if (check(word)) {
			count++;
		}

	}

	cout << count <<endl;

}