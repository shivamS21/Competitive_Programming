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
    ll m,n,k;
    cin >> n >> k;
    vector<ll> vec(n);
    rep(i,0,n) cin >> vec[i];
    ll mx = 0, index = 0;
    rep(i,0,n){
        if(vec[i] >= mx){
            mx = vec[i];
            index = i;
        }
    }
    vector<ll> temp;
    rep(j,index,n){
        temp.pb(vec[j]);
    }
    // cout << mx << " " << index << endl;
    // prll(temp);
    ll mxtemp = vec[0];
    ll i = 1, c = 0;
    vector<pair<ll,ll> > nos;
    while(i <= index){
        temp.pb(min(vec[i], mxtemp));
        nos.pb(mk(mxtemp, vec[i]));
        mxtemp = max(mxtemp, vec[i]);
        ++c;
        ++i;
    }
    // pirnt(temp);
    while(k--){
        ll chance; cin >> chance;
        if(chance <= c) cout << nos[chance-1].first << " " << nos[chance-1].second << endl;
        else{
            chance -= nos.size();
            if(chance%(n-1)) chance = chance % (n-1); 
            else chance = (n-1);
            cout << mx << " " << temp[chance] << endl;
        }
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}