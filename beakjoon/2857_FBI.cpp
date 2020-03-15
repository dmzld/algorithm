#include <iostream>
#include <string>

using namespace std;

int N;
string str;
bool check[5] = { false, };
bool flag = false;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++){
		cin >> str;
		if (str.find("FBI") != std::string::npos){
			check[i] = true;
			flag = true;
		}
	}
	if (!flag)
		cout << "HE GOT AWAY!";
	else
		for (int i = 0; i < 5; i++)
			if (check[i])
				cout << i + 1 << " ";

	return 0;
}
