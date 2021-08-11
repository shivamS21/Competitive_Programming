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
    int xa, xb, fx, fy, ya, yb;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> fx >> fy;
    if(xa == xb and ya == yb) cout << 0 << endl;
    else{
        if(xa == xb){
            if(fx == xa and fy >= min(ya, yb) and fy <= max(ya, yb))
            cout << abs(ya - yb) + 2 << endl;
            else cout << abs(ya - yb) << endl;
        }
        else if(ya == yb){
            if(fy == ya and fx >= min(xa, xb) and fx <= max(xa, xb)) cout << abs(xa - xb) + 2 << endl;
            else cout << abs(xa - xb) << endl;
        }
        else cout << abs(xa - xb) + abs(ya - yb) << endl;
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
 