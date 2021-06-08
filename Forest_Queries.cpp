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
    vector<string> s(n);
    rep(i,0,n) cin >> s[i];
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    rep(i,1,n+1){
        rep(j,1,n+1){
            int &res = dp[i][j];
            res = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (s[i-1] [j-1]=='*');
        }
    }
    rep(i,0,k){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int a = dp[x2][y1-1];
        int b = dp[x1-1][y1-1];
        int c = dp[x1-1][y2];
        int d = dp[x2][y2];
        cout << d - (a + c - b) << endl;
    }

    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 