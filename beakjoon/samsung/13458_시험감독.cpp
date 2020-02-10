#include <iostream>

using namespace std;

int N;
int room[1000000];
int B, C;
long long ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> room[i];
	cin >> B >> C;

	ans = N;
	
	for (int i = 0; i < N; i++){
		int num = room[i] - B;
		if (num > 0){
			ans += num / C;
			if (num % C)
				ans++;
		}
	}
	cout << ans;

	return 0;
}
