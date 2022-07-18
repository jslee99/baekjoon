#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int num = 666;
	int cnt = 1;
	int check;
	while (cnt != n) {
		num++;
		check = (to_string(num)).find("666");
		if (check == -1) {
			continue;
		}
		else {
			cnt++;
		}
	}
	printf("%d\n", num);
}