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
ll power(ll no,ll p, ll mod)
{
    if(p == 1)
    return no;
    if(p == 0)
    return 1;
    ll q = power(no,p/2,mod);
    q = (q*q)%M;
    if(p % 2 != 0)
    q = (q*no)%M;
    return q;
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    if(n==1) cout << power(2, k, M) << endl;
    else{
        vector<int> dp(k+1,0);
        dp[0] = 1;
        rep(i,1,k+1){
            if(n%2){
                ll temp = power(2, n-1, M);
                temp = (temp * dp[i-1]) % M;
                dp[i] = (dp[i-1] + temp)%M;
            } else{
                ll temp1 = power(2, (i-1)*n, M);
                ll temp2 = power(2, n-1, M) - 1;
                temp2 = (temp2 * dp[i-1])%M;
                dp[i] = (temp1 + temp2) % M;
            }
        }
        cout << dp[k] << endl;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
  