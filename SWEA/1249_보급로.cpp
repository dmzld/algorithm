#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
 
using namespace std;
 
struct state{
    int y, x, t;
};
 
struct comp{
    bool operator()(state a, state b){
        return a.t > b.t;
    }
};
 
 
int T;
int N;
char map[100][100];
int dp[100][100], check[100][100];
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int ans;
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> T;
    for (int t = 1; t <= T; t++){
        memset(check, -1, sizeof(check));
        memset(map, '0', sizeof(map));
         
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> map[i][j];
         
        bool fin = false;
        priority_queue<state, vector<state>, comp> pq;
        pq.push({ 0, 0, 0 });
 
        while (!pq.empty() && !fin){
            int y = pq.top().y, x = pq.top().x, t = pq.top().t;
            pq.pop();
 
            for (int i = 0; i < 4; i++){
                int ny = y + dir[i].first, nx = x + dir[i].second;
 
                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;
 
                if (ny == N - 1 && nx == N - 1){
                    ans = t;
                    fin = true;
                    break;
                }
 
                int nt = t + (int)(map[ny][nx] - '0');
                if (check[ny][nx] == -1 || check[ny][nx] > nt){
                    pq.push({ ny, nx, nt });
                    check[ny][nx] = nt;
                }
            }
        }
 
        cout << "#" << t << " " << ans << "\n";
    }
 
 
    return 0;
}
