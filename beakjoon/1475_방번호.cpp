#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	int num[10] = { 0, }; // 0~9
	int ans = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	if (N == 0)
		num[0]++;
	else{
		while (N > 0){
			num[N % 10]++;
			N /= 10;
		}
	}

	if ((num[6] + num[9]) % 2 == 1)
		num[6] = (num[6] + num[9]) / 2 + 1;
	else
		num[6] = (num[6] + num[9]) / 2;
		
	for (int i = 0; i < 9; i++) // 6 == 9
		if (ans < num[i])
			ans = num[i];
		

	cout << ans;
	return 0;
}
