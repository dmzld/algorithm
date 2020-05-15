#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int	N, q[2000001], s = 0, e = 0; // idx of front, end
string str;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> str;

		if (str == "push"){
			int num;
			cin >> num;
			q[e++] = num;
		}
		else if (str == "pop"){
			if (e - s > 0)
				cout << q[s++] << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "size"){
			cout << e - s << "\n";
		}
		else if (str == "empty"){
			if (e - s > 0)
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (str == "front"){
			if (e - s > 0)
				cout << q[s] << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "back"){

			if (e - s > 0)
				cout << q[e - 1] << "\n";
			else
				cout << "-1\n";
		}
	}


	return 0;
}
