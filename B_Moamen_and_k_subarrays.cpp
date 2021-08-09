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
    cin >> n >> k;
    vector<ll> vec(n);
    rep(i,0,n) cin >> vec[i];
    vector<ll> temp = vec;
    sorta(temp);
    int ans = 0;
    int s = 0;
    int t = lower_bound(temp.begin(), temp.end(), vec[0]) - temp.begin();
    int one = 0, more = 0;
    rep(i,0,n){
        // cout << t << " ";
            if(t == n){
                if(s==1) one += 1;
                else more += 1;
                s = 1;
                t = lower_bound(temp.begin(), temp.end(), vec[i]) - temp.begin();
                ++t;
            } else{
                if(temp[t] == vec[i]){
                    ++s;
                    ++t;
                }
                else{
                    if(s==1) one += 1;
                    else more += 1;
                    t = lower_bound(temp.begin(), temp.end(), vec[i]) - temp.begin()+1;
                    s = 1;
                }
            }
        // cout << ans << endl;
    }
    if(s==1) one += 1;
    else more += 1;
    // cout << ans << " " << one << endl;
    if(one <= k and (k - one) >= more) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 