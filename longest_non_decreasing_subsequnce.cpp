#include<bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> v;
    vector<int>::iterator it;
    for(int i = 0; i < nums.size(); i++){
        it = upper_bound(v.begin(), v.end(), nums[i]);
        if(v.end() == it) v.push_back(nums[i]);
        else v[it-v.begin()] = nums[i];
    }
    return v.size();
}

int main(){
    int n; cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << lengthOfLIS(v) << endl;
    return 0;
}

/*
9
1 2 2 3 3 5 5 1 1
ans = 7
*/