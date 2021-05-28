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
vector<ll> vec(101);
ll dp[101][100005];
ll n,k;
ll calc(ll i, ll p){
    if(p==0)
    return 1;
    if(i==n)
    return 0;
    ll &res = dp[i][p];
    if(res != -1)
    return res;
    ll a = 0;
    rep(j,0,min(p,vec[i])+1){
        a = (a + calc(i+1, p-j));
    }
    return res = a;
}
void solve(){
    cin >> n >> k;
    rep(i,0,n) cin >> vec[i];
    memset(dp, -1, sizeof(dp));
    dp[0][k] = 0;
    rep(i,0,min(k,vec[0])+1){
        //cacl(index of the array, left k)
        dp[0][k] = (dp[0][k] + calc(1,k-i))%M;  
    }
    cout<<dp[0][k]<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 