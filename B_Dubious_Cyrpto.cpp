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
    ll l,r,m;
    cin >> l >> r >> m;
    ll mn = l - r, mx = r-l;
    // (m+y)%a == 0; y = 0 or a - m%a;

    rep(a,l,r+1){
        ll y = a - m%a;
        if(y==a)
        y = 0;
        if(y>=mn and y<=mx){

            cout<<a << " "<<l<<" "<<l+y<<endl;
            return;
        }
        y = -1*m%a;
        if(y>=mn){
            cout<<a<<" "<<l+m%a<<" "<<l<<endl;
            return;
        }
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
 