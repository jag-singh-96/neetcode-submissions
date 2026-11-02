class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set;

        for(auto w: wordList){
            set.insert(w);
        }

        if (set.find(endWord) == set.end()) {

            return 0;

        }


        queue<pair<string, int>> q;

        q.push({beginWord,1});

        while(!q.empty()){

            string node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(node == endWord) return level;

            for(int i = 0; i < node.length(); i++){
                char temp = node[i];

                for(auto c = 'a'; c <= 'z'; c++){
                    node[i] = c;

                    if(set.find(node) != set.end()){
                        q.push({node,level+1});
                        set.erase(node);
                    }
                }
                node[i] = temp;
            }

        }

        return 0;
        
    }
};
