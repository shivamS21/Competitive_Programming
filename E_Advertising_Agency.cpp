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
ll fac[1001];
void calc(){
    fac[0]=fac[1]=1;
    rep(i,2,1001)
    fac[i] = (i*fac[i-1])%M;
}
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
ll ncr(ll n, ll r){
    ll a = fac[n], b = fac[r], c = fac[n-r];
    b = (b * c) % M;
    b = power(b, M-2, M) % M;
    a = (a * b) % M;
    return a;
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    vector<ll>arr(n);
    rep(i,0,n) cin >> arr[i];
    sortd(arr);
    ll ele = arr[k-1];
    ll count = 0;
    rep(i,0,n){
        if(arr[i] == ele) ++count;
    }
    ll pre = 0;
    rep(i,0,k) if(arr[i]==ele) ++pre;
    cout << ncr(count, pre)%M << endl;

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    calc();
    while(tt--){
        solve();
    }
}
 