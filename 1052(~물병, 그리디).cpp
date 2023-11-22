#include <iostream>

using namespace std;

int n, k;
int ans = 0;

bool check(int m) {
	int o = m;
	int x = 0;

	while (o > 1) {
		int temp = o / 2;
		int temp2 = o % 2;

		o = temp;
		x += temp2;
	}

	return o + x > k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int m = n;

	while (check(m)) 
		m++;
	
	cout << m - n << '\n';
	
	return 0;
}