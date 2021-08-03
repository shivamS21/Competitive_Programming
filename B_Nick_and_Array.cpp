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
 
bool comp(pair<int,int> x,pair<int,int> y){
    return x.first > y.first;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<int> vec(n);
    rep(i,0,n) {
        cin >> vec[i];
        if(vec[i] >= 0) vec[i] = -vec[i] - 1;
    }
    if(n%2){
        int ind = -1, mx = -1;
        rep(i,0,n){
            if(abs(vec[i]) > mx){
                mx = abs(vec[i]);
                ind = i;
            }
        }
        vec[ind] = -vec[ind]-1;
    }
    print(vec);
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 