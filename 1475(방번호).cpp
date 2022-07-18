#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int num;
	scanf("%d", &num);
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
	int length = (to_string(num)).length();

	for (int i = 0; i < length; i++) {
		int x = num % 10;
		if (x == 9 || x == 6) {
			if (arr[6] <= arr[9]) {
				arr[6]++;
			}
			else {
				arr[9]++;
			}
		}
		else {
			arr[x]++;
		}
		num = num / 10;
	}

	int max = -1;
	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("%d\n", max);


	delete[] arr;
}