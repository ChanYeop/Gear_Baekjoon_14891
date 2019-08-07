#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<pair<int, pair<int, int>>> v;
int arr[9][9] = { 0 };
bool visited[9];

void rotate(int num, int dir) {
	if (dir == 1) {
		int fir = arr[num][7];
		for (int i = 7; i >= 1; i--) {
			arr[num][i] = arr[num][i - 1];
		}
		arr[num][0] = fir;
	}
	else if (dir == -1) {
		int fir = arr[num][0];
		for (int i = 0; i < 7; i++) {
			arr[num][i] = arr[num][i + 1];
		}
		arr[num][7] = fir;
	}
}

void allr(int num,int dir) {
	visited[num] = true;
	int prev_num = num - 1;
	int next_num = num + 1;
	if (next_num < 4 && !visited[next_num]) {
		if (arr[num][2] != arr[next_num][6])
			allr(next_num, dir*-1);
	}
	if (prev_num >= 0 && !visited[prev_num]) {
		if (arr[num][6] != arr[prev_num][2])
			allr(prev_num, dir*-1);
	}
	rotate(num, dir);
}



int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf_s("%1d",&arr[i][j]);
		}
	}
	int K;
	cin >> K;
	int num, dir;
	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		allr(num - 1, dir);
		memset(visited, false, sizeof(visited));
		//rotate(num - 1, dir);
	}

	int answ = 0;
	int score[] = { 1, 2, 4, 8 };
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1)
			answ += score[i];
	}

	cout << answ << endl;
	return 0;
}

