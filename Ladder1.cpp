// 2일차 - Ladder1 D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int num;
int map[100][100];
int ret;
int a, b;
int dy[] = { 0, 0, -1 }; // 좌, 우, 위, 아래
int dx[] = { -1, 1, 0 };

void moveLEFTward(int y, int x) {
	while (y>0) {
		if (map[y + dy[0]][x + dx[0]] == 1 && x + dx[0] >= 0) {
			y += dy[0];
			x += dx[0];
		}
		else {
			y += dy[2];
			x += dx[2];
			b = y;
			a = x;
			break;
		}
	}
}

void moveRIGHTward(int y, int x) {
	while (y>0) {
		if (map[y + dy[1]][x + dx[1]] == 1 && x + dx[1] <= 99) {
			y += dy[1];
			x += dx[1];
		}
		else {
			y += dy[2];
			x += dx[2];
			b = y;
			a = x;
			break;
		}
	}
}

void moveUPward(int y, int x, int num) {
	while (y>0) {
		if (map[y + dy[0]][x + dx[0]] == 1 && x + dx[0] >= 0) {
			// 이 위치에 if문이면 쉬운 문제이나 굳이 for문 사용하는 바람에...
			y += dy[0];
			x += dx[0];
			moveLEFTward(y, x);
			y = b;
			x = a;
		}
		else if (map[y + dy[1]][x + dx[1]] == 1 && x + dx[1] <= 99) {
			y += dy[1];
			x += dx[1];
			moveRIGHTward(y, x);
			y = b;
			x = a;
		}
		else {
			y += dy[2];
			x += dx[2];
		}
	}
	printf("#%d %d\n", num, x);
}

int main() {
	int a, b;
	for (int i = 0; i<10; ++i) {
		scanf("%d", &num);
		for (int y = 0; y<100; ++y) {
			for (int x = 0; x<100; ++x) {
				scanf("%d", &map[y][x]);
				if (map[y][x] == 2) {
					b = y;
					a = x;
					//printf("start : %d, %d\n", a, b);
				}
			}
		}
		moveUPward(b, a, num);
	}
	return 0;
}
