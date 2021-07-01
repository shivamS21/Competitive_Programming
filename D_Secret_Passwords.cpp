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
vector<int> visited(26,-1);
vector<set<char> > adj(26);
void dfs(char x, char par){
    // cout << x << " " << par << endl;
    visited[x-'a'] = par-'a'+1;
    for(char c: adj[x-'a']){
        if(visited[c-'a'] == -1){
            dfs(c, par);
        }
    }
}
void solve(){
    ll m,n,k;
    cin >> n;
    vector<string> arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    rep(i,0,n){
        string s = arr[i];
        int l = s.length();
        set<char> temp;
        for(char c: s)
        temp.insert(c);
        for(auto it = temp.begin(); it != temp.end(); ++it){
            for(auto it2 = it; it2 != temp.end(); it2++){
                char a = *it, b = *it2;
                adj[a-'a'].insert(b);
                adj[b-'a'].insert(a);
            }
        }
    }
    // rep(i,0,26){
    //     for(char c: adj[i]) cout << char(i+97) << " " << c << endl;
    // }
    int count = 0;
    rep(i,0,26){
        if(visited[i] == -1 and adj[i].size() > 0){
            // cout << char(i+97);
            dfs(char(i+97), char(i+97));    
            count += 1;
        }
    }
    // print(visited);
    cout << count << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 