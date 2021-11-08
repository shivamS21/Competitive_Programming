//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
 
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
int dp[1010][1010];
int m, n;
const int MAX = 1000;
void getMaxGold(int gold[MAX][MAX], int x, int y, int curr){
    if(x >= n or y >= m) return;
    if(curr + gold[x][y] > dp[x][y]){
        dp[x][y] = curr + gold[x][y];
        if(y+1 >= m) return;
        if(x+1 < n)
        getMaxGold(gold, x+1, y+1, dp[x][y]);
        if(y+1 < m)
        getMaxGold(gold, x-1, y+1, dp[x][y]);
    }
}
void solve(){
    memset(dp, 0, sizeof(dp));
    int gold[MAX][MAX]= { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    m = 4; n = 4;
    rep(i,0,n){
        getMaxGold(gold, i, 0, 0);
    }
    int mx = -1;
    rep(i,0,n){
        mx = max(mx, dp[i][0]);
    }
    cout << mx << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 