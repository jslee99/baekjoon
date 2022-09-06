#include<iostream>

using namespace std;

int T;
int N;
int price[1000000];
int max_price[1000000];

int main(void) {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> price[i];

		max_price[N - 1] = price[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			if (max_price[i + 1] < price[i]) {
				max_price[i] = price[i];
			}
			else {
				max_price[i] = max_price[i + 1];
			}
		}

		long long ans = 0;
		for (int i = 0; i < N; i++) {
			ans += (long long)(max_price[i] - price[i]);
		}

		cout << ans << endl;
	}

}