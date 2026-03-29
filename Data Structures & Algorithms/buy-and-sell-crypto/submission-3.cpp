
//Como saber qual é o menor?
// Dentro de um Hash<pair<values, bestDif>> só percorro o array 1 vez
// preciso de uma função que crie a melhor diferença
// a resposta será dada ao retornar o maior segundo elemento

// bestTrade = current - min;

// 8 = 10 - 2
// x + min = 10


#include <unordered_map>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min = prices[0];
        int bestTrade = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                if ((prices[i] - min) > bestTrade) {
                    bestTrade = (prices[i] - min);
                }
            }
        }
        return bestTrade;
    }
};
