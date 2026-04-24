#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
int main(){
   string s1 = "abbaac"; int ans=0; unordered_set<char>st;
    int right=0; int left=0;
    while(right<s1.size()){
        if(!st.empty() && st.find(s1[right])!=st.end()){
            while(left<right){
                if(s1[left]==s1[right]){
                    st.erase(s1[left]);
                    left++;
                    break;
                }
                st.erase(s1[left]);
                left++;
            }
        }
        st.insert(s1[right]);
        ans=max(ans,(right-left)+1);
        right++;
    }
    cout<<ans<<" ";
    return 0;
}