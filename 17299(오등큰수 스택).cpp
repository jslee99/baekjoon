#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int n;
int a[1000005];
int num[1000005];
int f[1000005];
int ngf[1000006];

//f, i


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		num[a[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		f[i] = num[a[i]];
	}

	stack<pair<int, int>> s; // ¼ýÀÚ, f
	for (int i = n; i >= 1; i--) {
		while (!s.empty() && f[i] >= s.top().second) {
			s.pop();
		}

		if (!s.empty()) {
			ngf[i] = s.top().first;
		}
		else {
			ngf[i] = -1;
		}

		s.push({ a[i], f[i] });
	}

	for (int i = 1; i <= n; i++) {
		cout << ngf[i] << ' ';
	}

	return 0;
}