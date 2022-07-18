#include<stdio.h>
#include<stdlib.h>

int n;
int s, e;
int res;

struct line {
	int start;
	int end;
};

struct line lines[1000000];

int compare(const void* a, const void* b) {
	return (*(struct line*)a).start - (*(struct line*)b).start;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &lines[i].start, &lines[i].end);	
	}

	qsort(lines, n, sizeof(struct line), compare);
	int check = lines[0].end;
	res = lines[0].end - lines[0].start;
	for (int i = 1; i < n; i++) {
		if (lines[i].end <= check) {
			continue;
		}

		if (lines[i].start > check) {
			res += lines[i].end - lines[i].start;
			check = lines[i].end;
		}
		else {
			res += lines[i].end - check;
			check = lines[i].end;
		}
	}

	printf("%d", res);
	return 0;
}
