#include <iostream>
#include <string>

using namespace std;

int N, K; // 단어 개수, 알려줄 글자 수
// anta, tica => a,c,t,n,i :  5
string str[50];
bool teach[26] = { false, };
int ans = 0;

void counting(){
	int res = 0;
	for (int i = 0; i < N; i++){
		bool flag = true;

		for (int j = 0; j < str[i].length(); j++){
			if (!teach[str[i][j] - 'a']){
				flag = false;
				break;
			}
		}

		if (flag)
			res++;
	}
	if (ans < res)
		ans = res;
}

void teaching(int idx, int cnt){
	if (cnt == K){
		counting();
		return;
	}

	for (int i = idx; i < 26; i++){
		if (!teach[i]){
			teach[i] = true;
			teaching(i + 1, cnt + 1);
			teach[i] = false;
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++){
		cin >> str[i];
		str[i] = str[i].substr(4, (str[i].length() - 8));
	}

	if (K < 5){
		cout << "0\n";
		return 0;
	}

	K -= 5;
	teach['a' - 'a'] = true;
	teach['c' - 'a'] = true;
	teach['t' - 'a'] = true;
	teach['n' - 'a'] = true;
	teach['i' - 'a'] = true;

	teaching(0, 0);

	cout << ans;
	
	return 0;
}
