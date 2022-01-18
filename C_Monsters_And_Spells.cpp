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
    ll m,n;
    cin >> n;
    vector<ll> k(n+1, 0), h(n+1, 0);
    rep(i,1,n+1) cin >> k[i];
    rep(i,1,n+1) cin >> h[i];
    vector<ll> fill(n+1, 0);
    ll mark = 0;
    for(int i = 1; i <= n; i++){
        if(h[i]>k[i]-k[i-1]){
            fill[i] = fill[i-1]+k[i]-k[i-1];
            ll p = fill[i];
            ll x = fill[i-1];
            p = (p*(p+1))/2 - (x*(x+1))/2;
            mark += p;
        } else{
            fill[i] = h[i];
            
            mark += (fill[i]*(fill[i]+1))/2;
        }
    }
    cout << mark << endl;
    
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 