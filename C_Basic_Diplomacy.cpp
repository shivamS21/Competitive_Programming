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
    cin >> n >> m;
    vector<int> vec[m];
    vector<pair<int,int> > p(m);
    rep(i,0,m){
        cin >> k;
        rep(j,0,k){
            int input; cin >> input;
            vec[i].pb(input);
        }
        p[i] = mk(k, i);  
    }
    sorta(p);
    vector<int> ans(m,0);
    map<int,int> mp;
    rep(i,0,m){
        rep(j,0,p[i].first){
            int ele = vec[p[i].second][j];
            if(mp[ele] < (m+1)/2){
                mp[ele] += 1;
                ans[p[i].second] = ele;
                break;
            }
        }
    }
    rep(i,0,m){
        if(ans[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    print(ans);
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 