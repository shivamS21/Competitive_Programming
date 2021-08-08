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
ll power(ll no,ll p)
{
    if(p == 1)
    return no;
    if(p == 0)
    return 1;
    ll q = power(no,p/2);
    q = (q*q);
    if(p % 2 != 0)
    q = (q*no);
    return q;
}
void solve(){
    ll m,n,k,x;
    cin >> n >> x;
    if(x == 0){
        cout << -1 << endl;
    }
    else{
        k = 0;
        while(n > 1){
            if(n <= x){
                n = 0;
                ++k;
                continue;
            }
            ll p = ll(log2(n));
            // cout << n << " " << p << endl;
            if(p%2==0)
            p -=1;
            n -= power(2, p);
            ++k;
        }
        // cout << n << endl;
        if(n == 1) ++k;
        cout << k << endl;
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
 