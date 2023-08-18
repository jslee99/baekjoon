#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
bool a[100005];
bool d[100005];
bool b[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	string str;
	cin >> str;
	for (int i = 0; i < n; i++) {
		a[i + 1] = str[i] - '0';
		d[i + 1] = str[i] - '0';
	}
	cin >> str;
	for (int i = 0; i < n; i++) {
		b[i + 1] = str[i] - '0';
	}

	//1번 누르지 않는 경우
	int c1 = 0;
	for (int i = 2; i <= n - 1; i++) {
		if (a[i - 1] != b[i - 1]) {
			c1++;
			a[i - 1] = !a[i - 1];
			a[i] = !a[i];
			a[i + 1] = !a[i + 1];
		}
	}

	if (a[n - 1] != b[n - 1]) {
		c1++;
		a[n - 1] = !a[n - 1];
		a[n] = !a[n];
	}


	// 1번 누르는 경우
	int c2 = 1;
	d[1] = !d[1];
	d[2] = !d[2];
	for (int i = 2; i <= n - 1; i++) {
		if (d[i - 1] != b[i - 1]) {
			c2++;
			d[i - 1] = !d[i - 1];
			d[i] = !d[i];
			d[i + 1] = !d[i + 1];
		}
	}

	if (d[n - 1] != b[n - 1]) {
		c2++;
		d[n - 1] = !d[n - 1];
		d[n] = !d[n];
	}


	int r = 99999999;
	if (d[n] == b[n]) {
		r = min(r, c2);
	}

	if (a[n] == b[n]) {
		r = min(r, c1);
	}

	if (r == 99999999) {
		cout << -1 << '\n';
	}
	else {
		cout << r << '\n';
	}
}