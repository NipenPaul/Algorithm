class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
      vector<int> v, ans;
      for(int &x: obstacles){
          auto it = upper_bound(v.begin(), v.end(), x);
          if(v.end() == it){
              v.push_back(x);
              ans.push_back(v.size());
          }else{
              v[it-v.begin()] = x;
              int d = it-v.begin();
              ans.push_back(d+1);
          }
      }  
      return ans;
    }
};
/*
Input: obstacles = [1,2,3,2]
Output: [1,2,3,3]
*/
