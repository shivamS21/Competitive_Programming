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
ll c = 0; 
ll n,k;
void solve(){
    cin >> n >> k;
    vector<ll> vec(n+1);
    rep(i,1,n+1) cin >> vec[i];
    ll dp[n+1][k+1]={0};
    dp[0][0] = 1;
    rep(j,1,k+1)
    dp[0][j] = 0;
    rep(i,1,n+1){
        vector<ll> sum(k+1);
        sum[0] = dp[i-1][0];    
        rep(j,1,k+1){
            sum[j] = (sum[j-1] + dp[i-1][j])%M;
        }
        rep(j,0,k+1){
            if(j <= vec[i])
            dp[i][j] = sum[j];
            else{
                dp[i][j] = (sum[j] - sum[j-vec[i]-1] + M)%M;
            }
        }
        sum.clear();
    }
    cout<<dp[n][k]%M<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 