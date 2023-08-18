#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
long long g;
vector<long long> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> g;

	long long x = 1;// ¿¹Àü ¸ö¹«°Ô
	while (pow(x, 2) + g >= pow(x + 1, 2)) {
		double d = sqrt(pow(x, 2) + g);
		if (d == (double)(long long)d) {
			v.push_back((long long)d);
		}
		x++;
	}

	if (v.size() == 0) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}
	

	return 0;
}