#include<iostream>

using namespace std;

int n, k;
int a[200005];
int b[100005];
int ans = 1;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int s = 1, e = 1;
	b[a[1]]++;

	do {
		if (b[a[e + 1]] + 1 <= k) {
			e++;
			b[a[e]]++;
			ans = max(ans, e - s + 1);
		}
		else {
			s++;
			b[a[s - 1]]--;
			if (s > e) {
				e++;
			}
		}
	} while (e < n);

	cout << ans << '\n';
}