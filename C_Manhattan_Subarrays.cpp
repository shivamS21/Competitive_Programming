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
bool ok(vector<int> a){
    int n = a.size();
    if(n <= 2) return true;
    if(n >= 5) return false;
    rep(i,0,n){
        rep(j,i+1,n){
            rep(k,j+1,n){
                if((a[i] <= a[j] and a[j] <= a[k]) or (a[i] >= a[j] and a[j] >= a[k]))
                return false;
            }
        }
    } return true;
}
void solve(){
    ll m,n,k;
    cin >> n;
    vector<ll> arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    int ans = 0;
    rep(i,0,n){
        vector<int> b;
        rep(j,i,n){
            b.pb(arr[j]);
            if(ok(b)) ++ans;
            else break;
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
 