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
    // cin >> n;
    string s; cin >> s;
    n = s.length();
    int index = -1;
    int no;
    for(int i = 0; i < n-1; i++){
        int a = s[i]-'0', b = s[i+1]-'0';
        int c = a+b;
        // cout << c << endl;
        if(c > 9){
            index = i;
            no = c;
        }
    }
    if(index!=-1){
        //double digit sum is present
        string p = to_string(no);
        s[index]= p[0];
        s[index+1] = p[1];
        cout << s << endl;
    }
    else{
        int c = (s[0]-'0')+(s[1]-'0');
        char d = c+'0';
        s[1]=d;
        for(int i = 1; i < n;i++) cout<< s[i];
        cout << endl;
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
 