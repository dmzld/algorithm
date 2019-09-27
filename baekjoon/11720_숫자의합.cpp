#include <iostream>
#include <string>
using namespace std;

int main(){

	int t;
	string a;
	int sum = 0;
	cin >> t >> a;
	
	for (int i = 0; i < t; i++){
		sum += a[i]-'0';
	}
	cout << sum;

	return 0;
}

/*
int t;
char a;
int sum = 0;
cin >> t;
for(int i = 0; i < t; i ++){
scanf("%c", &a);
sum += a-'0';
}
cout << sum;

return 0;
*/
