// 2일차 - Ladder2 D4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int num;
int map[100][100];
int ret[100] = { 0, };
int a, b;
int insert[100] = { 0, };
int retbackup[100] = { 0, };
int dy[] = { 0, 0, 1 }; // 좌, 우, 아래
int dx[] = { -1, 1, 0 };

void moveLEFTward(int y, int x, int k) {
	while (y<100) {
		if (map[y + dy[0]][x + dx[0]] == 1 && x + dx[0] >= 0) {
			y += dy[0];
			x += dx[0];
			++ret[k];
		}
		else {
			y += dy[2];
			x += dx[2];
			b = y;
			a = x;
			++ret[k];
			break;
		}
	}
}

void moveRIGHTward(int y, int x, int k) {
	while (y<100) {
		if (map[y + dy[1]][x + dx[1]] == 1 && x + dx[1] <= 99) {
			y += dy[1];
			x += dx[1];
			++ret[k];
		}
		else {
			y += dy[2];
			x += dx[2];
			b = y;
			a = x;
			++ret[k];
			break;
		}
	}
}

void moveDOWNward(int y, int x, int num, int k) {
	while (y<100) {
		if (map[y + dy[0]][x + dx[0]] == 1 && x + dx[0] >= 0) {
			y += dy[0];
			x += dx[0];
			++ret[k];
			moveLEFTward(y, x, k);
			y = b;
			x = a;
		}
		else if (map[y + dy[1]][x + dx[1]] == 1 && x + dx[1] <= 99) {
			y += dy[1];
			x += dx[1];
			++ret[k];
			moveRIGHTward(y, x, k);
			y = b;
			x = a;
		}
		else {
			y += dy[2];
			x += dx[2];
			++ret[k];
		}
	}
	retbackup[k] = ret[k];
	//printf("$%d\n", ret[k]);
}

int main() {
	int j;
	for (int i = 0; i<10; ++i) {
		j = 0;
		scanf("%d", &num);
		for (int y = 0; y<100; ++y) {
			for (int x = 0; x<100; ++x) {
				scanf("%d", &map[y][x]);
				if (y == 0 && map[y][x] == 1) {
					insert[j++] = x;
					//printf("start : %d, %d\n", insert[j-1], b);
				}
			}
		}
		for (int k = 0; k<j; ++k) {
			a = insert[k];
			b = 0;
			//printf("a=%d\n", a);
			moveDOWNward(b, a, num, k);
		}
		sort(ret, ret + j);
		for (int k = 0; k<j; ++k) {
			if (retbackup[k] == ret[0])
				printf("#%d %d\n", num, insert[k]);
		}
		for (int k = 0; k<100; ++k) {
			ret[k] = 0;
			insert[k] = 0;
			retbackup[k] = 0;
		}
	}
	return 0;
}


