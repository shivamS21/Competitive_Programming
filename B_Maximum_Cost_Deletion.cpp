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
// int oper(string &s){
//     int l = s.length();
//     int len = 0;
//     int count = 1;
//     char c = s[0];
//     int index = 0, indextemp = 0;
//     rep(i,1,l){
//         if(s[i] == c){
//             ++count;
//         } else{
//             if(count > len){
//                 len = count;
//                 index = indextemp;
//             }
//             count = 1;
//             indextemp = i;
//             c = s[i];
//         }
//     }
//     if(count > len){
//         len = count;
//         index = indextemp;
//     }
//     s.erase(s.begin()+index, s.begin()+index+count);
//     return len;
// }
vector<int> oper(string s, char c){
    int n = s.length();
    int count = 0;
    vector<int> temp;
    rep(i,0,n){
        if(s[i]==c)++count;
        else{
            if(count!=0)
            temp.pb(count);
            count = 0;
        }
    }
    if(count!=0)
    temp.pb(count);
    return temp;
}
void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    if(b>0)
    cout << n * (a+b) << endl;
    else{
        vector<int> zero = oper(s, '0');
        vector<int> one = oper(s, '1');
        // print(zero);
        // print(one);
        int ans1 = 0, ans2 = 0, z = 0;
        rep(i,0,zero.size()){
            ans1 += zero[i]*a+b;
            z += zero[i];
        }
        rep(i,0,one.size())
        ans2 += one[i]*a+b;
        cout << max(ans1 + (n-z)*a+b, ans2 + z*a+b) << endl;
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
 