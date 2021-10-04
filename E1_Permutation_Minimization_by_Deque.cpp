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
    vector<int> arr(n);
    rep(i,0,n) cin >> arr[i];
    vector<int> ans1(n, -1), ans2(n+1, INT_MAX);
    int a = 0, b = n;
    rep(i,0,n){
        if(arr[i] < ans2[b]) ans2[--b] = arr[i];
        else ans1[a++] = arr[i];
        
    }
    // print(ans2);
    // print(ans1);
    rep(i,0,n){
        if(ans2[i] != INT_MAX) cout << ans2[i] << " ";
    }
    rep(i,0,n) {
        if(ans1[i] != -1) cout << ans1[i] << " ";
    }
    cout << endl;
    // print(arr);
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 