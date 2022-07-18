#include<iostream>
#include<limits>

using namespace std;

int N;
int height[80001];
int can_see[80001];
int what_building_is_blocking[80001];
long long ans = 0;
int criteria_building;

int main(void) {
	cin >> N;
	criteria_building = N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &height[i]);
	}
	height[N] = numeric_limits<int>::max();
	can_see[N] = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (height[i] <= height[i + 1]) {
			can_see[i] = 0;
			what_building_is_blocking[i] = i + 1;
		}
		else {
			int c = what_building_is_blocking[i + 1];
			while (height[c] < height[i]) {
				c = what_building_is_blocking[c];
			}
			can_see[i] = c - i - 1;
			what_building_is_blocking[i] = c;
		}
		ans += (long long)can_see[i];
	}

	cout << ans << endl;
}