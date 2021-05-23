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
ll n;
void solve(){
    cin >> n;
    ll ans = 0;
    set<ll> s;
    ll i = 1;
    while((2*n-i*i+i) > 0){
        if((2*n-i*i+i) % (2*i) == 0)
        s.insert((2*n-i*i+i)/(2*i));
        i += 1;
    }
    cout<<s.size()<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    int count = 1;
    while(tt--){
        cout<<"Case #"<<count<<": ";
        count += 1;
        solve();
    
    }
}
 
 
 
 
// g++ -std=c++17