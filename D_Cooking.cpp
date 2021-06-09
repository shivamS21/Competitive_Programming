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
int mn = 1e6;
ll arr[102];
int dp[102][100005];
void fill(int n,int sum){
    memset(dp, 0, sizeof(dp));
    rep(i,0,n+1)
    dp[i][0] = 1;
    rep(i,1,n+1){
        rep(j,1,sum+1){
            if(arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
}
void solve(){
    ll m,n,k;
    cin >> n;
    ll sum = 0;
    rep(i,0,n) {
        cin >> arr[i]; 
        sum += arr[i];
    }
    ll ans = 1e7;
    fill(n, sum);
    rep(i,1,sum+1){
        //if any subset sum equals to i, then ans = min(ans, max(i, sum - i))
        //else no point of making calculation.
        if(dp[n][i])
        ans = min(ans, max(i, sum - i));
    }
    cout << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 