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
void solve(){
    ll m,n,k;
    cin >> n >> k;
    vector<ll>arr(n);
    rep(i,0,n) cin >> arr[i];
    sortd(arr);
    ll sum = 0;
    rep(i,0,k) sum += arr[i];
    //now this question  is all about counting no of subsets whose sum is equal to 'sum' and.
    // size of subsets is equal to k.
    ll dp[n+1][sum+1][k+1];
    memset(dp, 0, sizeof(dp));
    rep(i,0,n+1)
    dp[i][0][0] = 1;
    rep(i,1,n+1){
        rep(j,1,sum+1){
            rep(p,1,k+1){
                if(arr[i-1] <= j) dp[i][j][p] = (dp[i-1][j - arr[i-1]][p-1] + dp[i-1][j][p])%M;
                else dp[i][j][p] = dp[i-1][j][p];
            }   
        }
    }
    cout << dp[n][sum][k] << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 