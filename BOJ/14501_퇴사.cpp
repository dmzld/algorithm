#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> T; // ith work time
vector<int> P; // ith work pay
vector<bool> R; // ith work reservation
int res = 0;

void solution(int cnt, int cur_pay){
	if (cnt > N){ // 정산
		if (res < cur_pay)
			res = cur_pay;
		return;
	}
	
	bool canWork = false;
	if (cnt + T[cnt] - 1 <= N && !R[cnt]) // 퇴사 예정일을 넘지 않고 예약이 없는 경우
		canWork = true;

	if (canWork){ // 지금 상태가 T[cnt] 일을 수행할 수 있으면
		for (int i = cnt; i < cnt + T[cnt]; i++) // 예약 표시
			R[i] = true;

		solution(cnt + 1, cur_pay + P[cnt]);
		
		for (int i = cnt; i < cnt + T[cnt]; i++) // 예약 표시 지우기
			R[i] = false;
	}
	solution(cnt + 1, cur_pay);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	T.resize(N + 1);
	P.resize(N + 1);
	R.resize(N + 1, false);
	for (int i = 1; i <= N; i++){
		int time = 0, pay = 0;
		cin >> time >> pay;
		T[i] = time;
		P[i] = pay;
	}

	solution(1, 0); // day : 1 , pay : 0

	cout << res;
	return 0;
}
