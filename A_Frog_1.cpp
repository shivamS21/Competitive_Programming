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
vector<int> dp;
vector<int> arr;
int n;
void solve(){
    cin >> n;
    dp.resize(n+1);
    for(int i = 0; i < n+1; i++) dp[i] = INT_MAX;
    arr.resize(n+1);
    for(int i = 1; i < n+1; i++){
        cin >> arr[i];
    }
    dp[1] = 0;
    // dp[2] = abs(arr[1] - arr[2]);
    dp[0] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = min(abs(arr[i] - arr[i-1]) + dp[i-1], abs(arr[i] - arr[i-2]) + dp[i-2]);
    }
    cout << dp[n];
}
int main() {
    FAST_FURIER;
    int tt=1;
    //cin >> tt;
    while(tt--){
        solve();
    }
}
 