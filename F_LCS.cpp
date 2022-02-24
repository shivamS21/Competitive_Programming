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
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    int dp[n+1][m+1];
    rep(i, 0, n+1){
        rep(j, 0, m+1) dp[i][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            } else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    // cout<<dp[n][m]<<endl;
    string ans ="";
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++) cout << dp[i][j] << " ";cout<<endl;
    // }
    int i = n, j = m;
    while(i and j){
        if(s[i-1] == t[j-1])
        {
            ans += s[i-1];
            i -= 1;
            j -= 1;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        i -= 1;
        else j -= 1;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 