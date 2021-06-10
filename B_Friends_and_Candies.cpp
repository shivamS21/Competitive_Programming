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
    ll m,n;
    cin >> n;
    vector<ll> vec(n);
    ll sum = 0;
    rep(i,0,n){
         cin >> vec[i];
         sum += vec[i];
    }
    if(sum % n != 0){
        cout << -1 << endl;
        return;
    }
    sortd(vec);
    int f = 0;
    rep(i,0,n-1){
        if(vec[i] != vec[i+1])
        f = 1;
    }
    if(!f){
        cout << 0 << endl;
        return;
    }
    ll no = sum /n, temp = 0;
    rrep(i,n-1,-1){
        if(vec[i] < no)
        temp += no - vec[i];
        else break;
    }
    int k = 0, ans = 0;
    rep(i,0,n){
        ans += vec[i] - no;
        k += 1;
        if(ans >= temp)
        break;
    }
    cout << k << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 