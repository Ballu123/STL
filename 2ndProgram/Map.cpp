/*
 * Name:Balram Panwar
 * Email id: balram.panwar@gmail.com
 * Name of the file: Map.cpp
 * Win10
 * Microsoft Visual Studio
 *
 * class MostPopular : Add the trade with key:value pair in map
 * function main() : Create the instance of class
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

class MostPopular {
    std::unordered_map<std::string, int> stockData;

public:
    void addTrade(const std::string& stock, int shares) {
        stockData[stock] += shares;
    }

    void printTop(int nbrOfStocks) const {
        if (nbrOfStocks <= 0) return;

        // Use a pair for the heap: {shares, stock_name}
        typedef std::pair<int, std::string> StockPair;

        // We use a custom comparator to create a Min-Heap.
        // The smallest value will always be at the top.
        auto cmp = [](const StockPair& a, const StockPair& b) {
            if (a.first != b.first) return a.first > b.first; // Min-heap on shares
            return a.second < b.second; // Tie-breaker for heap stability
        };

        std::priority_queue<StockPair, std::vector<StockPair>, decltype(cmp)> pq(cmp);

        for (auto const& [name, shares] : stockData) {
            pq.push({shares, name});
            
            // Keep the heap size restricted to nbrOfStocks
            if (pq.size() > (size_t)nbrOfStocks) {
                pq.pop();
            }
        }

        // The heap now contains the top N, but in reverse order (smallest of top N first).
        // Transfer to a vector and reverse for final output.
        std::vector<StockPair> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        std::reverse(result.begin(), result.end());

        for (const auto& p : result) {
            std::cout << p.second << " " << p.first << std::endl;
        }
    }
};

int main(int argc, char** argv) 
{
    MostPopular mostPopular;

    mostPopular.addTrade("GLAXO"     , 100);
    mostPopular.addTrade("BP"        , 100);
    mostPopular.addTrade("GLAXO"     , 300);
    mostPopular.addTrade("SKY"       , 100);
    mostPopular.addTrade("BP"        , 100);
    mostPopular.addTrade("TESCO"     , 100);
    mostPopular.addTrade("VODAFONE"  , 400);
    mostPopular.addTrade("SKY"       , 100);
    mostPopular.addTrade("GLAXO"     , 100);
    mostPopular.addTrade("BP"        , 200);
    mostPopular.printTop(3);

  /*  std::cout << "Expected:\n"
              << "GLAXO 500\n"
              << "BP 400\n"
              << "VODAFONE 400" << std::endl;*/
    return 0;

}
