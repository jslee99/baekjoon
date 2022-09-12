#include<iostream>
#include<vector>

using namespace std;

vector<int> prime;
bool is_prime[10001];
int T;

int main(void) {
	for (int i = 2; i <= 10000; i++) is_prime[i] = true;

	for (int i = 2; i <= 10000; i++) {
		if (!is_prime[i]) continue;

		prime.push_back(i);
		for (int j = 2; i * j <= 10000; j++) {
			is_prime[i * j] = false;
		}
	}
	cin >> T;
	while (T--) {
		int n, a1, a2;
		cin >> n;
		for(int i = 0; i < (int)prime.size(); i++){
			if (prime[i] > n / 2) break;

			if (is_prime[n - prime[i]]) {
				a1 = prime[i], a2 = n - prime[i];
			}
		}
		cout << a1 << " " << a2 << endl;
	}

	cout << endl;
}