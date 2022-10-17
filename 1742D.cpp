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
    ll n;
    cin >> n;
    vector<int> arr(n);
    for(auto &it: arr) cin >> it;
    map<int,set<int>> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]].insert(i+1);
    }
    int ans = -1;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        for(auto it2 = it; it2!=mp.end(); it2++){
            if(__gcd(it->first, it2->first)==1){
                ans = max({ans, *(it->second.begin())+*(it2->second.begin()), *(it->second.begin())+*(--(it2->second.end())), 
                            *(--(it->second.end()))+*(it2->second.begin()), *(--(it->second.end()))+*(--(it2->second.end()))});
            }
        }
    }
    cout<<ans<<endl;

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
