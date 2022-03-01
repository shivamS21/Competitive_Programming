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
double dp[301][301][301];
double expect(int one, int two, int three, int n){
    if(one < 0 or two < 0 or three < 0) return 0;
    if(one == 0 and two ==0 and three == 0) return 0;
    if(dp[one][two][three]>0) return dp[one][two][three];
    int total = one + two + three;
    double ans = (n + one * expect(one-1, two, three, n) + two * expect(one+1, two-1, three, n) + three * expect(one, two+1, three-1, n));
    return dp[one][two][three] = ans / total;
}
void solve(){
    ll m,n,k;
    cin >> n;
    int three = 0, one = 0, two = 0;
    memset(dp, -1, sizeof(dp)); 
    for(int i = 0;i < n; i++){
        int a; cin >> a;
        if(a==1) ++one;
        else if(a==2) two++;
        else three++;
    }
    cout<<fixed << setprecision(9)<<expect(one, two, three, n);
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
} 