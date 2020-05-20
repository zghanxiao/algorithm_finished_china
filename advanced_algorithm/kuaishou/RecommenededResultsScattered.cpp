class Solution {
public:
    /**
     * @param elements: A list of recommended elements.
     * @param n: [picture P] can appear at most 1 in every n
     * @return: Return the scattered result.
     */
    vector<string> scatter(vector<string> &elements, int n) {
      // write your code here
      
      int size = elements.size();
      int iter;
      for (iter = 0; iter < size; ++ iter) {
        string element = elements[iter];  
        if (element[0] == 'P') {
          break;     
        }
      }
      
      if (iter == size) {
        return elements;
      }
      
      queue<string> Pq;
      queue<string> Vq;
      
      int s_i = iter;
      for (; s_i < size; ++ s_i) {
        string element = elements[s_i];
        if (element[0] == 'P') {
          Pq.push(element);
        } else {
          Vq.push(element);
        }
      }
      
      int new_size = iter;
      elements.resize(new_size);
      
      while (!Pq.empty()) {
        
        elements.push_back(Pq.front());
        Pq.pop();
        
        int cnt = 0;
        for (; cnt < n - 1 && !Vq.empty(); cnt ++) {
          elements.push_back(Vq.front());
          Vq.pop();
        }
        
        if (cnt != n - 1) {
          break;
        }
      }
      return elements;
    }
};
