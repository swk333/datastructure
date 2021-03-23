#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <sstream>
#include <stack>

using namespace std;

vector<int> stockSpan(vector<int> stocks){
    vector<int> ans;
    stack<int> index;


    for(int i = 0; i < stocks.size(); i++){
        int count = 1;
        
        while(index.size() > 0 && stocks[index.top()] < stocks[i]){
            count += ans[index.top()];
            index.pop();
        }
        ans.push_back(count);
        index.push(i);
        cout << index.top() << " " << stocks[index.top()] << " " << ans[index.top()] << endl;
        cout << count << endl;

    }
    return ans;
}
