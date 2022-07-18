#include<iostream>
#include<iostream>
using namespace std;

int main(void) {
	int n;
	int cnt = 0;
	scanf_s("%d", &n);
	int data = n;
	do {
		if (data < 10) {
			data = data * 10 + data;
			cnt++;
		}
		else {
			data = (data % 10)*10 + ((data % 10) + (data - (data % 10)) / 10) % 10;
			cnt++;
		}
	} while (data != n);
	printf("%d", cnt);
}