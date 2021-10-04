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
    // cin >> n;
    string s; cin >>s;
    n = s.length();
    vector<int> visited(n, 0);
    rep(i,0,n){
        if(visited[i]) continue;
        if(s[i]=='A'){
            rep(j,i+1,n){
                if(!visited[j] && s[j] == 'B'){
                    visited[j] = 1;
                    visited[i] = 1;
                    break;
                }
            }
        } else if(s[i] == 'B'){
            rep(j,i+1,n){
                if(!visited[j] && (s[j] == 'C' or s[j] == 'A') ){
                    visited[j] = 1;
                    visited[i] = 1;
                    break;
                }
            }
        } else{
            rep(j,i+1,n){
                if(!visited[j] && s[j] == 'B'){
                    visited[j] = 1;
                    visited[i] = 1;
                    break;
                }
            }
        }
    }
    rep(i,0,n){
        if(visited[i]==0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 