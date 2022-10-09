#include <iostream>
#include <vector>

using namespace std;

class Kadanes{
public:
    int maxSubArray(vector<int>& nums) {
        
        int currentSum =nums[0], totalSum = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
        
            currentSum = max(nums[i], currentSum+nums[i]); 
            
            totalSum = max(totalSum, currentSum);
    }
        return totalSum;
    }
};

int main(){
    Kadanes k1;
    vector<int> v = {5,-4,-2,6,-1}; //Type or take your inputs using a vector and pass it into the 'maxSubArray' method in Kadanes Class;
    cout<<k1.maxSubArray(v);
    return 0;
}