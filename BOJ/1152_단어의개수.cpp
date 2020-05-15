#include <iostream>
#include <cstring>
using namespace std;

int main(){

	char s[1000000];
	char* s_ptr;
	int ans = 0;

	scanf("%[^\n]", s);
	s_ptr = strtok(s, " ");
	while (s_ptr != NULL){
		ans++;
		s_ptr = strtok(NULL, " ");
	}

	cout << ans;

	return 0;
}
