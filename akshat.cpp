#include<bits/stdc++.h>
using namespace std;
int findPoints(vector<vector<int>>&points, int n){
    sort(points.begin(), points.end());

    unordered_map<int,int> mp;
    for(auto v: points){
        mp[v[1]]++;
    }

    vector<int> point;
    for(auto p: mp)        point.push_back(p.first);
    
    vector<pair<int,int> > pp;

    for(int i = 0; i < point.size(); i++){
        for(int j = i+1; j < point.size(); j++){
            pp.push_back({point[i], point[j]});
        }
    }
    int ans = 0;
    for(auto v: pp){
        int y1 = v.first;
        int y2 = v.second;

        int i = 0, local = 0;
        while(i < n){
            int x = points[i][0];
            int f1 = false, f2 = false, j = i;
            while(j < n and points[j][0] == x){
                if(points[j][1] == y1)
                    f1 = true;
                if(points[j][1] == y2)
                    f2 = true;
                j++;
                i++;
            }
            if(f1 and f2)
                ++local;
        }

        ans = max(ans, local);
    }
    return ans;
}
int main(){
    int n; cin >> n;
    vector<vector<int>> points(n, vector<int>(2, 0));

    for(int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];
    
    cout << findPoints(points, n);
}