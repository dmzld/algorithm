#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string eq;
vector<pair<int, int>> couple;
bool except[200] = { false, }; // for eq
stack<int> s;
vector<string> v;

void findEq(int cnt, int idx){
	if (cnt == 0){
		string tmp = "";
		
		for (int i = 0; i < eq.length(); i++){
			if (!except[i])
				tmp += eq[i];
		}

		v.push_back(tmp);

		return;
	}
	for (int i = idx; i < couple.size(); i++){
		except[couple[i].first] = true;
		except[couple[i].second] = true;
		findEq(cnt - 1, i + 1);
		except[couple[i].first] = false;
		except[couple[i].second] = false;
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> eq;
	for (int i = 0; i < eq.length(); i++){
		if (eq[i] == '(')
			s.push(i);
		else if (eq[i] == ')'){
			couple.push_back({ s.top(), i });
			s.pop();
		}
	}

	for (int i = 1; i <= couple.size(); i++) // except couple as many as i
		findEq(i, 0);

	/*
	input : (((1)))(2) => FAIL

	v.erase(unique(v.begin(), v.end()), v.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	*/

	sort(v.begin(), v.end());
	cout << v[0] << "\n";
	for (int i = 1; i < v.size(); i++)
		if (v[i]!=v[i-1])
			cout << v[i] << "\n";

	return 0;
}
