#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
 
int main(){
 
    int T = 0, ans = 0;
    pair<int, int> p1;
    pair<int, int> p2;
 
    cin >> T;
 
    for (int i = 0; i < T; i++){
         
        int x1, y1;
        int x2, y2;
        int ans = 0;
 
        cin >> x1 >> y1 >> x2 >> y2;
 
        int common = min(abs(x2 - x1), abs(y2 - y1)); // x2-x1 , y2-y1 중 작은쪽
        int rest = abs(abs(x2 - x1) - abs(y2 - y1)); // x2-x1 , y2-y1 중 큰쪽에서 작은쪽을 뺸 것
         
        ans += common * 2;
        ans += (rest / 2) * 4 + (rest % 2);
 
        cout << "#" << i + 1 << " " << ans << "\n";
         
    }
     
 
    return 0;
}
