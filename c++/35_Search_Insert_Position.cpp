// Leg: C++
// author: Zino 
#include<iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Insertion Sort
        // nums contains distinct values sorted in ascending order.
        
        int start = 0;
        int end = nums.size()-1;
        int point = start + (end - start)/2;

        printf("* p=%d s=%d e=%d \n", start, end);
    
        while (start<end && point<nums.size()){
                      
            printf(" p=%d s=%d e=%d val=%d \n", point, start, end, nums[point]);
            
            if (target > nums[point]){  //normal status
                start = point;
                
            }else if (target < nums[point]){
                end = point;
                
            }else if (target == nums[point]){
                return point;
            }    

            // no ans in nums and positation  in the 
            if (start == (end -1) && target > nums[start] && target < nums[end]){
                return start + 1;
            }
            
            // because of while condition, we need to process  when ans in nums[0]
            if (start == (end -1) && start ==0 && target == nums[0] ){
                return start;
            }
            // smaller than all when ans in nums[0]
            if (start == (end -1) && start ==0 && target < nums[0] ){
                return 0;
            }
            
            // bigger than all number
            if (start == (end -1) && end ==nums.size()-1 && target > nums[nums.size()-1] ){
                return nums.size();
            }
            
            // count point
            if ((end - start)/2 <1){
                point = start + 1;  
            }else{
                point = start + (end - start)/2;    
            }

            
        }
        
        printf("*** p=%d s=%d e=%d  \n", point, start, end);
        // only one element in the nums.
        if (start == end &&  target > nums[start]){
            return nums.size();
        }else if(start == end &&  target <= nums[start]){
            return 0;
        }
        
         return 0;
    }
};