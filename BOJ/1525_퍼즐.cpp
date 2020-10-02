#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

string str;
set<string> check;
pair<int, int> dir[4] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++){
		char tmp;
		cin >> tmp;
		str += tmp;
	}

	queue<string> q;
	q.push(str);
	check.insert(str);
	ans = 0;

	while (!q.empty()){
		int qSize = q.size();
		for (int t = 0; t < qSize; t++){
			string cStr = q.front();
			q.pop();

			if (cStr == "123456780"){
				cout << ans;
				return 0;
			}

			for (int i = 0; i < 9; i += 3){
				for (int j = 0; j < 3; j++){
					if (cStr[i + j] == '0'){

						for (int k = 0; k < 4; k++){
							int ny = i + dir[k].first * 3;
							int nx = j + dir[k].second;

							if (ny < 0 || ny >= 9 || nx < 0 || nx >= 3)
								continue;

							string nStr = cStr;
							nStr[i + j] = cStr[ny + nx];
							nStr[ny + nx] = '0';

							set<string>::iterator it = check.find(nStr);
							if (it == check.end()){
								check.insert(nStr);
								q.push(nStr);
							}
						}
					}
				}
			}
		}
		ans++;
	}

	cout << -1;

	return 0;
}
