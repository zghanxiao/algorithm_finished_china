/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
      // write your code here
      if (headA == nullptr || headB == nullptr) {
        return nullptr;
      }
      ListNode *dummyA = new ListNode(0), *iter = dummyA;
      dummyA -> next = headA;
      int cnt = 0;
      for (; iter -> next != nullptr; iter = iter->next ) {
        ++ cnt;
      }
      
      iter->next = headA;
      
      ListNode * slow_iter = headB, * fast_iter = headB;
      bool ini_meet = true;
      for(;!(slow_iter == fast_iter && !ini_meet);) {
        ini_meet = false;
        fast_iter = fast_iter->next;
        fast_iter = fast_iter->next;
        slow_iter = slow_iter->next;
      }
      
      slow_iter = headB;
      
      for (;slow_iter != fast_iter;) {
        fast_iter = fast_iter->next;  
        slow_iter = slow_iter->next;
      }
      
      return slow_iter;
    }
};
