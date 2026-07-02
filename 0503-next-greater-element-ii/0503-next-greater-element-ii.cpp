class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int currEle = nums[i];
            for(int j=1;j<n;j++){
                int ind=(j+i)%n;
                if(nums[ind]>currEle){
                    ans[i]=nums[ind];
                    break;
                }
            }
        }
        return ans;
    }
};