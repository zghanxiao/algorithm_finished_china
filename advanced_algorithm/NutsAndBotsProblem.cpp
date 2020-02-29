class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    int partition(vector<string> &things, int left, int right, 
      string & another_thing,  Comparator cmp) {
      //cout << "partition0" << endl;
      if (left > right) {
        return -1;
      } else if (left == right) {
        return left;
      }
      
      int left_iter = left;
      int right_iter = right;
      int pivot_index = -1;
      //int pre_left_iter = left;
      //int pre_right_iter = right;
      
      //cout << "partition0" << endl;

      for (;left_iter <= right_iter && left_iter <= right 
        && right_iter >= left;) {
        
        //cout << "left_iter right_iter" << left_iter <<" " << right_iter << endl;
        //cout << "partition1" << endl;

        if (cmp.cmp(things[left_iter], another_thing) == 0 || cmp.cmp(another_thing, things[left_iter]) == 0) { 
          pivot_index = left_iter;
          left_iter ++;
        }
        
        //cout << "partition2" << endl;

        if (cmp.cmp(things[right_iter], another_thing) == 0 || cmp.cmp(another_thing, things[right_iter]) == 0) {
          pivot_index = right_iter; 
          right_iter --;
        }
        
        
        //cout << "partition3" << endl;

        while(left_iter <= right && (cmp.cmp(things[left_iter], 
            another_thing) == -1 || cmp.cmp(another_thing, things[left_iter]) 
            == 1)) {
          //pre_left_iter = left_iter;
          left_iter ++;
        }
        
        //cout << "partition4" << endl;

        while(right_iter >= left && (cmp.cmp(things[right_iter],  
            another_thing)  == 1 || cmp.cmp(another_thing, things[right_iter]) 
            == -1)) {
          //pre_right_iter = right_iter;
          right_iter --;
        }
        
        //cout << "partition5" << endl;

        swap(things[left_iter], things[right_iter]);
      }
      //cout << "partition6" << endl;
      cout << "pivot_index pre_left_iter" << pivot_index << " " << pre_left_iter << endl;
      swap(things[pivot_index], things[left_iter - 1]);
      return pre_left_iter;
    }
    
    int sortHelper(vector<string> & nuts, vector<string> & bolts, int left, 
        int right, Comparator cmp) {
      if (left >= right) {
        return 0;
      }
      
      //cout << "left: right:" << left << " " << right << endl;
      //cout << "sortHelper0" << endl;
      int bolt_index = partition(bolts, left, right, nuts[left], cmp);
      //cout << "sortHelper05" << endl;
      
      for (int iter = 0; iter < bolts.size(); ++ iter) {
        cout << bolts[iter] << " ";
      }
      
      cout << endl;

      int nuts_index = partition(nuts, left, right, bolts[bolt_index], cmp);
      
      //cout << "sortHelper1" << endl;
      //cout << "bolt_index, nuts_index " << bolt_index << " " << nuts_index << endl;
      
      for (int iter = 0; iter < nuts.size(); ++ iter) {
        cout << nuts[iter] << " ";
      }

      /*
      if (bolt_index != nuts_index || bolt_index == -1) {
         return -1;
      }
      */
      
      //cout << "sortHelper2" << endl;

      int res1 = sortHelper(nuts, bolts, left, bolt_index - 1, cmp);
      int res2 = sortHelper(nuts, bolts, bolt_index + 1, right, cmp);
      //cout << "sortHelper3" << endl;

      if (res1 == - 1 || res2 == -1) {
        return -1;
      } else {
        return 0; 
      }
    }
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, 
        Comparator compare) {
      // write your code here
      if (nuts.size() != bolts.size()) {
        return;
      }
      int size = nuts.size();
      sortHelper(nuts, bolts, 0, size - 1, compare);
    }
};

int main() {
  Solution s;
  vector<string> nuts(4);
  nuts[0] = "ab";
  nuts[1] = "bc";
  nuts[2] = "dd";
  nuts[3] = "gg";
  vector<string> bolts(4);
  bolts[0] = "AB";
  bolts[1] = "GG";
  bolts[2] = "DD";
  bolts[3] = "BC";
  Comparator compare;
  s.sortNutsAndBolts(nuts, bolts, compare);
}
