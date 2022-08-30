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
    ll n = 6;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    map<int,int> mp1, mp2;
    for(int i = 0; i < nums.size(); i++){
        if(mp1.find(nums[i]) != mp1.end())
            mp1[nums[i]] += nums[i];
        else
            auto it = mp1.lower_bound(nums[i]-1);
            // cout << (*it).first << " " << (*it).second << endl;
            if(it == mp1.begin())
            mp1[nums[i]] = nums[i];
            else mp1[nums[i]] = nums[i]+mp1[(*(--it)).first];
    }
    for(int i = nums.size()-1; i > -1; i--){
        if(mp2.find(nums[i]) != mp2.end())
            mp2[nums[i]] += nums[i];
        else
            auto it = mp2.upper_bound(nums[i]+1);
            if(it==mp2.end())
            mp2[nums[i]] = nums[i];
            else mp2[nums[i]] = nums[i]+mp2[(*it).first];
    }
    int mx = 0;
    for(auto p: mp1){
        mx = max(p.second+mp2[p.first]-p.first, mx);
    }
    cout<< mx;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}

chhapri hai tu, tere gaane saste hain
jo lad nahi skte hain, vo gaali bakte hain