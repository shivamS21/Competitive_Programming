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
vector<int> Sieve(int n){
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for(ll i=2;i*i <= n;i+=1) {
        if(prime[i] == true){
           for (ll j=i*i; j<=n; j += i) 
                prime[j] = false;
        }
    }
    vector<int> p;
    rep(i,2,n+1){
        if(prime[i])
        p.pb(i);
    }
    return p;
}
void solve(){
    ll l,r; cin >> l >> r;
    vector<int> prime = Sieve(r);
    ll ans = 0;
    for(int i = 0; i < prime.size() and prime[i] <= r; i++){
        ll nums = 0;
        if(prime[i] >= l){
            ll a = r / prime[i];
            nums = a-1;
        }
        else{
            ll a = r / prime[i];
            ll b = (l-1) / prime[i];
            nums = a - b;
        }
        if(nums > 1 ){
            ans += (nums * (nums - 1));
        }
        cout << prime[i] << " " << nums << " " << ans << endl;
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
 