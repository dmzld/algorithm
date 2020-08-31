#include <iostream>

using namespace std;

int T;
int N, map[20][20];
pair<int, int> dir[4] = { { 1, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 } }; // counter clock
int dirCnt[4]; // must be [0] == [2], [1] == [3], but [2][3] is not used
bool num[101] = { false, };
int ans;

void validation(int y, int x){
	bool rec = true;
	bool nnum[101] = { false, };
	for (int i = 0; i <= 100; i++)
		nnum[i] = num[i];

	int ny = y, nx = x;
	for (int i = 0; i < dirCnt[0]; i++){
		ny += dir[2].first, nx += dir[2].second;
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || nnum[map[ny][nx]]){
			rec = false;
			break;
		}
		nnum[map[ny][nx]] = true;
	}

	if (!rec) return;

	for (int i = 0; i < dirCnt[1] - 1; i++){
		ny += dir[3].first, nx += dir[3].second;
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || nnum[map[ny][nx]]){
			rec = false;
			break;
		}
		nnum[map[ny][nx]] = true;
	}

	if (rec){
		if (ans < (dirCnt[0] + dirCnt[1]) * 2)
			ans = (dirCnt[0] + dirCnt[1]) * 2;
	}
	return;
}

void solution(int y, int x){
	int ny = y + dir[1].first, nx = x + dir[1].second;
	dirCnt[1]++;
	while (ny >= 0 && ny < N && nx >= 0 && nx < N && !num[map[ny][nx]]){
		num[map[ny][nx]] = true;

		validation(ny, nx); // make rectangular

		ny += dir[1].first, nx += dir[1].second;
		dirCnt[1]++;
	}

	// init
	dirCnt[1] = 0;

	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		ans = -1;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				bool cnum[101] = { false, };
				cnum[map[i][j]] = true;

				int ny = i + dir[0].first, nx = j + dir[0].second;
				dirCnt[0]++;
				while (ny >= 0 && ny < N && nx >= 0 && nx < N && !cnum[map[ny][nx]]){
					cnum[map[ny][nx]] = true;
					for (int n = 1; n <= 100; n++)
						num[n] = cnum[n];

					solution(ny, nx);

					ny += dir[0].first, nx += dir[0].second;
					dirCnt[0]++;
				}

				// init
				dirCnt[0] = 0;
			}
		
		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}
