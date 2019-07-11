#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[7] = { 0, };

void pw() {
	//printf("%d %d %d %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
	while (true) {
		bool flag = false;
		for (int i = 1; i <= 5; ++i) {
			int temp = arr[0];
			for (int j = 0; j<7; ++j)
				arr[j] = arr[j + 1];
			arr[7] = temp;
			int j = arr[7] - i;
			if (j <= 0) {
				arr[7] = 0;
				flag = true;
			}
			else {
				arr[7] = j;
			}
			if (flag) break;
		}
		if (flag) break;
	}
}

int main() {
	for (int i = 0; i<10; ++i) {
		int t;
		scanf("%d", &t);
		for (int j = 0; j<8; ++j)
			scanf("%d", &arr[j]);
		pw();
		printf("#%d %d %d %d %d %d %d %d %d\n", t, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7]);
	}
	return 0;
}
