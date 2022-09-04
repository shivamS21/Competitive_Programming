#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(pair<int,int>&a, pair<int,int>&b){
    if(a.first != b.first) return a.first < b.first;

    return a.second < b.second;
}
/*...............code starts here................*/
void solve(){
    int n, q;
    cin >> n >> q;

    vector<pair<int,int>> dim;
    for(int i = 0; i < n; i++){
        int h, w;

        cin >> h >> w;
        dim.push_back({h, w});
    }

    sortd(dim);
    
    // need to find no in range  hs < h < hb and ws < w< wb
    vector<int> height, width;
    for(auto p: dim){
        height.push_back(p.first);
        width.push_back(p.second);
    }

    int area[n];
    area[0] = dim[0].first * dim[0].second;

    for(int i = 1; i < n; i++)
        area[i] = area[i-1] + dim[i].first * dim[i].second;
    for(int i: area)
    cout << i << " "; cout << endl;

    while(q--){

        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        int low = upper_bound(height.begin(), height.end(), hs) - height.begin();
        int high = upper_bound(height.begin(), height.end(), hb-1) - height.begin();
        cout << low << " " << high << endl;
        int low1 = upper_bound(width.begin()+low, width.begin()+high, ws) - width.begin();
        int low2 = upper_bound(width.begin()+low, width.begin()+high, wb-1) - width.begin();
        cout << low1 << " " << low2 << endl;
        if(low2 == n){
            if(low1 == 0)
            cout << area[n-1];
            else cout << area[n-1]-area[low1-1];
        } else{
            if(low1 == 0)
            cout << area[low2];
            else cout << area[low2-1] - area[low1-1];
        }
        cout << endl;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
