#include <iostream>
#include <string>

using namespace std;

int N;
string str;
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> str;
	for (int i = 0; i < N; i++){
		if (str.at(i) == 'S'){
			ans++;
		}
		else if (str.at(i) == 'L'){
			ans++;
			i++;
		}
	}
	if (str.find('L') == std::string::npos)
		cout << ans;
	else
		cout << ans + 1;

	return 0;
}
