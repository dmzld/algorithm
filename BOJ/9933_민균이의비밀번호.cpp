#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> list;

void solution(int s, int e, string r_pass){
	
	if (s > e)
		return;
	int m = (s + e) / 2;
	if (list[m]==r_pass){
		cout << r_pass.length() << " " << r_pass.at(r_pass.length() / 2);
		exit(0);
	}
	else if (list[m] < r_pass){
		solution(m + 1, e, r_pass);
	}
	else{
		solution(s, m - 1, r_pass);
	}
}

int main(){	
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	list.resize(N);
	for (int i = 0; i < N; i++){
		cin >> list[i];
	}
	sort(list.begin(), list.end());

	for (int i = 0; i < N; i++){
		string r_str = list[i];
		reverse(r_str.begin(), r_str.end());
		solution(0, N - 1, r_str);
	}

	return 0;
}
