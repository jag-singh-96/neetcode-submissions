/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*,Node*> map;

        Node* ptr = head;


        while(ptr != NULL){
            Node* clone = new Node(ptr->val);
            map[ptr] = clone;
            ptr = ptr->next;
        }


        ptr = head;
        while(ptr != NULL){

            Node* clone = map[ptr];
            clone->next = map[ptr->next];
            clone->random = map[ptr->random];
            ptr = ptr->next;

        }


        return map[head];

        
    }
};
