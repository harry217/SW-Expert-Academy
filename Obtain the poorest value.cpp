// 1일차 - 최빈수 구하기 D2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include<algorithm>
#include <stdio.h>
#include<iostream>
using namespace std;

​int com;
int score[100] = { 0, };
int back[100] = { 0, };
int t;
int num;

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &num);
		for (int j = 0; j < 1000; ++j) {
			scanf("%d", &com);
			++score[com];
		}
		for (int i = 0; i < 100; ++i)
			back[i] = score[i];
		//오름차순정렬
		sort(score, score + 99, greater<int>());
		for (int i = 100; i >= 0; --i) {
			if (back[i] == score[0]) { // 가장 많은 점수 숫자인 score[0]에 해당하는 점수 가져옴
				printf("#%d %d\n", num, i);
				break;
			}
		}
		for (int j = 0; j < 100; ++j) {
			score[j] = 0;
		}
	}
	return 0;
}


