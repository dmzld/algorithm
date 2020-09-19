#include <iostream>
#include <algorithm>

using namespace std;

int T;
int map[100], N, ans;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int t = 1; t <= 10; t++){
		cin >> N;
		for (int i = 0; i < 100; i++)
			cin >> map[i];

		// time complexity == 1000 * 100 * log(100)
		for (int i = 0; i < N; i++) { // N <= 1000
			sort(map, map + 100); // O(nlogn) => 100 * log(100)
			map[99]--;
			map[0]++;
		}
		sort(map, map + 100);
		cout << "#" << t << " " << map[99] - map[0] << "\n";
	}


	return 0;
}
