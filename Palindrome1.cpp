// 3일차 - 회문1 D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

char map[16][8];
char cmp[16][8];
int cnt;

int main() {
	for (int i = 0; i<10; ++i) {
		int len, ret = 0;
		scanf("%d", &len);
		for (int y = 0; y<8; ++y) {
			scanf("%s", &map[y]);
		}
		for (int y = 0; y<8; ++y) {
			for (int x = 0; x<8; ++x) {
				map[8 + x][y] = map[y][x];
			}
		}
		for (int y = 0; y<16; ++y) {
			for (int x = 0; x<8; ++x) {
				cmp[y][x] = map[y][x];
				//printf("map:%d, x:%d, y:%d\n", map[y][x], x, y);
			}
		}
		// 회문 비교
		for (int y = 0; y<16; ++y) {
			for (int x = 0; x <= 8 - len; ++x) {
				cnt = 0;
				for (int z = 0; z<len; ++z) { // 홀수
					if (map[y][x + z] == cmp[y][len - 1 + x - z]) {
						++cnt;
						//printf("$cnt: %d, x:%d, z:%d, len:%d, x+z:%d, len-1+x-z:%d\n", cnt, x, z, len, x+z, len-1+x-z);
					}
				}
				if (cnt == len)
					++ret;
			}
		}
		//printf("#%d %d, len:%d\n", i+1, ret, len);
		printf("#%d %d\n", i + 1, ret);
		ret = 0;
	}
	return 0;
}