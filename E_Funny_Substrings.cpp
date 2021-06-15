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
    map<string, string> mp;
    int ans = 0;
    rep(i,0,n){
        string a, check, b, c;
        cin >> a >> check  >> b;
        if(check == ":="){
            mp[a] = b;
            //means asigning a variable some value
        }else{
            cin >> check >> c;
            // strings are basically stored in a,c,d
            mp[a] = mp[b] + mp[c];
        }
        // cout <<"i " << i << " " <<  mp[a] << endl;
        if(i==n-1){
            int l = mp[a].length();
            string s = mp[a];
            rep(i,0,l-3){
                if(s.substr(i,4)=="haha")
                ++ans;
            }
        }
    }
    cout << ans << endl;

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 