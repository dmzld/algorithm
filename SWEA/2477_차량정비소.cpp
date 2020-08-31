#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
int N, M, K, A, B;
int ta[11], tb[11], tt[1001];
int res[1001][2]; // i th customer use what number of a & b
bool check[1001];

bool testOver(){
	for (int i = 1; i <= K; i++)
		if (!check[i])
			return false;

	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		pair<int, int> a[11]; // <num, time>
		int b[11] = { 0, }; // time
		int time = -1, ans = 0;
		queue<int> aw, bw; // set of waiting people of a, b
		memset(check, false, sizeof(check));

		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++)
			cin >> ta[i];
		for (int i = 1; i <= M; i++)
			cin >> tb[i];
		for (int i = 1; i <= K; i++)
			cin >> tt[i];

		while (!testOver()){

			// setting by time
			time++;
			//cout << "time : " << time << "\n";

			for (int i = 1; i <= N; i++)
				if (a[i].second > 0){
					a[i].second--;
					if (a[i].second == 0){
						//cout << a[i].first << " cutomer go repair wait\n";
						bw.push(a[i].first); // customer in reception go to repair wait
					}
				}

			for (int i = 1; i <= M; i++)
				if (b[i] > 0)
					b[i]--;
			
			// arrive acception
			for (int i = 1; i <= K; i++)
				if (tt[i] == time){
					aw.push(i);
					//cout << i << " cutomer arrive\n";
				}

			// take acception
			if (!aw.empty()){
				for (int i = 1; i <= N; i++){
					if (a[i].second == 0){ // if there is empty acception
						a[i] = { aw.front(), ta[i] }; // waiting customer takes acception

						//cout << aw.front() << " customer take acception\n";
						res[aw.front()][0] = i; // save usage history
						aw.pop();
					}

					if (aw.empty()) break;
				}
					
			}

			// take repair
			if (!bw.empty()){
				for (int i = 1; i <= M; i++){
					if (b[i] == 0){
						b[i] = tb[i];

						//cout << bw.front() << " complete\n";
						res[bw.front()][1] = i; // save usage history
						check[bw.front()] = true;
						bw.pop();
					}
					
					if (bw.empty()) break;
				}
					
			}
		}

		for (int i = 1; i <= K; i++)
			if (res[i][0] == A && res[i][1] == B)
				ans += i;
		if (ans == 0)
			ans = -1;

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
