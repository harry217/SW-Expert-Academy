// 1일차 - Flatten D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int box[100];
int t;
int main() {
	for (int i = 0; i<10; ++i) {
		scanf("%d", &t);
		for (int j = 0; j<100; ++j) {
			scanf("%d", &box[j]);
		}
		for (int j = 0; j<t; ++j) { // dump
			sort(box, box + 100, greater<int>()); // 내림차순 여기다 t를 더해버린 실수를...
												  //printf("high : %d\n", box[0]);
			--box[0];
			sort(box, box + 100); // 올림차순
								  //printf("low : %d\n", box[0]);
			++box[0];
		}
		int high;
		int low;
		sort(box, box + 100, greater<int>());
		high = box[0];
		sort(box, box + 100);
		low = box[0];
		printf("#%d %d\n", i + 1, high - low);
	}
	return 0;
}
