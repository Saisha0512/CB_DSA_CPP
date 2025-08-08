# include <iostream>
# include <map>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

class Node {
public : 
    char data;
    map<char, Node*> children;
    bool terminal;

    Node (char d){
        data = d;
        terminal = false;
    }
};

class Trie {
    Node *root = new Node('\0');

public :
    void insert(string word){
        Node *temp = root;
        for (int i = 0; i < word.size(); i ++){
            char ch = word[i];
            if (temp -> children.count(ch) == 0){
                Node *n = new Node(ch);
                temp -> children[ch] = n;
            }
            temp = temp -> children[ch];
        }
        temp -> terminal = true;
    }

    void prefix_helper(Node *pre_end, string word, vector<string> &prefix){
        word += pre_end -> data;
        if (pre_end -> terminal){
            prefix.push_back(word);
        }
        // Base Case : 
        if (pre_end -> children.empty()){
            return;
        }

        // Recursive Case :   
        for (auto x : pre_end -> children){
            prefix_helper(x.second, word, prefix);
        }
    }

    void prefix(string prefix){
        Node *temp = root;
        vector<string> words;
        string word = prefix;
        for (int i = 0; i < prefix.size(); i ++){
            char ch = prefix[i];
            if (temp -> children.count(ch) == 0){
                cout << "No suggestions" << endl;
                insert(prefix);
                return;
            }
            temp = temp -> children[ch];
        }
        // If prefix is a word itself
        if (temp -> terminal){
            words.push_back(word);
        }
        // For other words
        for (auto x : temp -> children){
            prefix_helper(x.second, word, words);
        }
        sort(words.begin(), words.end());
        if (words.empty()){
            cout << "No suggestions" << endl;
            insert(prefix);
        }
        else {
            for (string s : words){
                cout << s << endl;
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    Trie t;
    for (int i = 0; i < n; i ++){
        string word;
        cin >> word;
        t.insert(word);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i ++){
        string prefix;
        cin >> prefix;
        t.prefix(prefix);
    }
    return 0;
}