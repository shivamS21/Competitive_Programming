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
    vector<ll> vec(3);
    cin >> vec[0] >> vec[1] >> vec[2];
    sorta(vec);
    if(vec[2]==vec[0]+vec[1])cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
