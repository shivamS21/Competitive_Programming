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
vector<double> p;
int n;
double dp[3000][3000];
void solve(){
    cin >> n;
    p.resize(n);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> p[i];
    dp[0][0] = 1;
    for(int chance = 1; chance <= n; chance++){
        double h = p[chance-1], t = 1 - p[chance-1];
        dp[chance][0] = t * dp[chance-1][0];
        for(int head = 1; head <= chance; head++){
            dp[chance][head] = h * dp[chance-1][head-1] + t * dp[chance-1][head];
        }
    }
    double ans = 0.0;
    for(int head = n/2+1; head <= n; head++){
        ans += dp[n][head];
    }
    cout << fixed << setprecision(10) << ans;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 