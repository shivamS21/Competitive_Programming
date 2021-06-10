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
string IntToString(ll a) 
{ 
    char x[100]; 
    sprintf(x, "%lld", a); 
    string s = x; 
    return s; 
} 
ll count(ll a, ll b){
    string x = IntToString(a), y = IntToString(b);
    if(x.length() == y.length()){
        ll ans = 0,l=x.length();
        rep(i,0,l){
            if(x[i] == y[i])
            ++ans;
        }
        return ans;
    }
    else return y.length();
}
void solve(){
    ll l, r; cin >> l >> r;
    ll ans = 0;
    while(l < r){
        int diff = 10 - l % 10;
        if(l + diff > r){
            ans += r - l;
            l = r;
            break;
        }
        l += diff;
        ans += diff - 1;
        ans += count(l, r);
    }
    cout << ans << endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 