/**
 * Definition of singly-linked-list:
 *
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
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
      // write your code here
      ListNode * dummy = new ListNode(0);  
      dummy->next = head;
      
      if (dummy->next == nullptr || dummy->next->next == nullptr) {
        return dummy->next;
      }
      
      ListNode * grandpa = dummy->next;
      ListNode * father = grandpa->next;
      ListNode * child = father->next;
      grandpa->next = nullptr;
    
      while(true) {
        father->next = grandpa;
        if (child == nullptr) {
          break;
        }
        grandpa = father;
        father = child;
        child = child->next;
      } 
      return father;
      
    }
};
