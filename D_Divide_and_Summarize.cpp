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
set<ll> s;
vector<ll> vec;
void go(ll l, ll r){
    ll sum = 0;
    rep(i,l,r+1) sum += vec[i];
    s.insert(sum);
    ll pos = -1;
    ll mid = (vec[l] + vec[r])/2;
    rep(i,l,r+1){
        if(vec[i] <= mid)
        pos = i;
        else break;
    }
    if(pos == -1 or pos == r) return;
    go(l, pos);
    go(pos+1, r);
}
void solve(){
    ll m,n,k;
    cin >> n >> k;
    vec.resize(n);
    rep(i,0,n) cin >> vec[i];
    sorta(vec);
    go(0,n-1);
    rep(i,0,k){
        ll sum; cin >> sum;
        if(s.find(sum)!=s.end()) cout << "Yes";
        else cout << "No"; cout << endl;
    }
    s.clear();
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 