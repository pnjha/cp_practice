#include<bits/stdc++.h>

using namespace std;

vector<vector<bool>> visited;
unordered_set<string> ans_set;

struct TrieNode{
    
    vector<TrieNode*> children = vector<TrieNode*>(26,NULL);
    bool is_end = false;
};


TrieNode* create_node(){
    // TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    TrieNode* node = new TrieNode;
    node->is_end = false;
    
    return node;
}

TrieNode* insert_trie(TrieNode* root,string word){
    
    TrieNode *temp = NULL, *rootptr = root;
    
    for(int i = 0;i<word.length();i++){
        
        if(!rootptr->children[word[i] - 'a']){

            temp = create_node();
            rootptr->children[word[i] - 'a'] = temp;
        }
        rootptr = rootptr->children[word[i] - 'a'];
    }
    
    rootptr->is_end = true;
    
    return root;
}

void dfs(vector<vector<char>>& board, TrieNode* root, int row, int col, string word){
    
    cout<<row<<" "<<col<<" "<<word<<"\n";

    if(row<0||col<0||row>=board.size()||col>=board[0].size()||!root->children[board[row][col] - 'a']||visited[row][col])
        return;
    
    visited[row][col] = true;

    word += board[row][col];
    
    root = root->children[board[row][col]-'a'];
    
    if(root->is_end){
        ans_set.insert(word);
    }
    
    
    dfs(board,root,row-1,col,word);
    dfs(board,root,row,col-1,word);
    dfs(board,root,row+1,col,word);
    dfs(board,root,row,col+1,word);

    visited[row][col] = false;
    word.pop_back();    
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
    
    if(words.size()==0||board.size()==0)
        return vector<string>();
    
    visited.clear();
    ans_set.clear();
    visited.resize(board.size(),vector<bool>(board[0].size(),false));
    
    TrieNode *root = create_node();
    string word = "";

    for(int i = 0;i<words.size();i++){
        root = insert_trie(root,words[i]);
    }
    

    for(int i = 0;i<board.size();i++){
        
        for(int j = 0;j<board[i].size();j++){
            
            dfs(board,root,i,j,word);
        }
    }
    
    
    return vector<string>(ans_set.begin(),ans_set.end());
}

int main(){

    vector<vector<char>> board{{'a','b'},{'c','d'}};
    vector<string> words{"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"};

    vector<string> s = findWords(board,words);

    cout<<"over\n";

    for(int i = 0;i<s.size();i++)
        cout<<s[i]<<"\n";

    return 0;
}