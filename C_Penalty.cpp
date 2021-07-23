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

int ans = 10;
vector<int> p1(10), p2(10);
void rec(string s, int s1, int s2, int val, int index){
    if(index==s.length()) return;
    val += 1;
    if(index%2){
        if(s[index]=='1'){
            if(s1+p1[index] < s2+p2[index] and s1 < s2+1){
                cout << "evain " << index <<" "<< s1 << " " << s2 << endl; 
                ans = min(ans, val);
                return;
            }
        }
        else if(s[index]=='?'){
            int val1 = s2+p2[index];
            cout << "shivam " << s1 << " " << s2+1 << endl;
            if(s1 + p1[index] < val1 and s1 < s2+1){
                ans = min(ans, val);
                return;
            }
            
        }
    } else{
        if(s[index]=='1'){
            if(s1+p1[index] > s2+p2[index] and s1+1>s2){
                cout << "evain " << index <<" "<< s1 << " " << s2 << endl; 
                ans = min(ans, val);
                return;
            }
        }
        else if(s[index]=='?'){
            int val1 = s1+p1[index];
            
            if(s2 + p2[index] < val1 and s1+1>s2){
                ans = min(ans, val);
                return;
            }
            
        }
    }

    if(index%2){
        //second team
        if(s[index]=='1'){
            rec(s, s1, s2+1, val, index+1);
        }
        else if(s[index]=='?'){
            rec(s, s1, s2+1, val, index+1);
            rec(s, s1, s2, val, index+1);
        }
    } else{
        if(s[index]=='1'){
            rec(s, s1+1, s2, val, index+1);
        }
        else if(s[index]=='?'){
            rec(s, s1+1, s2, val, index+1);
            rec(s, s1, s2, val, index+1);
        }
    }
}
void solve(){
    ll m,n,k;
    string s; cin >> s;
    ans = 10;
    rrep(i,9,-1){
        if(i%2){
            //2nd team
            if(i==9){
                if(s[i] == '1' or s[i] == '?') p2[i] = 1;
                else p2[i] = 0;
            } else{
                if(s[i] == '1' or s[i] == '?') p2[i] = 1;
                else p2[i] = 0;
            }
        } else{
            if(s[i] == '1' or s[i] == '?') p1[i] = 1;
            else p1[i] = 0;
        }
    }
    rrep(i,8,-1){
        p1[i] = p1[i+1] + p1[i]%2;
        p2[i] = p2[i+1] + p2[i]%2;
    }
    rec(s, 0, 0, 0, 0);
    print(p1);
    print(p2);
    cout << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 