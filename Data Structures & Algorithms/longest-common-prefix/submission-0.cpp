class TrieNode {
            public:
                bool end;
                vector<TrieNode*> child;

                TrieNode() {
                    this->end = false;
                    child.resize(26, NULL);
                }
};
        
class Trie {
            private:
                TrieNode* root;

            public:
                Trie() {
                    root = new TrieNode();
                    
                }

                void insert(string word) {
                    TrieNode* temp = root;
                    for(auto &c : word) {
                        if(temp->child[c - 'a'] == NULL) { 
                            temp->child[c - 'a'] = new TrieNode(); 
                        }
                        temp = temp->child[c - 'a'];
                    }
                    temp->end = true; 
                }

                string searchPrefix() {
                    TrieNode* temp = root;
                    string prefix = "";
                    while (true) {
                        if (temp->end==true) {
                            break;
                        }

                        int childCount = 0;
                        int nextIndex = -1;

                        for (int i=0; i < 26; i++) {
                            if (temp->child[i]!=NULL) {
                                childCount++;
                                nextIndex=i;
                            }
                        }

                        if (childCount!=1) {
                            break;
                        }

                        char nextChar = 'a' + nextIndex;
                        prefix += nextChar;

                        temp = temp->child[nextIndex];
                    }

                    return prefix;
                }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         
         if (strs.empty()) return "";

         Trie myTree;
         for (string str : strs) {
            if (str.empty()) return "";
            myTree.insert(str);
         }
        
         return myTree.searchPrefix();
                  
    }
};
        