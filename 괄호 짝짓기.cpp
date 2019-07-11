// 4일차 - 괄호 짝짓기 D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int ret;
char j;
int n[8] = { 0, }; // ( : 0, ) : 1, [ : 2, ] : 3, { : 4, } : 5, < : 6, > : 7
int l;

int main() {
	for (int i = 0; i<10; ++i) {
		scanf("%d", &l);
		for (int k = 0; k <= l; ++k) {
			scanf("%c", &j); // 가로 문자는 캐릭터
			if (j == '(')
				++n[0];
			else if (j == ')')
				++n[1];
			else if (j == '[')
				++n[2];
			else if (j == ']')
				++n[3];
			else if (j == '{')
				++n[4];
			else if (j == '}')
				++n[5];
			else if (j == '<')
				++n[6];
			else if (j == '>')
				++n[7];
			/*else
			printf("k:%d\n", k); // 0, 1?*/
		}
		//printf("l:%d\n", l);
		//printf("t:%d, 0:%d 1:%d 2:%d 3:%d 4:%d 5:%d 6:%d 7:%d\n", n[0]+n[1]+n[2]+n[3]+n[4]+n[5]+n[6]+n[7], n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7]);
		if (n[0] == n[1] && n[2] == n[3] && n[4] == n[5] && n[6] == n[7])
			ret = true;
		else
			ret = false;
		printf("#%d %d\n", i + 1, ret);
		for (int k = 0; k<8; ++k)
			n[k] = 0;
	}
	return 0;
}
