#include<iostream>
#include<deque>
#include<string>

using namespace std;

int T;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int t = 0; t < T; t++) {
		deque<int> dq;
		string functionlist, liststr;
		int n;

		cin >> functionlist;
		cin >> n;
		cin >> liststr;

		//반복적인 substr은 시간복잡도가 안좋아지게됨 O(n^2)의 시간복잡도 n : str.size()

		/*
		liststr = liststr.substr(1, liststr.size() - 2);
		for (int i = 0; i < n; i++) {
			int pos = liststr.find(",");
			dq.push_back(stoi(liststr.substr(0, pos)));
			liststr = liststr.substr(pos + 1);
		}*/

		string s = "";
		for (int i = 0; i < liststr.size(); i++) {
			if (isdigit(liststr[i])) {
				s += liststr[i];
			}
			else {
				if (!s.empty()) {
					dq.push_back(stoi(s));
					s = "";
				}
			}
		}

		bool rev = false;
		bool is_err = false;

		for (int i = 0; i < functionlist.size(); i++) {
			if (functionlist[i] == 'R') {
				rev = !rev;
			}
			else {
				if (dq.empty()) {
					is_err = true;
					break;
				}

				if (!rev)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		string ans = "[";
		if (is_err) {
			ans = "error";
		}
		else {
			if (dq.empty()) {
				ans = ans + "]";
			}
			else {
				if (!rev) {
					for (int i = 0; i < dq.size(); i++)
						ans += to_string(dq[i]) + ",";
				}
				else {
					for (int i = dq.size() - 1; i >= 0; i--)
						ans += to_string(dq[i]) + ",";
				}
				ans = ans.substr(0, ans.size() - 1);
				ans += "]";
			}
		}

		cout << ans << endl;
	}
}