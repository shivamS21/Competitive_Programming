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
bool comp(pair<int,int> x,pair<int,int> y)
{
    if(x.first != y.first)
    return x.first < y.first;
    else y.first < y.second;
}
 
/*...............code starts here................*/
// C is first won in M
ll dp[100005][2];
vector<pair<ll, ll> > v;
ll n;
ll calc(ll i, ll j, ll currtime){
    if(i == n)
    return 0;
    ll &res = dp[i][j];
    if(res != -1){
        return res;
    }
    if(currtime >= v[i].first and currtime <= v[i].second){
        res = max(1+calc(i+1, 1, currtime+1), calc(i+1, 0, currtime));
    }
    else if(currtime < v[i].first){
        res = max(1+calc(i+1, 1, v[i].first+1), calc(i+1, 0, currtime));
    }
    else{
        res = calc(i+1, 0, currtime);
    }
    return res;
}
void solve(){
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);
    // int count = 0;
    // int start = 1;
    // for(pair<ll,ll> i: v){
    //     if(i.first<=start && start<=i.second){
    //         count++;
    //         start++;
    //     }else if(start<i.first){
    //         start = i.first+1;
    //         count++;
    //     }
    // }
    // cout << count << '\n';
    mem(dp, -1);
    dp[0][0] = calc(0, 0, 1);
    dp[0][1] = calc(0, 1, v[0].first+1);
    cout<<max(dp[0][0], dp[0][1])<<endl;

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