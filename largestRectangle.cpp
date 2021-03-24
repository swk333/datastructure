#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <stack>

using namespace std;

int largestRectangle(vector<int> h){
    //ここから書きましょう
    stack<int> s;
    int n = h.size();
    vector<int> left(n), right(n);
    int maxArea = 0;

    for(int i = 0; i < n; i++){
      if(s.empty()){
        left[i] = 0;
        s.push(i);
      } else {
          while(!s.empty() && h[s.top()] >= h[i]){
            s.pop();
          }
          left[i] = s.empty() ? 0 : s.top()+1;
          s.push(i);
        }
    }

    while(!s.empty()){
      s.pop();
    }

    for(int i = n-1; i >= 0; i--){
      if(s.empty()){
        s.push(i);
        right[i] = n-1;
      } else {
        while(!s.empty() && h[s.top()] >= h[i]){
          s.pop();
        }
        right[i] = s.empty() ? n-1: s.top()-1;
        s.push(i);
      }
    }


  for(int i = 0; i < n; i++){
    maxArea = max(maxArea, h[i] * (right[i] - left[i] + 1));
  }

  return maxArea;


};
