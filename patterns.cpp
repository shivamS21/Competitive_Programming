#include<bits/stdc++.h>
using namespace std;
#define print(v) for(int ele: v) cout << ele << " "; cout << endl;
void pattern1(){
    //hollow pyramid, half pyramid
    /*
        *******
        *    *
        *   *
        *  *
        * *
        **
        *
    */
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    cout<<"*"; cout << endl;

    for(int i = 0; i < n-1; i++){
        cout<<"*";
        for(int j = 0; j < n-2-i; j++){
            if(j==n-3-i)
            cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}
void pattern2(){
    int n; cin >> n;
    vector<string> v;
    string s = "";
    for(int i = 0; i < n; i++){
        s += "* ";
    }
    s.pop_back();
    v.push_back(s);
    // cout<<s<<endl;
    for(int i = n-1; i >= 1; i--){
        int j = i;
        int f = 0;
        for(char &c: s){
            if(c==' ')
            c = '*';
            else
            c = ' ';
        }
        for(int j = 0; j < n-i; j++)
        s[j]=' ', s[s.length()-1-j]=' ';
        v.push_back(s);
        // cout<<s<<endl;
    }
    
    reverse(v.begin(), v.end());
    for(auto x: v)
        cout << x << endl;
}
void pattern3(){
    vector<vector<int>> pascal;
    vector<int> v;
    v.push_back(1);
    pascal.push_back(v);
    v.push_back(1);
    pascal.push_back(v);
    for(int i = 1; i <= 10; i++){
        v.clear();
        v.push_back(1);
        for(int j = 1; j <= i; j++)
            v.push_back(pascal[i][j-1]+pascal[i][j]);
        v.push_back(1);
        pascal.push_back(v);
    }

    for(auto x: pascal){
        for(int ele: x)
            cout << ele << " ";
            cout<<endl;
    }
}
int main(){
    // pattern1();
    // pattern2();
    pattern3();
}