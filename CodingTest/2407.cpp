#include<iostream>

using namespace std;

//string numAdd

string dp[101][101];

string add(string s1, string s2) {

	string result = "";
	int sum = 0;
    int len = max(s1.size(), s2.size());


	for (int i = 0; i < len || sum; i++) {

		if (s1.size() > i) sum += (s1[i] - '0');
		if (s2.size() > i) sum += (s2[i] - '0');

		result += ((sum % 10) + '0');
		sum /= 10;
	}


	return result;
}



string combination(int n, int m) {

	if (n == m || m == 0) {
		return "1";
	}

	string& res = dp[n][m];
	if (res != "") return res;

	res = add(combination(n - 1, m - 1), combination(n - 1, m));
	return res;
}


int main() {

	int n, m;

	cin >> n >> m;

	combination(n, m);

	for (int i = dp[n][m].size() - 1; i >= 0; --i) {

		cout << dp[n][m][i];
	}

	//cout << endl;

}