#include<iostream>

using namespace std;
int N, M;
long long num_of_mod_prefix_sum[1005];
long long cnt = 0;

int main() {
	cin >> N >> M;
	num_of_mod_prefix_sum[0] = 1;

	int A, mod_prefix = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		mod_prefix = (mod_prefix + A) % M;
		cnt += num_of_mod_prefix_sum[mod_prefix];
		num_of_mod_prefix_sum[mod_prefix]++;
	}

	cout << cnt << endl;
}