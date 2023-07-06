#include<cstdio>
#include<iostream>

using namespace std;

long long len[1000]; // length of S(i)
int N;

char recur(int k, int n) {// S(k)의 n번째 문자는?
	if (k == 0) {
		switch (n) {
		case 1:
			return 'm';
		case 2:
			return 'o';
		case 3:
			return 'o';
		}
	}

	if (n <= len[k - 1]) {
		return recur(k - 1, n);
	}
	else if (n >= len[k - 1] + k + 4) {
		return recur(k - 1, n - len[k - 1] - k - 3);
	}
	else {
		if (n == len[k - 1] + 1) return 'm';
		else return 'o';
	}
}

int main() {
	scanf("%d", &N);
	len[0] = 3;
	int i = 0;
	while (N > len[i]) {
		len[i + 1] = 2 * len[i] + i + 4;
		i++;
	}
	printf("%c\n",recur(i, N));

	return 0;
}

/*
#include<algorithm>

char buf[100[;
scanf("%s", &buf);
*/