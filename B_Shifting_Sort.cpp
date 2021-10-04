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
    ll m,n,k=0;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n) cin >> arr[i];
    vector<int> temp = arr;
    sorta(temp);
    // print(temp);
    vector<vector<int> > ans;
    for(int i = 0; i < n; i++){
        if(temp[i] == arr[i]) continue;
        int mn = i;
        rep(j,i,n){
            if(arr[j] < arr[mn]) mn = j;
        }
        //cout << "mn " << mn << endl;
        if(mn == i) continue;
        int shift = mn - i;
        vector<int> p;
        p.pb(i+1);
        p.pb(i+shift+1);
        p.pb(shift);
        ans.pb(p);
        int pp = arr[i+shift];
        for(int j = i+shift; j > i; j--) arr[j] = arr[j-1];
        arr[i] = pp;
        // print(arr);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 