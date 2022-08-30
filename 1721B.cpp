#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int solve(){
    ll n, m, x, y, d;
    cin >> n>> m >> x >> y >> d;
    vector<vector<int>>vec(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    q.push({x-1, y-1});
    vec[x-1][y-1] = 1;
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = xx + dx[i];
            int newy = yy + dy[i];
            if(newx < 0 or newy < 0 or newx >= n or newy >= m) continue;
            int dis = abs(x-1 - newx)+abs(y-1-newy);
            if(dis <= d and vec[newx][newy] == -1){
                q.push({newx, newy});
                vec[newx][newy] = 1;
            }
        }
    }
    q.push({0, 0});
    queue<int> dist;
    dist.push(0);
    vector<vector<int>> visited(n, vector<int>(m, 0));
    visited[0][0] = 1;
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        int dd = dist.front();
        if(xx == n-1 and yy == m-1) return dd;
        dist.pop();
        q.pop();
        for(int i = 0; i < 4; i++){
            int newx = xx + dx[i];
            int newy = yy + dy[i];
            if(newx < 0 or newy < 0 or newx >= n or newy >= m) continue;
            if(visited[newx][newy] == 0 and vec[newx][newy] != 1){
                q.push({newx, newy});
                dist.push(dd+1);
                visited[newx][newy] = 1;
            }
        }
    }
    return -1;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) cout << solve() << endl;
}
