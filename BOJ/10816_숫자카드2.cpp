#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, C[500000], idx = 0;
long long num;
vector<pair<int, int>> p;

int find(int s, int e){
	if (s > e)
		return 0;
	else{
		int m = (s + e) / 2;
		if (p[m].first == num){
			return p[m].second;
		}
		else if (p[m].first < num)
			return find(m + 1, e);
		else if (p[m].first > num)
			return find(s, m - 1);
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> C[i];
	sort(C, C + N);
	for (int i = 0; i < N; i++){
		int c = C[i],cnt = 0;
		while (c == C[i]){
			cnt++;
			i++;
		} i--;
		p.push_back({ C[i], cnt });
	}

	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> num;

		cout << find(0, p.size() - 1) << " ";
	}
  
  // or use upper,lower bound function of vector

	return 0;
}
