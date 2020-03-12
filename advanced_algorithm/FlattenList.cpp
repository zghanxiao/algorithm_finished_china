class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    void flattenHelper(vector<NestedInteger> & nestedList, vector<int> & res) {
      int size = nestedList.size(); 
      for (int iter = 0; iter < size; ++ iter) {
        NestedInteger item= nestedList[iter];  
        if (item.isInteger()) {
          res.push_back(item.getInteger());
        } else {
          vector<NestedInteger> list = item.getList();
          flattenHelper(list, res);
        }
      }
    }
    
    vector<int> flatten(vector<NestedInteger> &nestedList) {
      // Write your code here
      vector<int> res;
      flattenHelper(nestedList, res);
      return res;
    }
};
