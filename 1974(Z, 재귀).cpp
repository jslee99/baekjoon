#include<iostream>
#include<cmath>

using namespace std;

int N, r, c;
int ans;

int recur(int sum, int n, int ro, int co) {
	if (n == 1) {
		return sum;
	}

	if (ro < n / 2) {
		if (co < n / 2) {
			return recur(sum + 0, n / 2, ro, co);
		}
		else {
			return recur(sum + pow(n, 2) / 4, n / 2, ro, co - n / 2);
		}
	}
	else {
		if (co < n / 2) {
			return recur(sum + pow(n, 2) / 2, n / 2, ro - n / 2, co);
		}
		else {
			return recur(sum + pow(n, 2) * 3 / 4, n / 2, ro - n / 2, co - n / 2);
		}
	}
}

int main(void){
	cin >> N >> r >> c;
	cout << recur(0, pow(2, N), r, c) << endl;
}