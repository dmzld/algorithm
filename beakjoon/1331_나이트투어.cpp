#include <iostream>
#include <cmath>

using namespace std;

int sy, sx, y, x, cy, cx;
char tmp;
bool map[7][7] = { false, }; // 1 ~ 6

int main(){

	cin >> tmp >> y;
	x = tmp - 'A' + 1;
	sy = y, sx = x;
	map[sy][sx] = true;

	for (int i = 1; i < 36; i++){
		cin >> tmp >> cy;
		cx = tmp - 'A' + 1;

		if ((pow((cy - y), 2) + pow((cx - x), 2) != 5) || map[cy][cx]){
			cout << "Invalid\n";
			return 0;
		}
		map[cy][cx] = true;
		y = cy, x = cx;
	}

	if ((pow((sy - y), 2) + pow((sx - x), 2) != 5)){
		cout << "Invalid\n";
		return 0;
	}
	for (int i = 1; i <= 6; i++){
		for (int j = 1; j <= 6; j++){
			if (!map[i][j]){
				cout << "Invalid\n";
				return 0;
			}
		}
	}

	cout << "Valid\n";

	return 0;
}
