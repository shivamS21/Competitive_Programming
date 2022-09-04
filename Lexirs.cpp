#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
void solve(){
    int n;
    cin >> n;
    string s; cin >> s;

    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];

    pair<string,int> dp[n+1];
    dp[0] = {"", 0};

    for(int i = 1; i <= n; i++){
        dp[i].first = s[i-1];
        dp[i].second = a[1];
        if(dp[i].first > dp[i-1].first){
            if(dp[i].second < dp[i-1].second+a[1]){
                dp[i].second = dp[i-1].second+a[1];
            }
            else if(dp[i].second == dp[i-1].second+a[1] and dp[i-1].first != "")
                dp[i].first = min(dp[i].first, dp[i-1].first);
        }
        string p = "";
        p += s[i-1];
        for(int j = i-1; j > 0; j--){
            p = s[j-1]+p;
            if(p > dp[j-1].first ){
                if(dp[i].second < dp[j-1].second+a[i-j+1])
                    dp[i] = {p, dp[j-1].second+a[i-j+1]};
                else if(dp[i].second == dp[j-1].second+a[i-j+1])
                    dp[i].first = min(dp[i].first, dp[j-1].first);
            }

            int x = i-j+1;
            if(dp[i].second < a[x]){
                dp[i] = {p, a[x]};
            } else if(dp[i].second == a[x])
                dp[i].first = min(dp[i].first, p);
            // cout << i << " " << dp[i].first << " " << dp[i].second << endl;
        }
        
        // cout << i << " " << dp[i].first << " " << dp[i].second << endl;
    }
    // for(int i = 0; i < n+1; i++)
    // cout << dp[i].first << " " << dp[i].second << endl;
    // ; cout << endl;
    cout << max(dp[n].second, 0) << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
