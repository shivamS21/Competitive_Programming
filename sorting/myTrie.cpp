#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *links[26];
    bool isEnd;
    Node(){
        for(auto &link: links) link = NULL;
        isEnd = false;
    }
};
struct Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string &key){
        Node* dummyNode = root;
        for(int i = 0; i < key.length(); i++){
            int index = key[i]-'a';
            if(!dummyNode->links[index])
            dummyNode->links[index] = new Node();
            dummyNode = dummyNode->links[index];
        }
        dummyNode->isEnd = true;
    }

    bool search(string &key){
        Node* dummyNode = root;
        for(int i = 0; i < key.length(); i++){
            int index = key[i]-'a';
            if(!dummyNode->links[index]) return false;
            dummyNode = dummyNode->links[index];
        }
        return dummyNode->isEnd;
    }
    bool startsWith(string &key){
        Node* dummyNode = root;
        for(int i = 0; i < key.length(); i++){
            int index = key[i]-'a';
            if(!dummyNode->links[index]) return false;
            dummyNode = dummyNode->links[index];
        }
        return true;
    }
};
int main(){
    struct Trie *root = new Trie();
    vector<int> instructions = {1, 2, 1, 2, 1};
    vector<string> v = {"hello", "hello", "hell", "hello", "hell"};
    for(int i = 0; i < instructions.size(); i++){
        int instruct = instructions[i];
        if(instruct == 1){
            // Insert
            root->insert(v[i]);
            cout << v[i] << " inserted" << endl;
        } else if(instruct == 2){
            cout << v[i] << " ";
            if( root->search(v[i]))
            cout << "present is there!!" << endl;
            else cout << "not present" << endl;
        } else if(root->startsWith(v[i])){
            cout << v[i] << " is there!" << endl;
        } else cout << "doesn't start with " << v[i] << endl;
    }
}

