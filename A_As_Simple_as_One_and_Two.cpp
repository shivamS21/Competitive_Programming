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
    string s; cin >> s;
    n = s.length();
    set<int> post;
    rep(i,0,n-2){
        string temp = s.substr(i,3);
        // cout<<temp<<endl;
        if(temp == "two"){
            if(i+3 < n and s[i+3]=='o')
            post.insert(i+2);
            else post.insert(i+3);
        }
        else if(temp == "one"){
            if(i>0 and s[i-1]=='o')
            post.insert(i+2);
            else post.insert(i+1);
        }
    }
    cout<<post.size() << endl;
    string ans = "";
    // rep(i,0,n){
    //     if(post.find(i+1) != post.end()){
    //         continue;
    //     }
    //     ans += s[i];
    // }
    // cout<<ans<<endl;
    while(post.size()){
        cout << *post.begin() << " ";
        post.erase(post.begin());
    }
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