#include<bits/stdc++.h>
using namespace std;
class A
{
    public:
    int x;
    A(){
        cout << "_____CLASS A_______" << endl;
        cout << "Value of x:"; cin >> x; cout << endl;
        cout << "Value of y:"; cin >> y; cout << endl;
        cout << "Value of z:"; cin >> z; cout << endl;
    }
    protected:
    int y;
    private:
    int z;
    
};
class B: public A
{
    public:
    B(){
        cout << "This is public class B" << endl;
        cout << "Value of y in child class: " << y << endl;
        cout << "Value of x in child class: " << x << endl;
    }
};
class C: protected A
{
    public:
    C(){
        cout << "This is protected class C" << endl;
        cout << "Value of y in child class: " << y << endl;
        cout << "Value of x in child class: " << x << endl;
    }
};
class D: private A
{
    public:

    D(){
        cout << "This is private class D" << endl;
        cout << "Value of y in child class: " << y << endl;
        cout << "Value of x in child class: " << x << endl;
    }
    
};
//multiple inheritance
class G
{
    public:
    int y;
    G(){
        cout << "____class G____" << endl;
        cout << "Value of x in class G: "; cin >> y; cout << endl;
    }
};
class F: public A, protected G
{
    // int x;
    public:
    F(){
        cout << "____class F____" << endl;
        // cout << "Value of x: "; cin >> x; cout << endl;
        // cout << x << endl;
        cout << "Value of x in A: " << x << endl;
    }
};
int main(){
    F f;
}