class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map <int,int> m;
        
        for(int i = 0;i < n;i++) {
            int x = target - nums[i];
            
            if(m.find(x) != m.end()) {
                return {i,m[x]};
            } else {
                m[nums[i]] = i;
            }
            
        }
        return {-1,-1};
    }
};