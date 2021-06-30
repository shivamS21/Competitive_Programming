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
    ll n,l;
    cin >> n >> l;
    vector<double> vec(n);
    rep(i,0,n){
        cin >> vec[i];
    }
    double ans = 0.0;
    double cura = 0, curb = l;
    int s1=1 , s2 = 1;
    int i = 0, j = n-1;
    while(i <= j){
        double dis1 = vec[i] - cura;
        double dis2 = curb - vec[j];
        double t1 = dis1 * 1.0 / s1;
        double t2 = dis2 * 1.0 / s2;
        if(t1 <= t2){
            ans += t1;
            cura += dis1;
            curb -= s2 * 1.0 * t1;
            s1 += 1;
            i += 1;
        }
        else{
            ans += t2;
            curb -= dis2;
            cura += s1 * 1.0 * t2;
            s2 += 1;
            j -= 1;
        }
    }
    double dis = curb - cura;
    ans += dis / (s1 + s2);
    cout << fixed << setprecision(12) << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 