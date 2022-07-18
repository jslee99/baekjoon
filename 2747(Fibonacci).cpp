#include<iostream>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int a = 0;
	int b = 1;
	if (n == 0) {
		printf("%d", a);
	}
	else if(n == 1){
		printf("%d", b);
	}
	else {
		for (int i = 2; i <= n; i++) {
			int temp = a + b;
			a = b;
			b = temp;			
		}
		printf("%d", b);
	}
	
}