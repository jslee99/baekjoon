#include<iostream>
#include<vector>

using namespace std;
bool is_prime[4000001];
vector<int> prime;
int N;
int ans;

int main() {
	cin >> N;
	ans = 0;
	for (int i = 0; i <= 4000000; i++) is_prime[i] = true;

	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i <= 4000000; i++) {
		if (!is_prime[i]) continue;

		for (int j = 2; i * j <= 4000000; j++) {
			is_prime[i * j] = false;
		}
	}

	for (int i = 2; i <= 4000000; i++) {
		if (is_prime[i]) prime.push_back(i);
	}

	for (int i = 0; i < (int)prime.size(); i++) {
		int sum = 0;
		for (int j = i; j < (int)prime.size(); j++) {
			sum += prime[j];
			if (sum == N) {
				ans++;
				break;
			}
			else if (sum > N) {
				break;
			}
		}
	}

	cout << ans << endl;
}