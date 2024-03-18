#include<iostream>
using namespace std;
class trieNode{
    public:
    char data;
    trieNode * trieChild[26];
    bool isTerminal;


    trieNode(char ch){
        data = ch;
        for(int i = 0; i<26; i++){
            trieChild[i] = NULL;
        }
        isTerminal = false;
    }

};
class trie{
    public:
    trieNode* root;
    trie(){
        root = new trieNode('\0');
    }

    void insertUtil(trieNode* root, string word){
        //base Case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        trieNode* child;
        //absent
        if(root->trieChild[index] != NULL){
            child = root->trieChild[index];

        }
        else{
            //preesnt
            child = new trieNode(word[0]);
            root->trieChild[index] =child;
        }
        insertUtil(child, word.substr(1));

    }
    void insertword(string word){
        insertUtil(root, word);
    }

    bool searchUtil(trieNode* root, string word){
        // base case 
        if(word.length() == 0) return root->isTerminal;

        int index = word[0]-'A';
        trieNode* child;

        if(root->trieChild[index] != NULL){
            //present
            child = root->trieChild[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }



    int searchWord(string word){
        return  searchUtil(root,word);
    }


    

};

int main(){
    trie*t = new trie();
    t->insertword("RAM");
    t->insertword("RAMESH");
    t->insertword("ABHI");
    t->insertword("ABHISHEK");
    t->insertword("VIPIN");

    
  int res  = t->searchWord("ABHI");
  res? cout<<"present": cout<<"absent";
  cout<<endl;
  cout<<endl;
  cout<<endl;


 
return 0;
}       