#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char eq[100];
int num[50];
char op[50];
char temp[10];

void append(char temp[], char num) {
	int i = 0;
	while (temp[i] != '\0') {
		i++;
	}
	temp[i] = num;
	temp[i + 1] = '\0';
}

int main(void) {
	temp[0] = '\0';
	scanf("%s", eq);
	int length = strlen(eq);
	int j = 0, k = 0;
	op[k] = '+';
	k++;
	for (int i = 0; i < length; i++) {
		if (eq[i] == '+' || eq[i] == '-') {
			num[j] = atoi(temp);
			j++;
			temp[0] = '\0';
			op[k] = eq[i];
			k++;
		}
		else {
			append(temp, eq[i]);
		}
	}
	num[j] = atoi(temp);
	
	int res = 0;
	int i = 0;
	while (i <= j && op[i] == '+') {
		i++;
	}
	for (int l = 0; l < i; l++) {
		res += num[l];
	}
	for (int l = i; l <= j; l++) {
		res -= num[l];
	}
	printf("%d", res);
	//55 + 35 - 20 + 14 - 20 -40 + 40
	// -> 55 + 35 -20 -14 - 20 - 40 - 40
}