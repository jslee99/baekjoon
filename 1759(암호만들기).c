#include<stdio.h>
#include<stdlib.h>


int L, C;
char chs[15];
char pwd[16];

int cmp(void* a, void* b) {
	return *(char*)a - *(char*)b;
}

//password (cur_idx, idx of chs
void password(int cur_idx_pwd, int idx_of_chs, int m, int j) {
	if (cur_idx_pwd < L - 1) {
		// C - i, (L - 1) -	(cur_idx_pwd + 1) + 1 == L - cur_idx_pwd -1
		// C - i >= L - cur_idx_pwd - 1
		// i <= C - L + cur_idx_pwd + 1
		for (int i = idx_of_chs; i <= C - L + cur_idx_pwd + 1; i++) {
			pwd[cur_idx_pwd] = chs[i];
			if (chs[i] == 'a' || chs[i] == 'e' || chs[i] == 'i' || chs[i] == 'o' || chs[i] == 'u') {
				password(cur_idx_pwd + 1, i + 1, m + 1, j);
			}
			else {
				password(cur_idx_pwd + 1, i + 1, m, j + 1);
			}
			//password(cur_idx_pwd + 1, i + 1);
		}
	}
	else {
		for (int i = idx_of_chs; i < C; i++) {
			pwd[cur_idx_pwd] = chs[i];
			if (chs[i] == 'a' || chs[i] == 'e' || chs[i] == 'i' || chs[i] == 'o' || chs[i] == 'u') {
				if (m + 1 >= 1 && j >= 2) {
					printf("%s\n", pwd);
				}
			}
			else {
				if (m >= 1 && j + 1 >= 2) {
					printf("%s\n", pwd);
				}
			}
			
			//printf("%s\n", pwd);
		}
	}
	return;
}

int main(void) {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		getchar();
 		scanf("%c", &chs[i]);
	}
	getchar();
	qsort(chs, C, sizeof(char), cmp);
	pwd[L] = '\0';
	password(0, 0, 0, 0);
}





