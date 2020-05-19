class Solution {
public:
    /**
     * @param elements: A list of recommended elements.
     * @param n: [picture P] can appear at most 1 in every n
     * @return: Return the scattered result.
     */
    vector<string> scatter(vector<string> &elements, int n) {
      // write your code here
      vector<string> Pvec;
      vector<string> Vvec;
      
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
      
      int s_i = iter;
      for (; s_i < size; ++ s_i) {
        string element = elements[s_i];
        if (element[0] == 'P') {
          Pvec.push_back(element);
        } else {
          Vvec.push_back(element);
        }
      }
      
      int new_size = iter;
      elements.resize(new_size);
      
      int p_i = 0;
      int v_i = 0;
      bool p_completed_flag = true;
      bool v_completed_flag = true;
      
      bool p_stop_flag = false;
      bool v_stop_flag = false;
      while (true) {
        
        if (!v_completed_flag || p_i >= Pvec.size()) {
          break;
        }
        
        p_completed_flag = false;
        elements.push_back(Pvec[p_i]);
        p_i ++;
        p_completed_flag = true;
        
        if (!p_completed_flag || v_i >= Vvec.size()) {
          break;
        }
        
        v_completed_flag = false;
        int cnt = 0;
        for (;v_i < Vvec.size(); ) {
          elements.push_back(Vvec[v_i]);
          cnt ++;
          v_i ++;
          if (cnt == n - 1) {
            v_completed_flag = true;
          }
          
          if (v_completed_flag) {
            break;
          }
        }
      }
      return elements;
    }
};
