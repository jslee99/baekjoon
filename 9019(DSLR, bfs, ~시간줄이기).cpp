#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int T;

string str_to_str(string x) {
	while (x.size() < 4) {
		x.insert(0, "0");
	}
	return x;
}

int func_D(int x, vector<char> &v) {
	x = (x * 2) % 10000;
	v.push_back('D');
	return x;
}

int func_S(int x, vector<char> &v) {
	if (x == 0) {
		x = 9999;
	}
	else {
		x = x - 1;
	}
	v.push_back('S');

	return x;
}

int func_L(int x, vector<char> &v) {
	int a = (x - (x % 1000)) / 1000;
	x = (x * 10) % 10000;
	x = x + a;
	
	v.push_back('L');
	return x;
}

int func_R(int x, vector<char> &v) {
	int a = (x % 10) * 1000;
	x = x / 10;
	x = x + a;
	v.push_back('R');
	return x;
}

int main(void) {
	cin >> T;
	while (T--) {
		int a1, a2;
		bool visited[10000];
		for (int i = 0; i < 10000; i++) visited[i] = false;
		queue<pair<int, string>> q;


		scanf("%d %d", &a1, &a2);

		q.push(make_pair(a1, ""));
		visited[a1] = true;

		while (!q.empty()) {
			pair<int, string> x;
			x = q.front();
			q.pop();
			//if (visited[x.first]) continue;

			//visited[x.first] = true;
			if (x.first == a2) {
				printf("%s", x.second.c_str());
				printf("\n");
				break;
			}

			//4가지 동작
			int y;
			y = (x.first * 2) % 10000;
			if (!visited[y]) {
				visited[y] = true;
				q.push(make_pair(y, x.second + "D"));
			}

			if (x.first == 0) {
				y = 9999;
			}
			else {
				y = x.first - 1;
			}
			if (!visited[y]) {
				visited[y] = true;
				q.push(make_pair(y, x.second + "S"));
			}

			int z = (x.first - x.first % 1000) / 1000;
			y = (x.first % 1000) * 10 + z;
			if (!visited[y]) {
				visited[y] = true;
				q.push(make_pair(y, x.second + "L"));
			}

			z = (x.first % 10) * 1000;
			y = x.first / 10 + z;
			if (!visited[y]) {
				visited[y] = true;
				q.push(make_pair(y, x.second + "R"));
			}
		}

		continue;
	}
	return 0;
}


/*
12
5 0
RD

0 7
SDRDRDRDDSDR

9 0
SDSRSD

47 63
RSDLS

26 60
RSSRR

60 50
RSL

32 38
RSLSSSD

98 366
SRDLSD

5310 6
DRSSR

7519 2006
SDDRS

7579 4005
SRDDSDR

2720 8031
DDRSRDDS


12
5 0
0 7
9 0
47 63
26 60
60 50
32 38
98 366
5310 6
7519 2006
7579 4005
2720 8031

정답
RD
SDRDRDRDDSDR
SDSRSD
RSDLS
RSSRR
RSL
RSLSSSD
SRDLSD
DRSSR
SDDRS
SRDDSDR
DDRSRDDS
*/

// 시간줄이기 : visited를 더 tight하게 관리하여 push할때 visited를 true로 바꿔넣기
// scanf, printf 사용