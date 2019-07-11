// 4일차 - Stack1 D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;
int num, ret;

void mul(int ret, int m, int num) {
	if (m>1) {
		ret = ret*n;
		--m;
		//printf("ret:%d\n", ret);
		mul(ret, m, num);
	}
	else
		printf("#%d %d\n", num, ret);
}

int main() {
	for (int i = 0; i<10; ++i) {
		scanf("%d", &num);
		scanf("%d%d", &n, &m);
		ret = n;
		mul(ret, m, num);
		//printf("#%d %d\n", num, ret);
	}
	return 0;
}
