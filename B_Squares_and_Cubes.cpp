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
vector<ll> good;
void solve(){
    ll m,n,k;
    cin >> n;
    cout << upper_bound(good.begin(), good.end(), n) - good.begin() << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    set<ll> se;
    for(int i = 1; i *i <= 1e9; i++){
        se.insert(i*i);
    }
    for(int i = 1; i*i*i <= 1e9; i++)
    se.insert(i*i*i);
    set<ll>::iterator it = se.begin();
    while(it != se.end()){
        good.push_back(*it);
        ++it;
    }
    while(tt--){
        solve();
    }
}
 