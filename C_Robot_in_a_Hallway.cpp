#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
/*...............code starts here................*/
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
long long ans = 1e16;
long long n;
bool valid(ll x, ll y){
    if(x < 0 or x >= 2) return false;
    if(y < 0 or y >= n) return false;
    return true;
}
int visited[2][200005], arr[2][200005];
void dfs(ll x, ll y, ll count, ll time){
    if(count == 2*n) {
        ans = min(ans, time);
        return;
    }
    visited[x][y] = 1;
    ll newx, newy;
    for(int i = 0; i < 4; i++){
        newx = dx[i] + x;
        newy = dy[i] + y;
        if(valid(newx, newy) and visited[newx][newy] == 0){
            if(arr[newx][newy] <= time)
            dfs(newx, newy, count+1, time+1);
            else dfs(newx, newy, count+1, arr[newx][newy]+1);
        }
    }
    visited[x][y] = 0;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[0][i];
    for(int i = 0; i < n; i++) cin >> arr[1][i];
    memset(visited, 0, sizeof(visited));
    dfs(0, 0, 1, 0);
    cout << ans<< endl;
    ans = 1e16;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
