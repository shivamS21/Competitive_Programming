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
    int m,n,k;
    cin >> n;
    vector<int> vec(n);
    rep(i,0,n) cin >> vec[i];
    int mn = 200, mx = 0;
    int pn=0, px=0;
    rep(i,0,n){
        mn = min(mn, vec[i]);
        mx = max(mx, vec[i]);
    }
    rep(i,0,n){
        if(vec[i] == mn)
        pn = i;
        if(vec[i]==mx)
        px = i;
    }
    // cout << px << " " << pn << endl;
    int ans =  min(max(pn+1, px+1), n - min(pn, px));
    if(pn < px)
    ans = min(ans, pn+1+ n - px);
    else ans = min(ans, px+1+ n-pn);
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
 