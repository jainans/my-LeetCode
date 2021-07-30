class TrieNode {
public:
    char c;
    int ends;
    TrieNode* next[26];
    
    TrieNode(char p){
        c = p;
        ends=0;
        for(int i=0; i<26; i++){
            next[i]=NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root= new TrieNode('/');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p=root;
        for(int i=0; i<word.size(); i++){
            int q = word[i]-'a';
            if(p->next[q]==NULL)
                p->next[q]= new TrieNode(word[i]);
            p = p->next[q];
            
        }
        p->ends+=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(int i=0; i<word.size(); i++){
            int q = word[i]-'a';
            if(p->next[q]==NULL)
                return false;
            p= p->next[q];
        }
        if(p->ends==0)
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* p = root;
        for(int i=0; i<word.size(); i++){
            int q = word[i]-'a';
            if(p->next[q]==NULL)
                return false;
            p= p->next[q];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */