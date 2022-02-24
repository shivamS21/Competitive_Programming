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
int n, m;
ll dp[1001][1001];
vector<string> arr;
ll rec(int i, int j){
    if(i == n-1 and j == m-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    ll res = 0;
    if(i+1<n and arr[i+1][j] == '.')
    res = rec(i+1, j)%M;
    if(j+1<m and arr[i][j+1] == '.')
    res = (res + rec(i, j+1))%M;
    return dp[i][j] = res;
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i <=n; i++) for(int j = 0; j <= m; j++) dp[i][j] = -1;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << rec(0, 0);
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 