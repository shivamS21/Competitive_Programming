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
    vector<int>arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool dp[k+1][2];
    memset(dp, false, sizeof(dp));
    dp[0][0] = false;
    dp[0][1] = false;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(arr[j] <= i){
                dp[i][0] = dp[i][0] or !dp[i-arr[j]][1];
                dp[i][1] = dp[i][1] or !dp[i-arr[j]][0];
            }
        }
    }
    if(dp[k][0]) cout << "First"; else cout << "Second";
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 