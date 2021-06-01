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
    cin >> n;
    vector<ll> vec(n);
    rep(i,0,n) cin >> vec[i];
    vector<ll> ans;
    ll length = 2;
    rep(i,0,n){
        if(vec[i] != 1){
            while(!ans.empty() and ans.back()+1 != vec[i])
            ans.pop_back();
            if(!ans.empty())
            ans.pop_back();
        }
        ans.pb(vec[i]);
        rep(j,0,ans.size()){
            cout << ans[j];
            if(j==ans.size()-1)
            continue;
            cout << ".";
        }
        cout << endl;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 