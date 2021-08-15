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
    vector<ll> a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    if(n==1){
        if(a[0]) cout << n+1 << " " << 1 << endl;
        else cout << 1 << " " << n+1 << endl;
        return;
    }
    // int count = 0;
    // rep(i,0,n) if(a[i]) ++count;
    // if(count==0){
    //     cout << -1 << endl;
    //     return; 
    // }
    int mn = 1;
    int i = 0;
    for(;i < n; i++){
        if(a[i]) break;
        else{
            cout << mn++ << " ";
        }
    }
    cout << n+1 << " ";
    while(mn < n+1){
        cout << mn++ << " ";
    }
    cout << endl;

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 