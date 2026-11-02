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

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        int counter = 1;

        ListNode* ptr = head;

        ListNode* dummy = new ListNode(-1);

        dummy->next = head;

        ListNode* prev = dummy;

        ListNode* lprev = dummy;

        while(ptr){
            //  cout<<counter<<endl;
            if(counter == left){

                lprev = prev;
                ListNode* subPrev = NULL;   
                ListNode* n = NULL;
                while(counter < right+1 && ptr != NULL){
                    n = ptr->next;
                    ptr->next = subPrev;
                    subPrev = ptr;
                    ptr = n;
                    counter++;
                }
                ListNode* last = lprev->next;
                lprev->next = subPrev;
                last->next = ptr;
                break;

            }
            counter++;
            prev = ptr;
            ptr=ptr->next;
        }

        return dummy->next;

        
    }
};