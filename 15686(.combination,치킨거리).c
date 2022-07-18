#include<stdio.h>
#include<stdlib.h>


int chickens[13][2];
int houses[100][2];
int chic_dist[100][13];//13: tracking minimum chic index
int N;
int M;
int house_num = 0;
int chic_num = 0;
int chic_arr[13];
int res = 987654321;
const int INF = 987654321;

void comb(int cur_sel_num, int idx) {
	if (cur_sel_num < M - 1) {
		//M - cur_sel_num
		//i = idx + 1 ~ chic nums - (M - cur sel num) - 1
		for (int i = idx + 1; i <= chic_num - (M - cur_sel_num); i++) {
			chic_arr[cur_sel_num] = i;
			comb(cur_sel_num + 1, i);
		}
	}
	else {//base case
		for (int i = idx + 1; i < chic_num; i++) {
			chic_arr[cur_sel_num] = i;
			int sum_chic_dist = 0;
			for (int j = 0; j < house_num; j++) {
				int min = INF;
				for (int k = 0; k < M; k++) {
					if (min > chic_dist[j][chic_arr[k]]) {
						min = chic_dist[j][chic_arr[k]];
					}
				}
				sum_chic_dist += min;
			}
			if (res > sum_chic_dist) {
				res = sum_chic_dist;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp == 1) {
				houses[house_num][0] = i, houses[house_num][1] = j;
				house_num++;
			}
			else if (temp == 2) {
				chickens[chic_num][0] = i, chickens[chic_num][1] = j;
				chic_num++;
			}
		}	
	}
	for (int i = 0; i < house_num; i++) {
		for (int j = 0; j < chic_num; j++) {
			chic_dist[i][j] = abs(houses[i][0] - chickens[j][0]) + abs(houses[i][1] - chickens[j][1]);
		}
	}
	comb(0, -1);
	printf("%d\n", res);
}