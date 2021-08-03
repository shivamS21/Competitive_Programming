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
    string a, b; cin >> a >> b;
    int ans = 0;
    vector<int> occup(n, -1);
    rep(i,0,n){
        if(a[i] == '0' and b[i] == '1'){
            ++ans;
            occup[i] = 1;
        }
        else if(b[i] == '1'){
            if(i != 0 and occup[i-1] == -1 and a[i-1] =='1'){
                occup[i-1] = 1;
                ++ans;
            } else if(i != n-1 and occup[i+1] == -1 and a[i+1] == '1'){
                occup[i+1] = 1;
                ++ans;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 