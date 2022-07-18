#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
pair<int, int> lecture[200001];

vector<vector<int>> lecture_rooms;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second < b.second)
		return true;
	else if (a.second > b.second)
		return false;
	else
		return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> lecture[i].first >> lecture[i].second;
	}
	lecture[200000] = make_pair(0, 0);//dummy lecture

	sort(lecture, lecture + N, compare);
	/*
5
3 4
1 4
2 3
3 6
2 5

2 3
1 4
3 4
2 5
3 6
sorting testcase
	*/
	lecture_rooms.push_back(vector<int>(1,200000));
	for (int i = 0; i < N; i++) {
		bool new_lecture_room = true;

		for (int j = 0; j < lecture_rooms.size(); j++) {
			if (lecture[lecture_rooms[j].back()].second <= lecture[i].first) {
				lecture_rooms[j].push_back(i);
				new_lecture_room = false;
				break;
			}
		}

		if (new_lecture_room) {
			lecture_rooms.push_back(vector<int>(1, 200000));
			lecture_rooms.back().push_back(i);
		}
	}

	cout << lecture_rooms.size() << endl;
}