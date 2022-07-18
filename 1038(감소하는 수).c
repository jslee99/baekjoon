#include<stdio.h>
#include<math.h>

int dec_num[11];
int end_idx;
int N;

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < 11; i++) {
		dec_num[i] = 10;//ascii 57 : '9'
	}
	dec_num[0] = 0;
	int i;
	for (i = 1; i <= N; i++) {//when i iteration ends ith dec_num constructed
		int inc_idx = 0;
		/*
		while (1) {
			if (inc_idx > 9)
				break;
			if (dec_num[inc_idx] != '9' && dec_num[inc_idx] + 1 < dec_num[inc_idx + 1]) {
				dec_num[inc_idx]++;
				break;
			}
			else {
				inc_idx++;
			}
		}*/
		while (!(dec_num[inc_idx] == 10 || (dec_num[inc_idx] + 1 < dec_num[inc_idx + 1])))
			inc_idx++;

		if (inc_idx > 9) {
			break;
		}
		else if (dec_num[inc_idx] == 10) {
			//dec_num[inc_idx] = inc_idx;
			for (int j = 0; j <= inc_idx; j++) {
				dec_num[j] = j;
			}
		}
		else {
			dec_num[inc_idx]++;
			for (int j = 0; j < inc_idx; j++) {
				dec_num[j] = j;
			}
		}
	}

	if (i == N + 1) {
		long long res = 0;
		int j = 0;
		while (dec_num[j] < 10) {
			res += (long long)(dec_num[j]) * (long long)pow(10, j);
			j++;
		}
		printf("%lld\n", res);
	}
	else {
		printf("%d\n", -1);
	}
	return 0;
}