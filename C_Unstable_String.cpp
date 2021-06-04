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
    ll n,count=1;string s;
    cin >> s;
    n=s.length();
    vector<ll> dp(n,0),zero(n,-1),one(n,-1);
    rep(i,0,n){
        if(s[i]=='0') zero[i] = i;
        else if(i > 0) zero[i] = zero[i-1];
    }
    rep(i,0,n){
        if(s[i]=='1') one[i]=i;
        else if(i > 0) one[i]=one[i-1];
    }
    ll index;
    rep(i,1,n){
        if(s[i]=='?') dp[i]=dp[i-1];
        //now checking for one and zero
        else if(s[i] == '0'){
            if(zero[i-1]==one[i-1]) dp[i]=0;
            else if(zero[i-1]>one[i-1]){
                index =zero[i-1];
                if((index & 1) == (i & 1)) dp[i]=dp[index];
                else dp[i]=index+1;
            }
            else{
                index =one[i-1];
                if((index & 1) != (i & 1)) dp[i]=dp[index];
                else  dp[i]=index+1;
            }
        }
        else if(s[i]=='1'){
            if(zero[i-1]==one[i-1]) dp[i]=0;
            else if(zero[i-1]>one[i-1]){
                index =zero[i-1];
                if((index & 1) != (i & 1)) dp[i]=dp[index];
                else dp[i]=index+1;
            }
            else{
                index =one[i-1];
                if((index & 1) == (i & 1)) dp[i]=dp[index];
                else dp[i]=index+1;
            }
        }
        count+=(i-dp[i]+1);
    }
    cout<<count<<endl;

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 