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
 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<int> vec(n+1);
    rep(i,0,n) cin >> vec[i+1];
    int arr[n+1]={0};
    rep(i,1,n+1){
        arr[vec[i]] = i;
    }
    int j = 1, a = arr[1], b = arr[1];
    int ans[n+1]={0};
    ans[1] = arr[1];
    while(j <= n){
        if(arr[j] > a and arr[j] < b){
            if(b-a+1 == j)
            ans[j] = 1;
        }
        else{
            a = min(a, arr[j]);
            b = max(b, arr[j]);
            if(b-a+1 == j)
            ans[j] = 1;
        }
        j += 1;
    }
    rep(i,1,n+1)
    cout<<ans[i];
    cout<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    
    }
}
 
 
 
 
// g++ -std=c++17