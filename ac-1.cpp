#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int find_sum(string s) {
    int n = s.length();
    int first=-1, second=-1;
    for(char c: s) {
        if (c-'0' >=0 && c-'0' <= 9) {
            if (first == -1) first = c-'0';
            else {
                second = c-'0';
                break;
            }
        }
    }
    if (second == -1) second = first;

    return first*10+second;
}
int main(){
    int sum = 0;
    while(true) {
        string st; 
        cin >> st;
        sum += find_sum(st);
        cout << sum << endl;
    }
}