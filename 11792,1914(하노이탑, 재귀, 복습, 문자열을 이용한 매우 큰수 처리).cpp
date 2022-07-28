#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int n;
int a[21];

void hanoi(int n, int from, int to) {
	if (n == 1) {
		printf("%d %d\n", from + 1, to + 1);
	}
	else {
		hanoi(n - 1, from, 3 - from - to);
		printf("%d %d\n", from + 1, to + 1);
		hanoi(n - 1, 3 - from - to, to);
	}
}

int main(void){
	cin >> n;
	string s = to_string(pow(2,n));
	s = s.substr(0, s.find('.'));
	s[s.length() - 1] = s[s.length() - 1] - 1;
	cout << s << endl;
	if (n <= 20)
		hanoi(n, 0, 2);
}