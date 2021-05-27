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
ll dp[3005][3000][2];
vector<ll>arr(3005);
ll n;
ll calc(ll i, ll j, ll x, ll y, int chance){
    if(i>j)
    return 0;
    ll &res = dp[i][j][chance];
    if(res != -1)
    return res;
    if(!chance){
        res = max(x+arr[i] - y + calc(i+1,j,x+arr[i],y,1), x+arr[j] -y + calc(i,j-1,x+arr[j],y,1));
    }
    else
    res = min(x-arr[i]-y + calc(i+1,j,x,y+arr[i],0), x - arr[j]- y + calc(i,j-1,x,y+arr[j],0));
    return res;
}

void solve(){
   cin >> n;
   rep(i,0,n) cin >> arr[i];
    cout << max(arr[0]+calc(1,n-1,arr[0],0,1), arr[n-1]+calc(0,n-2,arr[n-1],0,1));
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    mem(dp,-1);

    while(tt--){
        solve();
    
    }
}
 
 
 
 
// g++ -std=c++17