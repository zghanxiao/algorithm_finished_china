class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
      // write your code here
      ListNode * grandpa = nullptr, * father = head, * child; 
      
      while(father != nullptr) {
        child = father->next;
        father->next =  grandpa;
        grandpa = father;
        father = child;
      } 
      return grandpa;
    }
};
