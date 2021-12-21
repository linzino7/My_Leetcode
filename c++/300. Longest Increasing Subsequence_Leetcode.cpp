class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int tmp[nums.size()];
        int c;
        int m = 1;
        
        // init
        for(int i = 0; i<nums.size();i++){
            tmp[i]=1;
        }
        
        for(int i = 1; i<nums.size();i++){ // upbound
            for(int j =0; j<=i; j++){ //scan
                if(nums[i] >  nums[j] and i!=j  and tmp[i]<(tmp[j]+1)){ 
                    // if order bigger and the point longest length is bigger than now
                    tmp[i] = tmp[j]+1;
                    if(tmp[i]>m){
                        m = tmp[i];
                    }
                }
            }
            // for(int j = 0; j<nums.size();j++){
            //     cout << tmp[j] << " ";
            // }
            // cout <<  "\n";
        }

        return m;
    }
};
