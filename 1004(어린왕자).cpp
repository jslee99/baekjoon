#include<iostream>
#include<cmath>

using namespace std;
int T;

int main(void){
	cin >> T;
	while (T--) {
		int start_x, start_y, end_x, end_y;
		int n;
		int cnt = 0;

		cin >> start_x >> start_y >> end_x >> end_y;		
		cin >> n;

		while (n--) {
			int cent_x, cent_y, r;
			cin >> cent_x >> cent_y >> r;
			bool start_is_in, end_is_in;

			start_is_in = (pow(r, 2) > (pow(start_x - cent_x, 2) + pow(start_y - cent_y, 2)));
			end_is_in = (pow(r, 2) > (pow(end_x - cent_x, 2) + pow(end_y - cent_y, 2)));
			if (start_is_in != end_is_in) cnt++;
			
		}
		cout << cnt << endl;
	}

}
