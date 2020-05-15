#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int oddN, num[500000], cnt[8001] = { 0, };
double avg = 0;
int mid = 0, frq = 0, rng = 0;
vector<int> f;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);



	cin >> oddN;
	for (int i = 0; i < oddN; i++){
		cin >> num[i];

		avg += num[i];
		cnt[num[i]+4000]++;
	}
	
	avg = round(((int)((avg / oddN) * 10)) / 10.0);
	
	sort(num, num + oddN);
	mid = num[oddN / 2];

	f.push_back(0);
	for (int i = 1; i <= 8000; i++){
		if (cnt[f[0]] < cnt[i]){
			f.clear();
			f.push_back(i);
		}
		else if (cnt[f[0]] == cnt[i])
			f.push_back(i);
	}
	frq = f.size() == 1 ? f[0] - 4000 : f[1] - 4000;

	rng = num[oddN - 1] - num[0];

	cout << avg << "\n" << mid << "\n" << frq << "\n" << rng;

	return 0;
}
