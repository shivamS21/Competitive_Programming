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
    int n;
    cin >> n;
    string s; cin >> s;
    int a = 0;
    for(auto x: s)
    if(x == '0') a+=1;
    if(!a){
        cout<<"DRAW"<<endl;
        return;
    }
    if(n%2==0){
        cout<<"BOB"<<endl;
    }
    else{
        if(s[n/2]=='0' and a != 1){
            cout<<"ALICE"<<endl;
        }
        else cout<<"BOB"<<endl;
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