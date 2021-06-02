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
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> q(k);
    rep(i,0,k){
        cin >> q[i];
    }
    if(n==1){
        rep(i,0,k)
        cout<<0<<endl;
        return;
    }
    int count = 0;
    rep(i,1,n){
        if(s[i-1] == s[i])
        count += 2;
        else count += 1;
    }
    rep(i,0,k){
        int index = q[i]-1;
        if(index == 0){
            if(s[0] == s[1])
            count -= 1;
            else count += 1;
        }
        else if(index == n-1){
            if(s[n-1] == s[n-2])
            count -= 1;
            else count += 1;
        }
        else{
            if(index-1 > -1){
                if(s[index] == s[index-1])
                count -= 1;
                else count += 1;
            }
            if(index+1 < n){
                if(s[index] == s[index+1])
                count -= 1;
                else count += 1;
            }
        }
        if(s[index]=='1')
        s[index]='0';
        else s[index]='1';
        cout<<count<<endl;
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
 