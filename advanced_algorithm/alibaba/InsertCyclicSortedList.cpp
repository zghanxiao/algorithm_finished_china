/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param node: a list node in the list
     * @param x: An integer
     * @return: the inserted new list node
     */
    ListNode * insert(ListNode * node, int x) {
      // write your code here
      ListNode * iter = node;
      int cnt = 0;
      bool ini_flag = true;
      for (;iter != nullptr && !(iter == node && !ini_flag); iter = iter->next) {
        cnt ++;
        ini_flag = false;
      }
      
      if (cnt == 0) {
        ListNode * new_node = new ListNode(x); 
        new_node -> next = new_node;
        return new_node;
      }
      if (cnt == 1) {
        ListNode * new_node = new ListNode(x); 
        node->next = new_node;
        new_node->next = node;
        return new_node;
      } 
      
      ListNode * cur_node = node, * next_node = cur_node->next;
      ini_flag = true;
      while(!(cur_node == node && !ini_flag)) {
        ini_flag = false;
        next_node = cur_node->next;
        
        int cur_val = cur_node->val;
        int next_val = next_node->val;
       
        if (cur_val <= next_val) {
          if (x >= cur_val && x <= next_val) {
            ListNode * new_node = new ListNode(x);
            cur_node->next = new_node;  
            new_node->next = next_node;
            return new_node;
          } 
        } else {
          if (x >= cur_val || x <= next_val) {
            ListNode * new_node = new ListNode(x);  
            cur_node->next = new_node;
            new_node->next = next_node;
            return new_node;
          }  
        } 
        cur_node = next_node;
        next_node = next_node->next;
      }
      
      ListNode * new_node = new ListNode(x);
      cur_node->next = new_node;  
      new_node->next = next_node;
      return new_node;
    }
};
