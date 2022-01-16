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
set<pair<int,int> > mp;
void find(vector<pair<int,int> > &arr, vector<pair<int,int> > &ret, int n, int m){
    for(pair<int,int> p: arr){
        pair<int,int> a, b, c, d;
        int x = p.first;
        int y = p.second;
        a.first = x-1; a.second = y;
        b.first = x; b.second = y-1;
        c.first = x+1; c.second = y;
        d.first = x; d.second = y+1;
        if(mp.find(a) == mp.end() && a.first >= 1 and a.first <= n && a.second >= 1 && a.second <= m){
            mp.insert(a);
            ret.pb(a);
        }
        if(mp.find(b) == mp.end() && b.first >= 1 and b.first <= n && b.second >= 1 && b.second <= m){
            // mp[b] = 1;
            mp.insert(b);
            ret.pb(b);
        }
        if(mp.find(c) == mp.end() && c.first >= 1 and c.first <= n && c.second >= 1 && c.second <= m){
            // mp[c] = 1;
            mp.insert(c);
            ret.pb(c);
        }
        if(mp.find(d) == mp.end() && d.first >= 1 and d.first <= n && d.second >= 1 && d.second <= m){
            // mp[d] = 1;
            mp.insert(d);
            ret.pb(d);
        }
    }
    // return ret;
} 
void solve(){
    ll m,n,k;
    cin >> n >> m;
    vector<pair<int,int> > arr;
    int d = 0;
    if(n%2 && m%2){
        //both odds
        arr.pb(mk(n/2+1, m/2+1));
        d = abs(n - n/2-1) + abs(m-m/2-1);
    } else if((m%2 && n%2==0) or (m%2==0 && n%2)){
        if(m%2){
            int x = m;
            m = n;
            n = x;
        }
        // n is odd here
        arr.pb({n/2+1, m/2});
        arr.pb({n/2+1, m/2+1});
        d = n-n/2-1 + m/2;
    } else{
        arr.pb({n/2, m/2});
        arr.pb({n/2,m/2+1});
        arr.pb({n/2+1,m/2});
        arr.pb({n/2+1, m/2+1});
        d = n/2+m/2;
    }
    vector<int> ans;
    // map<pair<int,int>, int> mp;
    for(pair<int,int> p: arr){
        mp.insert(p);
    }
    for(int i = 0; i < n*m; i++){
        for(int j = 0; j < arr.size(); j++){
            ans.pb(d);
        }
        ++d;
        vector<pair<int,int> > ret;
        find(arr, ret, n, m);
        arr = ret;
    }
    print(ans);
    mp.clear();
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 