/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* merge(ListNode* l, ListNode* r){

        if(l == NULL) return r;

        if(r == NULL) return l;

        ListNode* res = NULL;
        if(l->val > r->val){

            res = r;
            res->next = merge(l,r->next);

        }else{

            res = l;
            res->next = merge(l->next,r);

        }

        return res;

    }


    ListNode* mergeSort(vector<ListNode*>& lists, int s, int e){

        if(s>e) return NULL;

        if(s == e) return lists[s];

        int mid = (s+e)/2;

        ListNode* l = mergeSort(lists,s,mid);
        ListNode* r = mergeSort(lists,mid+1,e);

        ListNode* res = merge(l,r);

        return res;
    
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        return mergeSort(lists,0,n-1);
        
    }
};
