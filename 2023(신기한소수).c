#include<stdio.h>
#include<math.h>

int N;
int num[8];

int isPrime(int x) {// 1 T   2 F
	if (x == 1)
		return 0;
	for (int i = 2; i <= (int)sqrt((double)x); i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

void solve(int idx) {
	if (idx == 0) {
		for (int i = 1; i < 10; i++) {
			if (isPrime(i)) {
				num[idx] = i;
				solve(idx + 1);
			}		
		}
	}
	else if(idx < N){
		for (int i = 0; i < 10; i++) {
			num[idx] = i;
			int temp = 0;
			int exp = 0;
			for (int j = idx; j > -1; j--) {
				temp += num[j] * pow(10, exp);
				exp++;
			}
			if (isPrime(temp))
				solve(idx + 1);
		}
	}
	else {
		int temp = 0;
		int exp = 0;
		for (int j = idx - 1; j > -1; j--) {
			temp += num[j] * pow(10, exp);
			exp++;
		}
		printf("%d\n", temp);
	}
	return;
}

int main(void) {
	scanf("%d", &N);
	solve(0);
}
