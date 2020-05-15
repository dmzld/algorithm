#include <iostream>

using namespace std;

int A, B, N, M;
int map[101][101] = { 0, };
struct State{
	int x;
	int y;
	int dir;
};
State robo[101];
// N E S W
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main(){

	cin >> A >> B >> N >> M;
	for (int i = 1; i <= N; i++){
		char dir;
		cin >> robo[i].x >> robo[i].y >> dir;
		if (dir == 'N')
			robo[i].dir = 0;
		else if (dir == 'E')
			robo[i].dir = 1;
		else if (dir == 'S')
			robo[i].dir = 2;
		else if (dir == 'W')
			robo[i].dir = 3;

		map[robo[i].y][robo[i].x] = i;
	}

	for (int i = 0; i < M; i++){
		int num, cnt;
		char order;
		cin >> num >> order >> cnt;

		if (order == 'L'){
			cnt %= 4;
			while (cnt > 0){
				robo[num].dir = (robo[num].dir + 3) % 4;
				cnt--;
			}
		}
		else if (order == 'R'){
			cnt %= 4;
			while (cnt > 0){
				robo[num].dir = (robo[num].dir + 1) % 4;
				cnt--;
			}
		}
		else if (order == 'F'){
			int cy = robo[num].y, cx = robo[num].x;
			while (cnt > 0){
				cy += dy[robo[num].dir], cx += dx[robo[num].dir];
				if (cy<1 || cy>B || cx<1 || cx>A){
					cout << "Robot " << num << " crashes into the wall\n";
					return 0;
				}
				if (map[cy][cx]!=0){
					cout << "Robot " << num << " crashes into robot " << map[cy][cx] << "\n";
					return 0;
				}
				cnt--;
			}
			map[robo[num].y][robo[num].x] = 0;
			map[cy][cx] = num;
			robo[num].y = cy, robo[num].x = cx;
		}
	}

	cout << "OK\n";
	
	return 0;
}
