#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int main(){
    vector<int>nums={1,-1,1,-1,1,-1}; int k=2;
    double ans=INT_MIN; int track=0; double sum=0.0; int left=0;
     for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        track++;
        if(track==k){
            double temp=sum/k;
            ans=max(ans,temp);
            sum-=nums[left];
            track--;
            left++;
        }
     }
     cout<<ans<<" ";
     return 0;
}