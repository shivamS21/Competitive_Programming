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
long long dp[100002][2];
long long calc(int i, int taken, int val, vector<int> nums){
    if(i == nums.size()) return 0;
    long long &res = dp[i][taken];
    if(res != -1) return res;
    if(taken){
        // means I have to take the ith index no.
        res = pow(-1, 1-val) * nums[i] + max(calc(i+1, 1, 1-val, nums), calc(i+1, 0, 1-val, nums));
    } else{
        // means I can not taken this 
        res = max(calc(i+1, 1, val, nums), calc(i+1, 0, val, nums));
    }
    return res;
}
long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    // long long dp[n+1][2];
    for(int i = 0; i < n+1; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    dp[0][1] = nums[0] + max(calc(1, 1, 0, nums), calc(1, 0, 0, nums));
    dp[0][0] = max(calc(1, 1, 1, nums), calc(1, 0, 1, nums));
    return max(a, b);
} 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<int> nums(n);
    rep(i,0,n) cin >> nums[i];
    cout << maxAlternatingSum(nums);
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 