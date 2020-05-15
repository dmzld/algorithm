#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<string> nohear;
string nosee;
vector<string> nohs;

bool binSear(int s, int e, string name){
	if (s > e)
		return false;
	else{
		int mid = (s + e) / 2;

		if (!nohear[mid].compare(name))
//		if (nohear[mid] == name)
			return true;
		else if (nohear[mid] < name)
			return binSear(mid + 1, e, name);
		else
			return binSear(s, mid - 1, name);
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;

	nohear.resize(N);
	for (int i = 0; i < N; i++){
		cin >> nohear[i];
	}
	sort(nohear.begin(), nohear.end());

	for (int i = 0; i < M; i++){
		cin >> nosee;
		if (binSear(0, N - 1, nosee)) {
			nohs.push_back(nosee);
		}
	}
	sort(nohs.begin(), nohs.end());

	cout << nohs.size() << "\n";
	for (int i = 0; i < nohs.size(); i++)
		cout << nohs[i] << "\n";
	return 0;
}
