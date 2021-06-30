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
    map<int,int> mp;
    rep(i,0,n){
        int inp; cin >> inp;
        mp[i+1] = inp;
    } 
    set<int> s;
    rep(i,1,n+1) s.insert(i);
    map<int,int> parent;
    int ans[n+1]={0};
    while(!s.empty()){
        int no = *s.begin();
        ans[no] = 1;
        parent[no] = no;
        while(mp[no] != *s.begin()){
            no = mp[no];
            parent[no] = *s.begin();
            s.erase(no);
            ans[*s.begin()] += 1;
        }
        s.erase(s.begin());
    }
    rep(i,1,n+1){
        int p = parent[i];
        cout << ans[p]<<" ";
    }
    cout<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 
