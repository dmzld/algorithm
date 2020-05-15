#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

int N;
pair<int, int> T[100000];
bool check[100000];
stack<int> s;
int res = 0;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		int s, e;
		cin >> s >> e;
		T[i] = make_pair(e, s); // for sorting by end time, save time form of (end time, start time)
	}

	sort(T, T + N);

	for (int i = 0; i < N; i++)
		cout << T[i].first << " " << T[i].second << "\n";

	// because T is sorted by end time, below algorithm can be utilized
	int e = T[0].first, s = T[0].second;
	res++;
	for (int i = 1; i < N; i++){
		if (T[i].first == e && T[i].second == e)
			res++;
		else if (T[i].second >= e){
			e = T[i].first;
			s = T[i].second;
			res++;
		}
	}

	cout << res;

	return 0;
}
