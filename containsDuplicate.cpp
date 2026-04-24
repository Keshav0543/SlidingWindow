#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
int main(){
vector<int> nums(100000, 1);
int k = 1;
    unordered_map<int,int>mp; int flag=0;
    for(int i=0;i<nums.size();i++){
        if(!mp.empty() && mp.find(nums[i])!=mp.end()){
            if(abs(mp[nums[i]]-i)<=k){
                flag=1;
                break;
            }
        }
        mp[nums[i]]=i;
    }

    if(flag==0)cout<<"False"<<" ";
    else cout<<"True"<<" ";
    return 0;
}