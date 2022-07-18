#include<stdio.h>
#include<string.h>


char str[100000];
int cnt = 0;
int t;



int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%s", &str);
		/*
		while (1) {
			for (int i = 0; i < len / 2; i++) {
				if (str[i] != str[len - i - 1]) {
					if (str[i] == str[len - i - 2]) {
						for (int j = len - i - 1; j < len; j++) {
							str[j] = str[j + 1];
						}
						cnt++;
						len--;
						break;
					}
					else if (str[i + 1] == str[len - i - 1]) {
						for (int j = i; j < len; j++) {
							str[j] = str[j + 1];
						}
						cnt++;
						len--;
						break;
					}
					else {
						cnt = 2;
						break;
					}
				}
			}
		}*/
		int left = 0, right = strlen(str) - 1;
		while (left < right) {
			if (str[left] != str[right]) {
				cnt++;
				int l = left, r = right;

				l++;
				while (l < r) {
					if (str[l] != str[r]) {
						break;
					}
					else {
						l++;
						r--;
					}
				}
				if (l >= r) {
					break;
				}

				l = left, r = right;
				r--;
				while (l < r) {
					if (str[l] != str[r]) {
						cnt++;
						break;
					}
					else {
						l++;
						r--;
					}
				}
				break;

			}
			else {
				left++;
				right--;
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}
