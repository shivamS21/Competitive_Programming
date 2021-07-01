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
    cin >> n >> m;
    vector<pair<int,int> > arr(m);
    rep(i,0,m) cin >> arr[i].first >> arr[i].second;
    int c1 = 0, c2 = 0, try1 = arr[0].first, try2 = arr[0].second;
    map<int,int> s1, s2;
    rep(i,0,m){
        if(arr[i].first != try1 and arr[i].second != try1){
            s1[arr[i].first] += 1;
            s1[arr[i].second] += 1;
            c1 += 1;
        }
        if(arr[i].first != try2 and arr[i].second != try2){
            s2[arr[i].first] += 1;
            s2[arr[i].second] += 1;
            c2 += 1;
        }
    }

    int f = 0;
    for(pair<int,int> p: s1){
        if(p.second == c1){
            f = 1;
            break;
        }
    }
    for(pair<int,int> p: s2){
        if(p.second == c2){
            f = 1;
            break;
        }
    }
    if(f or(c1==0 and c2 == 0)) cout << "YES";
    else cout << "NO";
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 