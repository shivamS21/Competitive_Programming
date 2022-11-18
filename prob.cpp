#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
void solve(int blue, int red){
    if(red==0){
        cout<<"BLUE is left";
        return;
    }
    if(blue==0){
        cout<<"RED is left";
        return;
    }
    //blue+blue
    if(blue>1)
        solve(blue-1, red);
    
    //blue+red
    if(red>0 and red>0)
    solve(blue-1, red);

    //red+red
    if(red>1)
    solve(blue+1, red-2);
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve(20, 14);
}
