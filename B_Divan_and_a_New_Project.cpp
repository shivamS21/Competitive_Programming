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
    ll m,n,k;
    cin >> n;
    vector<pair<ll,ll> > vec(n);
    rep(i,0,n){
        cin >> vec[i].first;
        vec[i].second = i;
    }
    sort(vec.rbegin(), vec.rend());
    vector<ll> ans(n+1, 0);
    ll f = 0, a = 1, b = -1;
    ll time = 0;
    rep(i,0,n){
        if(!f){
            //shift to right
            time += 2 * a * vec[i].first;
            ans[vec[i].second+1] = a;
            a += 1;
        } else{
            time += 2 * abs(b) * vec[i].first;
            ans[vec[i].second+1] = b;
            b -= 1;
        }
        f = 1 - f;
    }
    cout << time << endl;
    print(ans);
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 