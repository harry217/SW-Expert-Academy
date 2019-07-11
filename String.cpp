// 3일차 - String D3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

char sen[1000];
char src[10];
int num, ret;
int cnt;

int main() {
	for (int i = 0; i<10; ++i) {
		cnt = 0;
		scanf("%d", &num);
		scanf("%s", &src);
		scanf("%s", &sen);
		/*
		for(int j=0;j<10;++j){
		if(src[j] != 0){
		++cnt;
		}else
		break;
		}*/
		int j = 0;
		while (src[j++]);
		cnt = j - 1;
		//printf("cnt : %d\n", cnt);
		/*
		for(int j=0;j<1000;++j){
		if(src[0] == sen[j] && j+cnt<1000){
		for(int c=0;c<cnt;++c){
		if(src[c] != sen[c])
		break;
		else if(c == cnt -1)
		++ret;
		}
		}
		}*/
		j = 0;
		while (sen[j++]) {
			if (src[0] == sen[j] && j + cnt<1000) {
				for (int c = 0; c<cnt; ++c) {
					if (src[c] != sen[j + c])
						break;
					else if (c == cnt - 1)
						++ret;
				}
			}
		}
		printf("#%d %d\n", num, ret);
		ret = 0;
	}
	return 0;
}