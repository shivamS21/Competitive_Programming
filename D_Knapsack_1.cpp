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
    ll m,n,k, w;
    cin >> n >> w;
    ll val[n+1], weight[n+1];
    for(int i = 1; i < n+1; i++){
        cin >> weight[i] >> val[i];
    }
    ll dp[w+1][n+1];
    for(int i = 0; i < w+1; i++) for(int j = 0; j < n+1; j++) dp[i][j] = 0;
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= n; j++){
            if(weight[j] <= i){
                //we can either take this weight, or can ignore it
                dp[i][j] = max(val[j] + dp[i-weight[j]][j-1], dp[i][j-1]);
            } else{
                //we have to ignore this weight
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[w][n];
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 