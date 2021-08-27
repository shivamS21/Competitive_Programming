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
 
void solve(){
    ll m,n,k,q;
    cin >> n >>q;
    string s; cin >> s;
    vector<int> pre(n+1, 0);
    int temp = 1;
    rep(i,0,n){
        if(s[i] == '+')
        pre[i+1] = pre[i] + temp;
        else pre[i+1] = pre[i] - temp;
        temp = -temp;
    }
    rep(i,0,q){
        int l, r; cin >> l >> r;
        int sum = pre[r] - pre[l-1];
        if(sum == 0) cout << 0 << endl;
        else if(sum%2) cout << 1 << endl;
        else cout << 2 << endl;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 