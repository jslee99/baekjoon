#include<stdio.h>
#include<math.h>

int a[4][8];
int K;
int visit[4] = { 0, };
int res = 0;

void rotation(int num, int dir) {
	if (dir == 1) {
		int temp = a[num][7];
		for (int i = 7; i >= 1; i--) {
			a[num][i] = a[num][i - 1];
		}
		a[num][0] = temp;
		visit[num] = 1;
		//right
		int new_num = num + 1;
		if (new_num < 4 && visit[new_num] == 0 && a[num][3] != a[new_num][6])
			rotation(new_num, -dir);
		//left
		new_num = num - 1;
		if (new_num >= 0 && visit[new_num] == 0 && a[num][7] != a[new_num][2])
			rotation(new_num, -dir);
	}
	else {
		int temp = a[num][0];
		for (int i = 0; i <= 6; i++) {
			a[num][i] = a[num][i + 1];
		}
		a[num][7] = temp;
		visit[num] = 1;
		//right
		int new_num = num + 1;
		if (new_num < 4 && visit[new_num] == 0 && a[num][1] != a[new_num][6])
			rotation(new_num, -dir);
		//left
		new_num = num - 1;
		if (new_num >= 0 && visit[new_num] == 0 && a[num][5] != a[new_num][2])
			rotation(new_num, -dir);
	}
}

int main(void) {
	for (int i = 0; i < 4; i++) {
		char buf[9];
		scanf("%s", buf);
		for (int j = 0; j < 8; j++) {
			a[i][j] = buf[j] - 48;
		}
	}
	scanf("%d", &K);
	while (K--) {
		int num, dir;
		for (int i = 0; i < 4; i++) {
			visit[i] = 0;
		}
		scanf("%d %d", &num, &dir);
		rotation(num - 1, dir);
	}
	for (int i = 0; i < 4; i++) {
		if (a[i][0] == 1)
			res += (int)pow(2, i);
	}
	
	printf("%d", res);
}

