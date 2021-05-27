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
    vector<ll> vec(n);
    rep(i,0,n) cin >> vec[i];
    map<ll,int> mp;
    for(ll i: vec)
    mp[-i] += 1;
    vector<int> count;
    for(pair<int,int> p: mp)
    count.pb(p.second);
    int g = count[0];
    int s = 0, i = 1;
    while(s <= g and i < count.size())
    s += count[i++];
    int ok = 0;
    if(s>g){
        int b = 0;
        while(b <= g and i < count.size()){
            b += count[i++];
        }
        while(i < count.size() and g+s+b+count[i] <= n/2 )
        b += count[i++];
        if(g < b and g < s and g+s+b <= n/2){
            ok = 1;
            cout<<g<<" "<<s<<" "<<b<<endl;
        }
    }
    if(!ok)
    cout<<"0 0 0"<<endl;
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