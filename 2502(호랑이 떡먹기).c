#include<stdio.h>
#include<stdlib.h>

int ddu;
int day;

void recur(int before_ddu, int now_ddu, int now_day) {
	if (now_day == 2) {
		printf("%d\n%d", before_ddu, now_ddu);
		exit(0);
	}
	else if (now_day == 3) {
		if (before_ddu >= now_ddu) {
			return;
		}
		if (now_ddu - before_ddu > before_ddu) {
			return;
		}
		printf("%d\n%d", now_ddu - before_ddu, before_ddu);
		exit(0);
	}
	else {
		if (before_ddu >= now_ddu) {
			return;
		}
		recur(now_ddu - before_ddu, before_ddu, now_day - 1);		
	}
}

int main(void) {
	scanf("%d %d", &day, &ddu);
	for (int i = ddu - 1; i > 0; i--) {
		recur(ddu - i, i, day - 1);
	}
}