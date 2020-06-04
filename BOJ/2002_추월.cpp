#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, ans = 0;
string car;
queue<string> in, out;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> car;
		in.push(car);
	}
	for (int i = 0; i < N; i++){
		cin >> car;
		out.push(car);
	}

	while (!in.empty()){
		if (in.front() != out.front()){
			string tmp = in.front(); // overtaken car
			ans++;
			while (in.front() != out.front()){ // find overtake car(==out.front())
				in.push(in.front());
				in.pop();
			}
			in.pop();
			out.pop();
			while (in.front() != tmp){ // rearrange order
				in.push(in.front());
				in.pop();
			}
		}
		else{	
			in.pop();
			out.pop();
		}
	}

	cout << ans;

	return 0;
}
