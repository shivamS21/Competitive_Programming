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
    vector<ll> arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    int height = 0;
    vector<int> gp;
    int c = 0;
    rep(i,0,n-1){
        if(arr[i] < arr[i+1]) ++c;
        else {
            gp.pb(c);
            c = 1;
        }
    }
    if(arr[n-1] < arr[n-2])
    gp.pb(1);
    else gp.pb(c);
    // print(gp);
    int child = 1, temp_child = 0;
    rep(i,0,gp.size()){
        temp_child += gp[i];
        child -= 1;
        if(!child){
            child = temp_child;
            temp_child = 0;
            if(i != gp.size()-1)
            ++height;
        }
    }
    cout << height +1 << endl; 
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 