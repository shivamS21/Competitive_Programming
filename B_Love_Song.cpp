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
    ll m,n,k,q;
    cin >> n >> q;
    string s; 
    cin >> s;

    vector<vector<int> > count(27, vector<int>(n+1,0));
    for(char c='a'; c <= 'z'; c++){
        rep(i,0,n){
            if(s[i] == c)
            count[c-'a'][i+1] = count[c-'a'][i] + 1;
            else count[c-'a'][i+1] = count[c-'a'][i];
            // cout << i << " " << s[i] << " " << c << endl;
        }
    }
    // rep(i,0,27){
    //     rep(j,0,n+1) cout << count[i][j] << " ";
    //     cout << endl;
    // }
    rep(i,0,q){
        ll l, r; cin >> l >> r;
        ll out = 0;
        for(char c='a'; c <= 'z'; c++){
            ll ans = 0;
            ll time = count[c-'a'][r] - count[c-'a'][l-1];
            ans += time * (c-'a'+1) - time;
            // cout << c << " " << l << " " << r << " " << time << " " << ans << endl;
            out += ans;
        }
        cout << out + r - l + 1 << endl;
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
 