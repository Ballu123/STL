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
#include <istream>
#include <sstream>
#include <algorithm>
#include <iostream> 
#include <cstring> 
#include <iterator>
#include <unordered_map>
#include <map>
#include <memory>
#include <set>
using namespace std;

class MostPopular 
{
  public:
    std::unordered_map<std::string, int> mmap;

  public:
    void addTrade(const std::string& stock, int shares) { 
        
        // adding the key->value in the mmap
        if(mmap.find(stock) == mmap.end())
          mmap[stock] = shares;
        else {
          auto itr = mmap.find(stock);
          int newval = shares + itr->second;
          mmap[stock] = newval;
        }
    }

    void printTop(int k) const {
      // sort map by key
      cout << "======map sort by key=====" <<endl;
      std::map<std::string, int, std::less<string>> m = {};
      m.insert(mmap.begin(), mmap.end());
      for(auto itrp : m) {
          cout << itrp.first << " : " << itrp.second <<endl;
      }

      // sort map by value (convert map into vector and then sort the vector)
      cout << "\n=====map sort by value======" <<endl;
      std::vector<std::pair<string, int>> pairs;
      for (auto itr = m.begin(); itr != m.end(); ++itr)
          pairs.push_back(*itr);
      sort(pairs.begin(), pairs.end(), [=](std::pair<string, int>& a, std::pair<string, int>& b)
                                        {return a.second > b.second;} );
      
      //[printing the all values of the vector.
      for(auto pval : pairs) {
          cout << pval.first << " : " << pval.second << endl;
      }
      cout << "\n===Printing only top k values===" << endl;
      for(auto pval = pairs.begin(); pval != pairs.begin()+k ; ++pval) {
          cout << pval->first << " : " << pval->second << endl;
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