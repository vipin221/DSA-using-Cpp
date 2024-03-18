#include<iostream>
using namespace std;
    class trieNode{
        public:
        char data;
        trieNode* trieChild[26];
        bool isTerminal;

        trieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                trieChild[i]= NULL;
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
            // base case
            if(word.length()== 0) {
            root->isTerminal  = true;
            return;
            }

            int index = word[0] - 'a';
            trieNode* child;

            if(root->trieChild[index] != NULL){
                // if present ->just move forward(down)
                child = root->trieChild[index];
            }
            else{
                // if absent create a child and attach it just below the index
                child = new trieNode(word[0]);
                root->trieChild[index] = child;
            }

            insertUtil(child, word.substr(1));
            
        }

        void insertword(string word){
            insertUtil(root,word);
        }

        bool searchUtil(trieNode* root,string word){
                // base case 
                if(word.length()== 0){
                    
                    return root->isTerminal;
                }
                int index = word[0] - 'a';
                trieNode* child;

                if(root->trieChild[index] != NULL){
                    // if present  ust move further
                    child = root->trieChild[index];
                }else{
                    // not present 
                    return false;
                }
           return searchUtil(child, word.substr(1));
        }
        int searchword(string word){
             return searchUtil(root, word);
        }


           void removeUtil(trieNode* root,string word){
                // base case 
                if(word.length()== 0 ){
                    if(root->isTerminal = true ){
                        root->isTerminal = false;
                    }
                    return;
                    
                }
                int index = word[0] - 'a';
                trieNode* child;

                if(root->trieChild[index] != NULL){
                    // if present  ust move further
                    child = root->trieChild[index];
                }else{
                    return ;
                }
           return removeUtil(child, word.substr(1));
        }
        void removeword(string word){
             return removeUtil(root, word);
        }

    
    };

int main(){

    trie* t = new trie();
    t->insertword("ramji");
    t->insertword("vipin");
    t->insertword("maurya");
    t->insertword("somya");
    int res = t->searchword("vipin");
    res? cout<<"present": cout<<"absent";
    cout<<endl;
    t->removeword("vipin");
    t->removeword("somya");
    t->searchword("vipin")? cout<<"present": cout<<"absent";
    cout<<endl;
    t->searchword("somya")? cout<<"present": cout<<"absent";
    cout<<endl;

return 0;
}