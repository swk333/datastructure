#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <queue>

using namespace std;

int findMinimum(queue<int> q){
    int ans = 2147483647;

    while(!q.empty()){
        ans = min(ans, q.front());
        q.pop();
    }
    return ans;
};


vector<int> minWindowArrK(vector<int> intArr,int k){
    //ここから書きましょう
    vector<int> ans;
    queue<int> q;

   for(int i = 0; i < intArr.size()+1; i++){
       
        if(i < k){
            q.push(intArr[i]);
            cout << q.front() << " " << i << endl;

        } else {
            ans.push_back(findMinimum(q));
            cout << q.front() << endl;
            q.push(intArr[i]);
            q.pop();

            
        }

    }


    return ans;
}

//参考
//https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/