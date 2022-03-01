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
//recursive approach

void solve(){
    ll m,n,k;
    // cin >> n;
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    n = 4;
    k = 10;
    int dp[k+1][n+1];
    //dp[i][j] = gives the number of subsequences having product less than i using indexes till j
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j-1];
            if(A[j-1] <= i)
            dp[i][j] += 1 + dp[i/A[j-1]][j-1];
        }
    }
    cout << dp[k][n];
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
} 