#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int f[100000];
int n;
int t;
int a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	n = 1;
	f[0] = 0;
	f[1] = 1;
	while (f[n] <= 1000000000) {
		n++;
		f[n] = f[n - 1] + f[n - 2];
	}

	cin >> t;
	while (t--) {
		cin >> a;
		vector<int> ans;
		
		while (a > 0) {
			int* x = lower_bound(f, f + n + 1, a);

			if (*x > a)
				x--;

			ans.push_back(*x);
			a -= *x;
		}
		
		sort(ans.begin(), ans.end());
		for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
			cout << *it << ' ';

		cout << '\n';
	}
}