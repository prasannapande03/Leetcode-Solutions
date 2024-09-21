#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
        vector<vector<long long int>> dp(n1+1, vector<long long int> (n2+1, -1));

        for(int j = 0; j<= n2; j++){
          dp[0][j] = 0;
        }

        for(int i = 0; i<n1; i++){
          dp[i][0] = 0;
        }

        for(int i = 1; i<= n1; i++){
          for(int j = 1; j<= n2; j++){
            if(text1[i-1] == text2[j-1]) 
            dp[i][j] = 1 + dp[i-1][j-1];

            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }

        return dp[n1][n2];
    }
};

int main(){
  string text1, text2;

  cin>>text1>>text2;

  Solution sol;
  int ans = sol.longestCommonSubsequence(text1, text2);

  cout<<ans;

  return 0;
}