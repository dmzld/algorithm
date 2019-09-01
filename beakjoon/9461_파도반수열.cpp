#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(void){
    int T;
    long long arr[101] = { 1, 1, 1, 1, 2, 2, };
 
    cin >> T;
 
    for (int i = 6; i <= 100; i++)
        arr[i] = arr[i - 1] + arr[i - 5];
 
    while (T--){
        int n;
        cin >> n;
        cout << arr[n] << "\n";
    }
 
}
