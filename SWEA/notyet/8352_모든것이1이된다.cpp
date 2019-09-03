/*

2^31를 넘는 값을 input으로 받을 수 있음.
현재대로의 알고리즘대로는 2^31이 넘는 값을 그대로 사용하여 에러.

*/

#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(){

	int T = 0;
	char a[11]; // if a[10], size of input over 10(it include "enter") so a will be corrupt
	int bin = 0, dec = 0;
	bool leap = false;

	cin >> T;

	for (int i = 0; i < T; i++){

		cin >> a;

		int year = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0');
		int month = (a[5] - '0') == 0 ? (a[6] - '0') : (a[5] - '0') * 10 + (a[6] - '0');
		int day = (a[8] - '0') == 0 ? (a[9] - '0') : (a[8] - '0') * 10 + (a[9] - '0');

		cin >> a;

		int hour = (a[0] - '0') == 0 ? (a[1] - '0') : (a[0] - '0') * 10 + (a[1] - '0');
		int min = (a[3] - '0') == 0 ? (a[4] - '0') : (a[3] - '0') * 10 + (a[4] - '0');
		int sec = (a[6] - '0') == 0 ? (a[7] - '0') : (a[6] - '0') * 10 + (a[7] - '0');


		cout << year << "/" << month << "/" << day << " " << hour << ":" << min << ":" << sec << "  start!!\n";

		char bin_s[30];

		cin >> bin_s;
		int j = 0;
		while (bin_s[j] != NULL){
			cout << j << "th, => " << (pow(2, j) * (int)(bin_s[j] - '0'));
			dec += (int)(pow(2, j++) * (int)(bin_s[j] - '0'));
			cout << " dec : " << dec << "\n";
		}

		sec += dec % 60;
		dec = dec / 60;
		
		min += dec % 60;
		dec = dec / 60;

		hour += dec % 12;
		dec = dec / 12; // dec = 시분초값 다 뺀, 남은 일수

		cout << year << "/" << month << "/" << day << " " << hour << ":" << min << ":" << sec << "  - hms\n";

		while (dec){
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
				if (dec < 31){
					day += dec;
					break;
				}
				dec -= 31;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11){
				if (dec < 30){
					day += dec;
					break;
				}
				dec -= 30;
			}
			else{ // month == 2
				cout << dec << "\n";
				if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0){ // 윤년
					if (dec < 29){
						day += dec;
						break;
					}
					dec -= 29;
				}
				else{ // 윤년X
					if (dec < 28){
						day += dec;
						break;
					}
					dec -= 28;
				}
				
			}
			month++;
			if (month > 12){
				month = 1;
				year++;
			}
		}

		cout << year << "/" << month << "/" << day << " " << hour << ":" << min << ":" << sec << "\n";


	}

	return 0;
	
}
