#include<stdio.h>
#include<string.h>

char buf[13];
int N;

int main(void) {
	scanf("%d", &N);
	while (1) {
		if (N == 1) {
			N++;
			continue;
		}

		sprintf(buf, "%d", N);
		int check = 1;
		for (int i = 0; i < strlen(buf) / 2; i++) {
			if (buf[i] != buf[strlen(buf) - 1 - i]) {
				check = 0;
				break;
			}
		}
		if (check == 0) {
			N++;
			continue;
		}

		check = 1;
		for (int i = 2; i * i <= N; i++) {
			if (N % i == 0) {
				check = 0;
				break;
			}
		}
		if (check == 0) {
			N++;
			continue;
		}
		break;
	}
	printf("%d\n", N);
}


