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
vector<int> vec;
void Sieve() 
{ 
    ll n = 1e7;
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for(ll p=2;p*p <= n;p+=1) {
        if(prime[p] == true){
           for (ll i=p*p; i<=n; i += p) 
                prime[i] = false;
        }
    }
    rep(i,2,n+1){
        if(prime[i])
        vec.pb(i);
    }
}  
void solve(int n){
    vector<int> p;
    p.pb(1);
    int i = 0;
    for(; vec[i]*vec[i] <= n; i++){
        int ele = vec[i];
        while(n%ele==0){
            p.pb(ele);
            n = n/ele;
        }
    }
    if(n>1)
    p.pb(n);
    rep(i,0,p.size()){
        printf("%d",p[i]);
        if(i == p.size()-1){
            printf("\n");
        }
        else printf(" x ");
    }
}
int main() {
    // FAST_FURIER;
    int n;
    Sieve();
    while(scanf("%d",&n) != EOF){
        solve(n);
    }
}
 