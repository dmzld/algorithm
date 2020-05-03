#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int num[10];
int map[4][30] = { // [route][score for pos]
	{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, },
	{ 0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40, }, // branch from 10
	{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40, }, // branch from 20
	{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40, } // branch from 30
};

bool check[4][30] = { false, };

struct State{
	int route = 0;
	int pos = 0;
	bool arrive = false;
	int score = 0;
};
State horse[4];

int ans = 0;


int getNextRoute(int i, int n){
	if (horse[i].route == 0){ // branch can be occured when route is 0
		if (map[horse[i].route][horse[i].pos + num[n]] == 10)
			return 1;
		else if (map[horse[i].route][horse[i].pos + num[n]] == 20)
			return 2;
		else if (map[horse[i].route][horse[i].pos + num[n]] == 30)
			return 3;
	}
	
	return horse[i].route; // no change then return own route
}

bool checkDup(int i, int n){
	// next position
	int r = getNextRoute(i, n);
	int pos = horse[i].pos + num[n];

	// normal case
	if (check[r][pos]) return true;

	// special case : different route but duplicated space
	// map[1][9 ~ 11] == map[2][13 ~ 15] == map[3][19 ~ 21]
	// map[0][20] == map[1][12] == map[2][16] == map[3][22]
	if (r == 0 && pos == 20){
		if (check[1][12] || check[2][16] || check[3][22]) return true;
	}
	else if (r == 1 && pos >= 9 && pos <= 12){
		if (check[2][pos + 4] || check[3][pos + 10] || (pos == 12 && check[0][20])) return true;
	}
	else if (r == 2 && pos >= 13 && pos <= 16){
		if (check[1][pos - 4] || check[3][pos + 6] || (pos == 16 && check[0][20])) return true;
	}
	else if (r == 3 && pos >= 19 && pos <= 22){
		if (check[1][pos - 10] || check[2][pos - 6] || (pos == 22 && check[0][20])) return true;
	}

	return false; // not dup
}

void solution(int n){ // dfs

	if (n >= 10){ // game over
		ans = max(ans, horse[0].score + horse[1].score + horse[2].score + horse[3].score);
		return;
	}

	for (int i = 0; i < 4; i++){
		if (!horse[i].arrive && !checkDup(i, n)){ // not arrive && there is no horse in next space
			// save state
			State tmp = horse[i];

			// update data
			check[horse[i].route][horse[i].pos] = false;
			horse[i].route = getNextRoute(i, n); 
			horse[i].pos += num[n];

			// check whether arriving or not
			if (map[horse[i].route][horse[i].pos] == 0){
				horse[i].arrive = true;
			}
			else{
				check[horse[i].route][horse[i].pos] = true;
				horse[i].score += map[horse[i].route][horse[i].pos];
			}

			// next step
			solution(n + 1);

			// rollback
			check[horse[i].route][horse[i].pos] = false;
			horse[i] = tmp;
			check[horse[i].route][horse[i].pos] = true;
		}
	}
}

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++)
		cin >> num[i];

	solution(0);

	cout << ans;

	return 0;
}
