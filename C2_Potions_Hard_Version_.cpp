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
vector<ll> vec(200005);
ll n;
void solve(){
    ll count = 0, ans = 0;
    cin>>n;
    rep(i,0,n) cin >> vec[i];
    //making priority queue
    
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    rep(i,0,n){
        count+=1;ans+=vec[i];
        if(vec[i]<0) pq.push(vec[i]);
        if(ans<0){
            count--;
            ans-=pq.top();
            pq.pop();
        }
    }
    cout<<count<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve(); 
    }
}
 