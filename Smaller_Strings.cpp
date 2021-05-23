//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define mem(v,a) 		 memset(v, a, sizeof(v))
#define M 1000000007
bool comp(ll x,ll y)
{
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
ll power(ll no,ll p)
{
    if(p == 1)
    return no;
    if(p == 0)
    return 1;
    ll q = power(no,p/2);
    q = (q*q)%M;
    if(p % 2 != 0)
    q = (q*no)%M;
    return q;
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    string s; cin >> s;
    ll ans = 0;
    ll left = (n+1)/2 - 1;
    rep(i,0,(n+1)/2){
        if(s[i]=='a') continue;
        ll a = s[i] - 'a';
        ll b = pow(k, left - i);
        b = (a*b)%M;
        ans = (ans + b)%M;
    }
    string temp(n,'a');
    rep(i,0,(n+1)/2){
        temp[i] = s[i];
    }
    int i = (n+1)/2, j = (n)/2-1;
    while(i < n){
        temp[i] = s[j];
        j -=1;
        i += 1;
    }
    // cout<<temp<<endl;
    if(temp < s)
    ans = (ans + 1)%M;
    cout<<ans<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    int count = 1;
    while(tt--){
        cout<<"Case #"<<count<<": ";
        solve();
        count += 1;
    }
}
 
 
 
 
// g++ -std=c++17