/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* m(Node* node,unordered_map<Node*,Node*> &map){

        if(map.find(node) != map.end()) return map[node];

        Node* clone = new Node(node->val);
        map[node] = clone;

        vector<Node*> nb;

        for(auto n: node->neighbors){
            nb.push_back(m(n,map));
        }

        clone->neighbors = nb;

        return clone;


    }

    Node* cloneGraph(Node* node) {

       if(node == NULL) return node;

       unordered_map<Node*,Node*> map;

       if(node->neighbors.size() == 0){
            Node* n = new Node(node->val);
            return n;
       }

       return m(node,map);
        
        
    }
};
