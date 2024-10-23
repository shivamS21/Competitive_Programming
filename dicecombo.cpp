#include<bits/stdc++.h>
#include<iostream>
#include<set>

using namespace std;
const int mod = 1e9+7;
#define ll long long
int recursion(vector<vector<int>>&dp, int sum, int i) {
    if (sum < 0) return 0;
    if (sum == 0) return 1;
    if (i > 6) return 0;

    if (dp[sum][i] != -1) return dp[sum][i];

    int not_taking = recursion(dp, sum, i+1);
    int taking = 0;
    for(int k = 1; k <= sum/i; k++) {
        taking += recursion(dp, sum-k*i, i+1);
    }

    return dp[sum][i] = taking + not_taking;
}
void coinComb1() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i< n; i++) cin >> coins[i];

    vector<ll> dp(x+1, 0);
    // dp[i] = no of ways to make sum = i by picking any number from coins
    // when needed total permutaions then use values above and coins inside
    // else in need of unique permutations, use coins above and values inside
    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < n; j++) {
            if (coins[j] <= i)
            dp[i] = (dp[i] + dp[i-coins[j]] + mod)%mod;
        }
    }
    cout << dp[x] << endl;
}
ll recursion(vector<vector<ll>>&dp, vector<int>&coins, int i, int x) {
    if(x==0) return 1;
    if (i==coins.size()) return 0;

    if (x < 0) return 0;

    if (dp[x][i] != -1) return dp[x][i];
    /*Either we are taking ith coin or not */
    
    int not_taking = recursion(dp, coins, i+1, x);
    int taking = 0;
    for(int k = 1; k <= x/coins[i]; k++) {
        taking = (taking + recursion(dp, coins, i+1, x - k*coins[i]) + mod)%mod;
    }

    return dp[x][i] = (not_taking + taking + mod)%mod;
}
void coinCombo2(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i <n; i++) {
        cin >> coins[i];
    }
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for(int coin: coins) {
        for(int value = 1; value <= x; value++) {
            if (coin <= value) {
                dp[value] = (dp[value] + dp[value-coin] +mod)%mod;
            }
        }   
    }    
    cout << dp[x] << endl;
}
void minCoins(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i <n; i++) cin >> coins[i];
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0; // coins needed to make sum = 0
    for(int coin: coins) {
    
        for(int val = 1; val <= x; val++) {
            if (coin <= val and dp[val-coin]!=INT_MAX)
            dp[val] = min(dp[val], 1+dp[val-coin]);
        }
    } 
    if (dp[x]==INT_MAX) cout << -1;
    else cout <<dp[x];
    cout<<'\n';
}
vector<int> digits(int no) {
    vector<int> v;
    while(no) {
        if (no%10)
        v.push_back(no%10);
        no = no/10;
    }
    return v;
}
void minSteps() {
    int no; cin >> no;
    int dp[no+1];
    dp[0] = 0;
    for(int i = 1; i <= no; i++) {
        dp[i] = 1e6;
        vector<int> v = digits(i);
        for(int dig: v) {
            dp[i] = min(dp[i], 1+dp[i-dig]);
        }
    }
    cout << dp[no] << endl;
}
void bookShop(){
    int n, x; cin >> n >> x;
    // maximum page I can buy for with x amount
    // dp[amount]: maximum pages I can buy with this amount
    vector<int>h(n), s(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    int dp[x+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int am = 1; am <= x; am++) {
            if (h[i-1] <= am) {
                dp[am] =max(dp[am], s[i-1]+dp[am-h[i-1]]);
            }
        }
    }
    for(int am = 1; am <= x; am++) {
        cout << am << " " << dp[am] << endl;
    }
    cout << dp[x] << endl;       
}
void med() {
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<ll> median;

    multiset<ll> ms;
    auto it = ms.begin();
    for(int i = 0; i < n; i++){
        ms.insert(nums[i]);

        if (ms.size() > k) {
            ms.erase(ms.find(nums[i-k]));
        }
        if(ms.size() == k) {
            it = next(ms.begin(), k/2);

            if(k%2) {
                median.push_back(*it);
            } else {
                median.push_back((*it+*prev(it))/2);
            }
        }
    }
    for(auto num: median) {
        cout << num << " ";
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    med();
    // minSteps();
    // bookShop();
    // minCoins();
    // coinCombo2();
    // int n; cin >> n;
    // vector<int>dp(n+1, 0);
    // dp[0] = 1;
    // for(int i = 1; i <= n; i++ ) {
    //     dp[i] = 0;
    //     for(int dice = 1; dice <= 6 && dice <= i; dice++) {
    //         dp[i] = (dp[i]+dp[i-dice]);
    //     }
    // }

    // cout << dp[n] << "\n";
}