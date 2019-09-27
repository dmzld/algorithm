#include <iostream>
#include <cstring>
using namespace std;

int main(){

	char d[15];
	int sec = 0;

	scanf("%s", d);

	for (int i = 0; d[i] != NULL; i++){
		if (d[i] >= 'A' && d[i] <= 'C')
			sec += 3;
		else if (d[i] >= 'D' && d[i] <= 'F')
			sec += 4;
		else if (d[i] >= 'G' && d[i] <= 'I')
			sec += 5;
		else if (d[i] >= 'J' && d[i] <= 'L')
			sec += 6;
		else if (d[i] >= 'M' && d[i] <= 'O')
			sec += 7;
		else if (d[i] >= 'P' && d[i] <= 'S')
			sec += 8;
		else if (d[i] >= 'T' && d[i] <= 'V')
			sec += 9;
		else if (d[i] >= 'W' && d[i] <= 'Z')
			sec += 10;
		else if (d[i] > 'Z')
			sec += 11;
	}
	cout << sec;

	return 0;
}
