class TrieNode {
    vector<TrieNode*> nodes;
    int childCnt;
    
    public :
    
    TrieNode() {
        nodes = vector<TrieNode*>(26, NULL);
        childCnt = 0;
    }
    
    bool hasNode(char c) {
        return nodes[c - 'a'] != NULL;
    }
    
    TrieNode * getNode(char c) {
        return nodes[c - 'a'];
    }
    
    void setNode(char c, TrieNode *node) {
        nodes[c - 'a'] = node;
    }
    
    void incChildCnt() {
        childCnt++;
    }
    
    int getChildCnt() {
        return childCnt;
    }
};

class Trie{
    TrieNode *root;
    int totalInsertions;
    public :
    
    Trie() {
        root = new TrieNode();
        totalInsertions = 0;
    }
    
    void insert(string s) {
        TrieNode *cur = root;
        for(int i=0; i<s.size(); i++) {
            
            char c = s[i];      
            if(!cur->hasNode(c)) {
                int insertions = cur->getChildCnt() == 0 ? 1 : i+1;
                if(cur -> getChildCnt() > 0 && cur != root) insertions++;
                totalInsertions += insertions;
                cur->setNode(c, new TrieNode());
                cur->incChildCnt();
            }
            cur = cur->getNode(c);
        }
    }
    
    int getMinEncodingLength() {
        return totalInsertions + root->getChildCnt();
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie *trie = new Trie();
        for(string s : words) {
            reverse(s.begin(), s.end());
            trie->insert(s);
        }
        return trie->getMinEncodingLength();
    }
};





