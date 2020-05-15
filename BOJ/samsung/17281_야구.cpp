#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N; // 이닝
int inning[51][10];
int order[10]; // [순번] = player
int selected[10] = { false, }; // [player]의 순서가 정해졌는지
int res = 0;

void playing(){
	int fin_score = 0;
	int start_order = 1;

	// 각 이닝에서
	for (int i = 1; i <= N; i++){
		int score = 0;
		int out = 0;
		bool runner[4] = { false, };

		// 3진아웃 될 때까지
		while (out < 3){
			
			// 로테이션을 돌린다
			for (int j = start_order; j < 10; j++){
				int run = 0;
				// out
				if (inning[i][order[j]] == 0){
					out++;
				}
				// 1,2,3,4루타
				else {
					runner[0] = true;
					run = inning[i][order[j]];
					for (int k = 3; k >= 0; k--){
						if (runner[k]){ // 타자가 있으면 주루한다
							if (k + run > 3){
								runner[k] = false;
								score++;
							}
							else{
								runner[k] = false;
								runner[k + run] = true;
							}
						}
					}
				}
				// 삼진 아웃이면 다음 시작 선수 저장 후 이닝 종료
				if (out == 3){
					start_order = j + 1;
					for (int i = 0; i < 4; i++)
						runner[i] = false;
					break;
				}
			}
			// 아직 삼진 아웃을 안당한채 로테이션이 끝나면 start palyer는 1번 선수
			if (out < 3)
				start_order = 1;
		}
		// 각 이닝에서의 점수 더하기
		fin_score += score;
	}
	if (res < fin_score){
		res = fin_score;
	}
		
}

void ordering(int cnt){
	if (cnt == 10){ // 9번까지 순서 정해지면 playing
		playing();
	}
	if (cnt == 4) // 4번타자는 언제나 1번 player
		ordering(cnt + 1);
	else{
		for (int i = 1; i < 10; i++){ //  1 ~ 9 player 중
			if (!selected[i]){ // i player가 순서가 정해지지 않았으면
				order[cnt] = i; // cnt 순번은 i player
				selected[i] = true; // i player 순서가 정해짐을 표시
				ordering(cnt + 1); // cnt + 1 순번을 정한다.
				selected[i] = false;
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++){ // 1 ~ N inning
		for (int j = 1; j <= 9; j++){ // 1 ~ 9 player
			int tmp;
			cin >> tmp;
			inning[i][j] = tmp;
		}
	}

	order[4] = 1; // 4번타자는 1번선수
	selected[1] = true; // 1번선수는 순서가 정해짐
	ordering(1); // 1번 순서부터 ordering

	cout << res;

	return 0;
}
