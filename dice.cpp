// dice.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>               
#include<algorithm>               
using namespace std;
#pragma warning (disable: 4996)

int N, M, sy, sx, K; // ���� ����, ���� ����, ������ ��ǥ, ��� ��
int MAP[20][20]; // ��
int DICE[6]; // ���� �ֻ��� ��

const int dx[] = { +1, -1, 0, 0 }; // �� �� �� ��
const int dy[] = { 0, 0, -1, +1 };

void move_dice(int k) {
	int nDICE[6]; // ���� �ֻ���

	switch (k)
	{
		case 0: // ��
			nDICE[0] = DICE[0];
			nDICE[5] = DICE[1];
			nDICE[2] = DICE[2];
			nDICE[4] = DICE[3];
			nDICE[1] = DICE[4];
			nDICE[3] = DICE[5];
			break;
		case 1: // ��
			nDICE[0] = DICE[0];
			nDICE[4] = DICE[1];
			nDICE[2] = DICE[2];
			nDICE[5] = DICE[3];
			nDICE[3] = DICE[4];
			nDICE[1] = DICE[5];
			break;
		case 2: // ��
			nDICE[3] = DICE[0];
			nDICE[0] = DICE[1];
			nDICE[1] = DICE[2];
			nDICE[2] = DICE[3];
			nDICE[4] = DICE[4];
			nDICE[5] = DICE[5];
			break;
		case 3: // ��
			nDICE[1] = DICE[0];
			nDICE[2] = DICE[1];
			nDICE[3] = DICE[2];
			nDICE[0] = DICE[3];
			nDICE[4] = DICE[4];
			nDICE[5] = DICE[5];
			break;
		default:
			break;
	}
	for(int i=0;i<6;++i)
		DICE[i] = nDICE[i];
}

int main() {
	scanf("%d %d %d %d %d", &N, &M, &sy, &sx, &K);
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x)
			scanf("%d", &MAP[y][x]);
	}

	// dice		
	int dir;
	for (int i = 0; i < K; ++i) {
		scanf("%d", &dir);
		--dir;
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];

		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {

			move_dice(dir);

			if (MAP[ny][nx] == 0)
				MAP[ny][nx] = DICE[3];
			else {
				DICE[3] = MAP[ny][nx];
				MAP[ny][nx] = 0;
			}
			sy = ny;
			sx = nx;
			printf("%d\n", DICE[1]); // ǥ��
		}
	}


	return 0;
}