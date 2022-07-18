#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int* arr = new int[3];
	int a = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr[i]);
	}
	a = arr[0] * arr[1] * arr[2];
	string str = to_string(a);
	arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < str.size(); i++) {
		switch (str[i]) {
			case '0':
				arr[0]++;
				break;
			case '1':
				arr[1]++;
				break;
			case '2':
				arr[2]++;
				break;
			case '3':
				arr[3]++;
				break;
			case '4':
				arr[4]++;
				break;
			case '5':
				arr[5]++;
				break;
			case '6':
				arr[6]++;
				break;
			case '7':
				arr[7]++;
				break;
			case '8':
				arr[8]++;
				break;
			default:
				arr[9]++;
				break;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
}