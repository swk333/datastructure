#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map> 
#include <queue> 

using namespace std;

queue<int> stackCards(vector<int> cards){
    queue<int> s;
    for(int i = 0; i < cards.size()-1; i++){
        if(cards[i] <= cards[i + 1]){
            s.push(cards[i]);
        } else {
            while(!s.empty()){
                s.pop();
            }
        }
    }
    s.push(cards[cards.size()-1]);

    return s;
};

int pointCaluculate(queue<int> cards){
    int point = cards.size() * 4;
    return point;
}

string ansString(queue<int> cards){
    string ans = "[";
    while(!cards.empty()){
        ans+= to_string(cards.front()) + ",";
        cards.pop();
    }
    ans.erase(ans.size()-1, 1);
    ans += "]";
    return ans;
}

string diceStreakGamble(vector<int> player1,vector<int> player2,vector<int> player3,vector<int> player4){
    //ここから書きましょう
    queue<int> card1 = stackCards(player1);
    queue<int> card2 = stackCards(player2);
    queue<int> card3 = stackCards(player3);
    queue<int> card4 = stackCards(player4);
    map<string, int> score;
    score["1"] = pointCaluculate(card1); 
    score["2"] = pointCaluculate(card2); 
    score["3"] = pointCaluculate(card3); 
    score["4"] = pointCaluculate(card4); 
    
    int pointMax = 0;
    string winner = "";
    for(auto p : score){
        if(pointMax < p.second){
            pointMax = p.second;
            winner = p.first;
        };
    }

    string ans = to_string(pointMax);
    string ans2 = ""; 
    queue<int> winnerCards;
    
    if(winner == "1"){
        winnerCards = card1;
    } else if(winner == "2"){
        winnerCards = card2;
    } else if(winner == "3"){
        winnerCards = card3;
    } else {
        winnerCards = card4;
    }
    ans2 = ansString(winnerCards);
    return "Winner: Player " + winner + " won $" + ans + " by rolling " + ans2;
}
