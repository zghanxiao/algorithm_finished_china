/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    int get_res(string& array_item, string & another_item, 
        bool bolt_array_flag, Comparator & cmp) {
      if (!bolt_array_flag) {
        return cmp.cmp(array_item, another_item);
      } else {
        return cmp.cmp(another_item, array_item);
      }
    }
    
    bool equal(int res) {
      return res == 0;
    }
    
    bool less(bool bolt_array_flag, int cmp_res) {
      return !bolt_array_flag && cmp_res == -1 || bolt_array_flag && cmp_res == 1;
    }
    
    bool bigger(bool bolt_array_flag, int cmp_res) {
      return !bolt_array_flag && cmp_res == 1 || bolt_array_flag && cmp_res == -1;
    }
    
    int partition(vector<string> &things, int left, int right, 
      string & another_thing,  Comparator & cmp) {
      if (left > right) {
        return -1;
      } else if (left == right) {
        return left;
      }
      
      bool bolt_array_flag = cmp.cmp(things[left], another_thing) == 2;
      int left_iter = left;
      int right_iter = right;
      int pivot_index = -1;
      
      for (;left_iter <= right_iter && left_iter <= right 
        && right_iter >= left;) {
        
        while (left_iter <= right_iter) {
          int cmp_res = get_res(things[left_iter], another_thing, bolt_array_flag,
              cmp);
          
          if (equal(cmp_res)) { 
            pivot_index = left_iter;
            left_iter ++;
          } else if(less(bolt_array_flag, cmp_res)) {
            left_iter ++;
          } else {
            break;
          }
        }

        while(left_iter <= right_iter) {
          int cmp_res = get_res(things[right_iter], another_thing, bolt_array_flag,
              cmp) ;

          if (equal(cmp_res)) { 
            pivot_index = right_iter; 
            right_iter --;
          } else if(bigger(bolt_array_flag, cmp_res)) {
            right_iter --;
          } else {
            break;
          }
        }
        
        int left_cmp_res = -1, right_cmp_res = -1;
        if (left_iter <= right_iter) {
          left_cmp_res = get_res(things[left_iter], another_thing, 
              bolt_array_flag, cmp);
          right_cmp_res = get_res(things[right_iter], another_thing, 
              bolt_array_flag, cmp);
       
          if (bigger(bolt_array_flag, left_cmp_res) && less(bolt_array_flag, 
              right_cmp_res)) {
            swap(things[left_iter], things[right_iter]);
          }
        }
      }
      
      if (left_iter -1 >= pivot_index) {
        swap(things[pivot_index], things[left_iter - 1]);
        return left_iter - 1;
      } else {
        swap(things[pivot_index], things[right_iter + 1]);
        return right_iter + 1;
      }
    }
    
    int sortHelper(vector<string> & nuts, vector<string> & bolts, int left, 
        int right, Comparator cmp) {
      if (left >= right) {
        return 0;
      }
      
      int bolt_index = partition(bolts, left, right, nuts[left], cmp);
      int nuts_index = partition(nuts, left, right, bolts[bolt_index], cmp);

      if (bolt_index != nuts_index || bolt_index == -1) {
         return -1;
      }
      
      int res1 = sortHelper(nuts, bolts, left, bolt_index - 1, cmp);
      int res2 = sortHelper(nuts, bolts, bolt_index + 1, right, cmp);

      if (res1 == - 1 || res2 == -1) {
        return -1;
      } else {
        return 0; 
      }
    }
    
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, 
        Comparator compare) {
      if (nuts.size() != bolts.size()) {
        return;
      }
      int size = nuts.size();
      sortHelper(nuts, bolts, 0, size - 1, compare);
    }
};
