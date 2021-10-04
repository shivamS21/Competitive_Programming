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
    set<pair<int,int> > s;
    for(int i = 0; i < n; i++){
        int p; cin >>p;
        s.insert({p, i+1});
    }
    vector<pair<int,int> > ans;
    while(s.size() > 1){
        while((*s.begin()).first == 0) s.erase(s.begin());
        int size = (*(--s.end())).first;
        int inde = (*(--s.end())).second;
        for(set<pair<int,int> >::iterator it = s.begin(); it != --s.end() && size > 0; ++it){
            ans.pb({(*it).second, inde});
            (*it).first -= 1;
            size -= 1;
        }
        if(size > 0)
        s.insert({size, inde});

    }
    cout << ans.size() << endl;
    for(pair<int,int> q: ans) cout << q.first << " " << q.second << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 