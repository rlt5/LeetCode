
// Test Cases
// ["Trie","insert","insert","insert","insert","insert","insert","search","search","search","search","search","search","search","search","search","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith"]
// [[],["app"],["apple"],["beer"],["add"],["jam"],["rental"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]
// Expected: [null,null,null,null,null,null,null,false,true,false,false,false,false,false,true,true,false,true,true,false,false,false,true,true,true]

// ["Trie","insert","search","search","startsWith","insert","search"]
// [[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
// ["Trie","insert","insert","insert","insert","insert","insert","search","search","search","search","search","search","search","search","search","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith","startsWith"]
// [[],["app"],["apple"],["beer"],["add"],["jam"],["rental"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"],["apps"],["app"],["ad"],["applepie"],["rest"],["jan"],["rent"],["beer"],["jam"]]
// ["Trie","insert","search"]
// [[],["jam"],["jan"]]


class Trie {
public:
        
    // Definition for a tree node.
    struct Node {
        string val;
        bool wordExists;
        vector<Node*> list;
        Node() : val(""), wordExists(false){}
        Node(string x) : val(x){}
    };            
    
    Node* root;
    
    Node* findNode(Node* node, string val){
        for ( Node* child : node->list ){
            if ( val.compare(child->val) == 0 ){
                return child;
            }
        }
        return nullptr;
    }
    
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        root->wordExists = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i = 0;
        Node* currentNode = root;
        while ( i < word.size() && currentNode ){
            i++;
            if ( findNode(currentNode, word.substr(0,i)) ){
                currentNode = findNode(currentNode, word.substr(0,i));
            } else {
                i--;
                break;
            }
        }
        while ( i < word.size() ){
            i++;
            Node* newNode = new Node(word.substr(0,i));
            // cout << word.substr(0,i) << "," ;
            newNode->wordExists = false;
            currentNode->list.push_back( newNode );
            currentNode = newNode;
        }
        currentNode->wordExists = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word == "")
            return true;
        
        int i = 0;
        Node* currentNode = root;
        // Node* foundNode = findNode(currentNode, word.substr(0,i));
        while ( i < word.size() && currentNode ){
            i++;
            currentNode = findNode(currentNode, word.substr(0,i));
        }
        if ( currentNode ){
            return currentNode->wordExists;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i = 0;
        Node* currentNode = root;
        while ( i < prefix.size() && currentNode ){
            i++;
            if ( findNode(currentNode, prefix.substr(0,i)) ){
                currentNode = findNode(currentNode, prefix.substr(0,i));
            } else {
                i--;
                break;
            }
        }
        if ( i == prefix.size() ){
            return true;
        }
        return false;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */