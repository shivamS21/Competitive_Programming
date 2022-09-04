#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(pair<ll,ll> &a, pair<ll,ll>&b){
    return a.second > b.second;
}
/*...............code starts here................*/
void solve(){
    ll n;
    cin >> n;

    string st; 
    cin >> st;

    vector<pair<ll,ll>> p;
    
    ll current = 0;
    for(ll i = 0; i < n; i++){
        ll mx = max(i, n-1-i);
        if(st[i] == 'L'){
            current += i;
            p.push_back({i, mx-i});
        }
        else{
            current += n-1-i;
            p.push_back({n-1-i, mx-(n-1-i)});
        }
    }
    sortd(p);

    for(ll i = 0; i < n; i++){

        current = current+p[i].second;
        cout << current<< " ";
    }
    cout << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
