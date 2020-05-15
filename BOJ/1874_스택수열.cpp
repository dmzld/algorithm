#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;


int main(){

	int n = 0, m = 0;
	bool f = true;
	stack<int> s;
	queue<char> q;

	cin >> n;
	vector<int> arr(n,0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++){
		s.push(i);
		q.push('+');

		while (arr[m] == s.top()) {
			//cout << "same " << arr[m] << s.top() << "\n";
			s.pop();
			q.push('-');
			m++;
			if (!s.empty() && arr[m] < s.top()){
				f = false;
				break;
			}
			else if (s.empty())
				break;
		}

		if (f == false)
			break;
	}


	if (f == true)
		while (!q.empty()){
			cout << q.front() << "\n";
			q.pop();
		}
	else
		cout << "NO\n";
		
	return 0;
}
