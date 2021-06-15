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
    string s; cin >> s;
    n = s.length();
    vector<int> a(n+1,0), b(n+1,0);
    (s[0]=='a')? a[1] = 1 : a[1] = 0;
    (s[n-1]=='b') ? b[n] = 1 : b[n] = 0;
    rep(i,1,n) (s[i]=='a')? a[i+1] = a[i]+1 : a[i+1] = 0;
    rrep(i,n-2,-1) (s[i]=='b') ? b[i+1] = b[i+2] + 1 : b[i+1] = 0;
    // print(a);
    // print(b);
    ll ans = 0;
    ll count = 0;
    rep(i,0,n-1){
        if(s[i]=='a' and s[i+1] == 'b'){
            ll ca = a[i+1], cb = b[i+2];
            count += ca;
            ans = (ans + ((power(2,count,M)%M-1) * cb) % M) % M;
        }
    }
    cout << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 