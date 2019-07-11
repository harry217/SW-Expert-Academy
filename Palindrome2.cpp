// 3일차 - 회문2 D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

char map[200][100];
int ret[100] = { 0, };
int mx = 0;
int cnt = 0;

int main() {
	int num = 0;
	mx = cnt;
	for (int i = 0; i<10; ++i) {
		scanf("%d", &num);
		for (int y = 0; y<100; ++y) {
			scanf("%s", &map[y]);
		}
		for (int y = 0; y<100; ++y) {
			for (int x = 0; x<100; ++x) {
				map[100 + x][y] = map[y][x];
			}
		}
		//int k=0;
		for (int y = 0; y<200; ++y) {
			for (int x = 0; x<100; ++x) {
				for (int z = x; z<100; ++z) {
					if (map[y][x] == map[y][z]) { // 같은 걸 찾는다
						for (int c = 0; c <= z - x; ++c) {
							if (map[y][x + c] == map[y][z - c]) {
								++cnt;
								//printf("map:%d, x:%d, y:%d, z:%d, c:%d\n", map[y][x], x, y, z, c);
								//printf("$cnt: x:%d, z:%d, c:%d, x+c:%d, 100-z-c:%d\n", x, z, c, x+c, 100-z-c);
							}
							else
								break;
						}
						if (cnt != 2) {
							if (cnt > mx)
								mx = cnt;
						}
						cnt = 0;
					}
				}
			}
		}
		printf("#%d %d\n", num, mx);
		mx = 0;
	}
	return 0;
}