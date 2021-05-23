//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define mem(v,a) 		 memset(v, a, sizeof(v))
#define M 1000000007
bool comp(ll x,ll y)
{
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
ll arr[1001][1001];
ll x1, x2, yy, y2;
ll dp[1001][1001];
void fill(){
    ll no = 1;
    int i = 1, d = 2;
    while(i <= 1000){
        arr[i][1] = no;
        no += d;
        i += 1;
        d += 1;
    }
    rep(i,1,1001){
        ll d = i;
        rep(j,2,1001){
            arr[i][j] = arr[i][j-1] + d;
            d+=1;
        }
    }
    // rep(i,1,5){
    //     rep(j,1,5){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
ll calc(ll i, ll j){
    ll ans = 0;
    rep(i,x1,x2+1){
        ans += arr[i][yy];
    }
    rep(j,yy+1,y2+1){
        ans += arr[x2][j];
    }
    return ans;
}
void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    x1 = a;
    yy = b;
    x2 = c;
    y2 = d;
    memset(dp,-1,sizeof(dp));
    cout<<calc(x1,x2)<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    fill();
    while(tt--){
        solve();
    
    }
}
 
 
 
 
// g++ -std=c++17