#include <bits/stdc++.h>
using namespace std;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
/*...............code starts here................*/
ll calculate_perimeter(vector<pair<ll,ll>>&rectangle){
    ll widthSum = 0, maxHeight = 0;

    for(auto &p: rectangle){
        widthSum += min(p.first, p.second);
        maxHeight = max(maxHeight, max(p.first, p.second));
    }

    return (widthSum+maxHeight)*2;
}
void solve(){
    ll n; cin >> n;
    vector<pair<ll,ll>> rectangle(n);
    for(auto &p: rectangle){
        cin >> p.first >> p.second;
        if(p.first > p.second)
        swap(p.first, p.second);
    }
    cout<<calculate_perimeter(rectangle)<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
