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
    ll x,y; cin >> x >> y;
    ll m = 0, count = 1, sum = 0;
    set<ll> s;
    while(true){
        ll streak = 0;
        while(sum + x*count <= y){
            m += 1;
            streak += 1;
            sum += x*count;count *= 2;
        }
        if(s.find(streak)!=s.end()){
            cout<<-1<<endl;
            return;
        }
        else s.insert(streak);
        count = 1;
        if(sum == y){
            cout<<m << endl;
            return;
        }
        if(x > y - sum){
            cout<<-1<<endl;
            return;
        }
        m += 1;
    }
    
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