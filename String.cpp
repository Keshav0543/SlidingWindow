#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    string s= "abcdef"; vector<string>words={"gh","ij"};
    vector<string>store; int len=words[0].size(); unordered_map<string,int>mp; vector<int>ans;
    //Run a loop to convert into an string
    int track=0; string temp="";
    for(int i=0;i<s.size();i++){
        temp+=s[i];
        track++;
        if(track==len){
            store.push_back(temp);
            temp="";
            track=0;
        }
    }

    //Store in a map
    for(int i=0;i<words.size();i++)mp[words[i]]++;

    int left=0; int right=0; track=0;
    while(right<store.size()){
        if(mp.find(store[right])!=mp.end()){
            if(mp[store[right]]>0){
                track++;
                mp[store[right]]--;
            }
            //Dublicate cses
            else{
                while(left<right){
                    if(store[left]==store[right]){
                        left++;
                        break;
                    }
                    else if(mp.find(store[right])!=mp.end()){
                        mp[store[left]]++;
                        track--;
                    }
                    left++;
                }
            }
        }
        else {
            while(left<=right){
                if(mp.find(store[left])!=mp.end()){
                    mp[store[left]]++;
                    track--;
                }
                left++;
            }
        }
        if(track==words.size()){
            ans.push_back(left * words[0].size());
            mp[store[left]]++;
            track--;
            left++;
        }
        right++;
    }

    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}