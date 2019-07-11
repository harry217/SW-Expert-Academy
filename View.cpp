// 1일차 - View D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int line;
int apt[1000];
int test[4];

void count(int line, int num) {
	int ret = 0;
	for (int i = 2; i<line - 2; ++i) {
		for (int j = 0; j<5; ++j) {
			test[j] = apt[i - 2 + j];
		}
		sort(test, test + 5, greater<int>()); // 배열 0부터 시작하더라도 5개 개수 배열이라면 5를 더 해줄것!
		if (apt[i] == test[0]) {
			ret += test[0] - test[1];
			//printf("$%d\n", test[0] - test[1]);
			//printf("@%d, %d, %d\n", ret, i, apt[i]);
		}
	}
	printf("#%d %d\n", num, ret);
}
int main() {
	for (int i = 0; i<10; ++i) {
		scanf("%d", &line);
		for (int j = 0; j<line; ++j) {
			scanf("%d", &apt[j]);
		}
		count(line, i + 1);
	}
	return 0;
}


