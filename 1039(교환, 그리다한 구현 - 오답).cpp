#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int N, K;
bool been_perfect = false;
bool same_exist;

bool is_perfect(string str, int str_size) {
	bool flag = true;
	for (int i = 0; i < str_size - 1; i++) {
		if (str[i] < str[i + 1]) {
			flag = false;
		}
	}

	return flag;
}

bool is_same_exist(string str, int str_size) {
	bool flag = false;
	for (int i = 0; i < str_size; i++) {
		for (int j = 0; j < str_size; j++) {
			if (i == j) continue;

			if (str[i] == str[j]) {
				flag = true;
			}
		}
	}

	return flag;
}

int ret_pivot_idx(string str, string perfect_str, int str_size) {
	for (int i = 0; i < str_size; i++) {
		if (str[i] != perfect_str[i])
			return i;
	}
	return -1;
}



int main(void) {
	cin >> N >> K;
	string str = to_string(N);
	//str.size() : 1   2
	int str_size = (int)str.size();

	if (str_size == 1) {
		cout << -1 << endl;
		return 0;
	}
	else if (str_size == 2) {
		bool flag = false;
		for (int i = 0; i < str_size; i++) {
			if (str[i] == '0') flag = true;
		}

		if (flag) {
			cout << -1 << endl;
		}
		else {
			if (K % 2 == 1) {
				swap(str[0], str[str_size - 1]);
				cout << str << endl;
			}
			else {
				cout << str << endl;
			}
		}
		return 0;
	}
	else {
		/*
		int locked_idx = -1;
		for (int swap_cnt = 0; swap_cnt < K; swap_cnt++) {
			if (locked_idx + 3 == str_size) {
				swap(str[str_size - 2], str[str_size - 1]);
			}
			else {
				int max_idx = locked_idx + 1;
				for (int i = max_idx + 1; i < str_size; i++) {
					if (str[max_idx] <= str[i]) {
						max_idx = i;
					}
				}

				if (max_idx == locked_idx + 1 || str[max_idx] == str[locked_idx + 1]) {
					swap_cnt--;
					locked_idx++;
				}
				else {
					swap(str[locked_idx + 1], str[max_idx]);
					locked_idx++;
				}
			}
			
		}*/

		string perfect_str = str;
		sort(perfect_str.begin(), perfect_str.end(), greater<int>());

		same_exist = is_same_exist(str, str_size);

		been_perfect = is_perfect(str, str_size);
		for (int swap_cnt = 0; swap_cnt < K; swap_cnt++) {
			if (been_perfect) {
				if (same_exist) {

				}
				else {
					swap(str[str_size - 2], str[str_size - 1]);
				}
			}
			else {
				int pivot_idx = ret_pivot_idx(str, perfect_str, str_size);

				int max_idx = pivot_idx;
				for (int i = pivot_idx; i < str_size; i++) {
					if (str[max_idx] <= str[i]) {
						max_idx = i;
					}
				}
				swap(str[max_idx], str[pivot_idx]);

				been_perfect = is_perfect(str, str_size);
			}
		}


		cout << str << endl;
		return 0;
	}

	return 0;
}