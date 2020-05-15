#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M;
int map[8][8];
int check[8][8] = { false, };
stack<pair<int, int>> s;

vector <pair<int, int>> tv; // cctv (y, x)
pair<int, int> dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int cantSee = 0, ans = 987654321;

int detect(int y, int x, int dirIdx){
	int cnt = 0;
	while (map[y][x] != 6 && y >= 0 && y < N && x >= 0 && x < M){
		if (!check[y][x]){
			check[y][x] = true;
			s.push({ y, x });
			cnt++;
		}
		y += dir[dirIdx].first;
		x += dir[dirIdx].second;
	}
	return cnt;
}

void goBack(int cnt){
	for (int i = 0; i < cnt; i++){
		int y = s.top().first;
		int x = s.top().second;
		s.pop();
		check[y][x] = false;
	}
}

void solution(int idx){
	if (idx >= tv.size()){

		if (ans > cantSee - s.size())
			ans = cantSee - s.size();
		return;
	}

	switch (map[tv[idx].first][tv[idx].second]){
	case 1:
		for (int i = 0; i < 4; i++){
			int cnt = 0;
			
			// detect 1 dir
			int y = tv[idx].first + dir[i].first, x = tv[idx].second + dir[i].second;
			cnt += detect(y, x, i);
			
			// next cctv
			solution(idx + 1);

			// get back check state
			goBack(cnt);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++){
			int cnt = 0;

			// detect oppsite 2 dir 
			int y = tv[idx].first + dir[i].first, x = tv[idx].second + dir[i].second;
			cnt += detect(y, x, i);

			y = tv[idx].first + dir[i + 2].first, x = tv[idx].second + dir[i + 2].second;
			cnt += detect(y, x, i + 2);

			// next cctv
			solution(idx + 1);

			// get back check state
			goBack(cnt);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++){
			int cnt = 0;

			// detect adjacent 2 dir 
			int y = tv[idx].first + dir[i].first, x = tv[idx].second + dir[i].second;
			cnt += detect(y, x, i);

			y = tv[idx].first + dir[(i + 1) % 4].first, x = tv[idx].second + dir[(i + 1) % 4].second;
			cnt += detect(y, x, (i + 1) % 4);

			// next cctv
			solution(idx + 1);

			// get back check state
			goBack(cnt);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++){
			int cnt = 0;

			// detect 3 dir 
			int y = tv[idx].first + dir[i].first, x = tv[idx].second + dir[i].second;
			cnt += detect(y, x, i);

			y = tv[idx].first + dir[(i + 1) % 4].first, x = tv[idx].second + dir[(i + 1) % 4].second;
			cnt += detect(y, x, (i + 1) % 4);

			y = tv[idx].first + dir[(i + 2) % 4].first, x = tv[idx].second + dir[(i + 2) % 4].second;
			cnt += detect(y, x, (i + 2) % 4);

			// next cctv
			solution(idx + 1);

			// get back check state
			goBack(cnt);
		}
		break;
	case 5:
		int cnt = 0;

		// detect all dir 
		int y = tv[idx].first + dir[0].first, x = tv[idx].second + dir[0].second;
		cnt += detect(y, x, 0);
		y = tv[idx].first + dir[1].first, x = tv[idx].second + dir[1].second;
		cnt += detect(y, x, 1);
		y = tv[idx].first + dir[2].first, x = tv[idx].second + dir[2].second;
		cnt += detect(y, x, 2);
		y = tv[idx].first + dir[3].first, x = tv[idx].second + dir[3].second;
		cnt += detect(y, x, 3);
		// next cctv
		solution(idx + 1);

		// get back check state
		goBack(cnt);

		break;
	}
	
}

int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j]>0 && map[i][j] < 6){
				check[i][j] = true;
				tv.push_back({ i, j });
			}
			if (map[i][j] == 0)
				cantSee++;
		}
	}

	solution(0);

	cout << ans;
	return 0;
}
