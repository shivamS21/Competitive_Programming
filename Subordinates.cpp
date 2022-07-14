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
    pair<int,int> arr[n-1];
    for(int i = 0; i < n-1; i++){
        cin >> arr[i].first;
        arr[i].second = i+2 ;
    }
    sort(arr, arr+n-1);
    int mp[n+3];
    for(int i = 0; i < n+3; i++) mp[i] = 0;
    for(int i = 0; i < n-1; i++) cout << arr[i].first << " "; cout << endl;
    for(int i = 0; i < n-1; i++) cout << arr[i].second << " "; cout << endl;
    for(int i = n-2; i > -1; i--){
        mp[arr[i].first] += 1 + mp[arr[i].second];
        cout << arr[i].first << " " << mp[arr[i].first] << endl;
    }
    for(int i = 1; i <= n; i++) cout << mp[i] << " ";
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
