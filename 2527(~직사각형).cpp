#include<iostream>
#include<vector>

using namespace std;
int a, b, c, d;
int e, f, g, h;
int x, y, p, q;


int main() {
	for (int i = 0; i < 4; i++) {
		cin >> a >> b >> c >> d >> e >> f >> g >> h;
		
		x = max(a, e);
		y = max(b, f);
		p = min(c, g);
		q = min(d, h);

		if (x < p && y < q) {
			cout << 'a' << '\n';
		}
		else if ((x == p && y < q) || (x < p && y == q)) {
			cout << 'b' << '\n';
		}
		else if (x == p && y == q) {
			cout << 'c' << '\n';
		}
		else if(x > p || y > q) {
			cout << 'd' << '\n';
		}
	}
}