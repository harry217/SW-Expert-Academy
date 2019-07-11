// 2일차 - Sum D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int map[100][100];
int num, ret;
int sum[201] = { 0, };

void check() {
	for (int y = 0; y<100; ++y) {
		for (int x = 0; x<100; ++x) {
			sum[y] += map[y][x];
		}
	}
	for (int x = 0; x<100; ++x) {
		for (int y = 0; y<100; ++y) {
			sum[x + 100] += map[y][x];
		}
	}
	for (int y = 0; y<100; ++y) {
		for (int x = 0; x<100; ++x) {
			if (y == x)
				sum[200] += map[x][y];
			if (100 - y == x)
				sum[201] += map[x][y];
		}
	}
}

int main() {
	for (int i = 0; i<10; ++i) {
		scanf("%d", &num);
		for (int y = 0; y<100; ++y) {
			for (int x = 0; x<100; ++x) {
				scanf("%d", &map[y][x]);
			}
		}
		check();
		sort(sum, sum + 202, greater<int>());
		ret = sum[0];
		printf("#%d %d\n", num, ret);
		for (int j = 0; j<202; ++j)
			sum[j] = 0;
	}
	return 0;
}


