class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int sum1=0, sum2=0;
        vector<int> b=nums;
        for(int i=0; i < nums.size(); i++) {
            //cout<<i<<endl;
            if(i&1) {
                if(b[i] <= b[i-1]) sum1+=b[i-1]-(b[i]-1);
            }
            else {
                if(i&&b[i] >= b[i-1]) {
                    sum1+=b[i] - (b[i-1]-1);
                    b[i]=b[i-1]-1;
                }
            }
        }
        for(int i=0; i < nums.size(); i++) {
            if(i&1) {
                if(nums[i] >= nums[i-1]) {
                    sum2+=nums[i]-(nums[i-1]-1);
                    nums[i]=nums[i-1]-1;
                }
            }
            else {
                if(i&&nums[i] <= nums[i-1]) sum2+=nums[i-1] - (nums[i]-1);
            }
        }
        // cout<<sum1<<" "<<sum2<<endl;
        return min(sum1,sum2);
    }
};