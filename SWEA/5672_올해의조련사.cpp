#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
 
 
char arr[2000];
char ans[2000];
 
int main(){
 
    int T = 0, N = 0, K = 0;
    int front, back, ans_idx;
 
    cin >> T; // 전체 = N * K
 
    for (int i = 0; i < T; i++){
        cin >> N;
        front = 0, back = N - 1, ans_idx = 0;
 
        for (int j = 0; j < N; j++){
            char a;
            cin >> a;
            arr[j] = a;
        }
 
        while (front != back){
            if (arr[front] < arr[back]){ // pop front
                ans[ans_idx++] = arr[front++];
            }
            else if (arr[front]>arr[back]){ // pop back
                ans[ans_idx++] = arr[back--];
            }
            else{ // if front == back, then compare next sequence
 
                int f = front + 1;
                int b = back - 1;
 
                while (arr[f] == arr[b] && f < b){ // until front != back
                    f++;
                    b--;
                }
                // CDEFA BFEDC =>  CCDDEEFFAB /////// FEDCA BCDEF => FEDCA BCDEF //// 즉 어쨋든 작은쪽에 가까운 곳을 먼저 뺀다.
                // ACDBCB -> CDBCB -> CDBC -> CDB -> CD -> D
                //           A        AB      ABC    ABCB  ABCBC
 
                if (f >= b){
                    ans[ans_idx++] = arr[front++];
                }
                else if (arr[f] < arr[b]){
                    ans[ans_idx++] = arr[front++];
                }
                else if (arr[f] > arr[b]){
                    ans[ans_idx++] = arr[back--];
                }
            }
        }
        ans[ans_idx] = arr[front]; // last
         
        cout << "#" << i + 1<<" ";
        for (int j = 0; j < N; j++){
            cout << ans[j];
        }
        cout << "\n";
         
    }
 
     
     
 
    return 0;
}
