#include<bits/stdc++.h>

using namespace std;


class WordDictionary {

public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        cout<<word<<" \n";
        
        WordDictionary* root = this;
        
        for(int i = 0;i<26;i++){
            if(root->children[i])
                cout<<i<<"\n";
        }
        
        for(int i = 0;i<word.length();i++){
        
            if(!root->children[word[i]-'a']){ 
        
                root->children[word[i]-'a'] = create_node();
            }
        
            root = root->children[word[i]-'a'];
        }
        
        root->is_word = true;
    }
    
    bool modified_search(WordDictionary* root, string word){
        
        for(int i = 0;i<word.length();i++){

            if(word[i]=='.'){
                
                for(int j = 0;j<26;j++){

                    if(root->children[j]){

                        if(i+1>=word.length())
                            return true;
                        
                        string temp = word.substr(i+1);
                        
                        if(modified_search(root->children[j],temp))
                            return true; 
                    }

                }
                return false;
                
            }else{
                if(!root->children[word[i]-'a']){
                    return false;
                }
            }
            root = root->children[word[i]-'a'];
        }
        
        return root->is_word;
    }
    
    bool search(string word) {
        
        WordDictionary* root = this;
        
        for(int i = 0;i<word.length();i++){

            if(word[i]=='.'){
                
                for(int j = 0;j<26;j++){

                    if(root->children[j]){

                        if(i+1>=word.length())
                            return true;
                        
                        string temp = word.substr(i+1);
                        
                        if(modified_search(root->children[j],temp))
                            return true; 
                    }

                }
                return false;
                
            }else{
                if(!root->children[word[i]-'a']){
                    return false;
                }
            }
            root = root->children[word[i]-'a'];
        }

        return root->is_word;
    }
    
    
private:
    
    WordDictionary* children[26];
    bool is_word = false;
    
    WordDictionary* create_node(){
        WordDictionary* node = new WordDictionary;
        
        // for(int i = 0;i<26;i++)
        //     node->children[i] = NULL;

        return node;
    }
    
};


int main(){

    WordDictionary* obj = new WordDictionary();

    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");

    cout<<obj->search("pad")<<" "<<obj->search("bad")<<" "<<obj->search(".ad")<<" "<<obj->search("b..")<<"\n";

    // obj->addWord("Prakash");
    // obj->addWord("nath");
    // obj->addWord("jha");
    
    // cout<<obj->search("n..h.")<<" "<<obj->search("j.a")<<" "<<obj->search(".ha")<<" "<<obj->search("jbs.")<<" "<<obj->search("...")<<"\n";

    return 0;
}





