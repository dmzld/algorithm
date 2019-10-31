#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){	
	
	string s;
	int alpa[26] = { 0, };
	int max = -1;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> s){
		for (int i = 0; i < s.length(); i++)
			if (s.at(i) >= 'a'&&s.at(i)<='z')
				alpa[s.at(i) - 'a']++;
		s.clear();
	}
	
	for (int i = 0; i < 26; i++){
		if (max < alpa[i])
			max = alpa[i];
	}
	for (int i = 0; i < 26; i++)
		if (alpa[i] == max)
			cout << alpa[i];

	return 0;
}
