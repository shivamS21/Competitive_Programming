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
    if(n > m) cout << n-m << endl;
    else{
        queue<pair<int,int> > q;
        q.push({n, 0});
        int mn = INT_MAX;
        vector<int> visited(2*m+10,0);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p.first > m*2 or visited[p.first]) continue;
            else visited[p.first] = 1;
            // cout << p.first << " " << p.second << endl;
            if(p.first == m){
                mn = min(mn, p.second);
                continue;
            }
            if(p.first != 1)
            q.push({p.first-1, p.second+1});
            q.push({2*p.first, p.second+1});
        }
        cout << mn << endl;
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
 