#include<iostream>
using namespace std;

int main(void) {
	for (int i = 1; i < 10000; i++) {
		bool self = true;

		if (1 <= i && i < 10) {
			for (int j = 1; j < i; j++) {
				if (j + j == i) {
					self = false;
					break;
				}
			}
			if (self == true) {
				printf("%d\n", i);
			}
		}
		else if (10 <= i && i < 100) {
			for (int j = 1; j < i; j++) {
				int temp = j;
				int sum = temp;
				for (int k = 0; k < 2; k++) {
					sum += temp % 10;
					temp = temp / 10;
				}
				if (sum == i) {
					self = false;
					break;
				}
			}
			if (self == true) {
				printf("%d\n", i);
			}
		}
		else if (100 <= i && i < 1000) {
			for (int j = i - 27; j < i; j++) {
				int temp = j;
				int sum = temp;
				for (int k = 0; k < 3; k++) {
					sum += temp % 10;
					temp = temp / 10;
				}
				if (sum == i) {
					self = false;
					break;
				}
			}
			if (self == true) {
				printf("%d\n", i);
			}
		}
		else {
			for (int j = i - 36; j < i; j++) {
				int temp = j;
				int sum = temp;
				for (int k = 0; k < 4; k++) {
					sum += temp % 10;
					temp = temp / 10;
				}
				if (sum == i) {
					self = false;
					break;
				}
			}
			if (self == true) {
				printf("%d\n", i);
			}
		}
	}
}