/*
 * Name:Balram Panwar
 * Email id: balram.panwar@gmail.com
 * Name of the file: AvgtriptimeperVec.cpp
 * Win10
 * Microsoft Visual Studio
 *
 * Function split() : spliting the Cin with delimiter (;)
 * Function main() : compute the average trip time per vehicle and 
 *                   prints the average trip time in second (sorted by the
 *                   VIN ascending) to STDOUT.
 */
#include <algorithm>
#include <cstring> 
#include <istream>
#include <iostream>
#include <iterator> // for iterators
#include <map>
#include <memory>
#include <sstream> // std::istringstream
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//spliting the Cin with delimiter (;) 
std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
//main function
int main() {
  std::map<std::string, unsigned long>mmap;
  std::string vin;
  unsigned long	timep;
  std::string state;
  int diff = 0;
  int count =0;
  std::unordered_map<std::string, pair< int, int >> result;
  std::string str;
  std:: string on = "ON";
  std:: string off = "OFF";
  // To store the user input line by line in the vector
  std::vector<std::string> table;
  
  while (std::getline(std::cin, str)) {
        table.push_back(str);
  }
  std::vector<std::string>::iterator itr;
  for(itr = table.begin(); itr != table.end(); itr++) {
    vector<string> vec = split(*itr, ';');
    vin = vec[0];
    timep = std::atoi (vec[1].c_str());
    state = vec[2];

    if(state.substr(0,2).compare(on) == 0) {
      mmap[vin] = timep;
    }else {
      auto pos = result.find(vin);
      if (pos == result.end()) {
        diff = timep -mmap[vin];
        count = 1;
        result[vin] = make_pair( diff, count);
      }else {
        auto key_pair = pos->second;
        
        int lastdiff = key_pair.first;
        diff = timep -mmap[vin];
        diff = diff + lastdiff;

        int lastcount = key_pair.second;
        count  = 1 + lastcount;
        result[vin] = make_pair( diff, count);
      }
    }
   }
   for (const auto &entry: result) {
	auto key_pair = entry.second;
	std::cout <<entry.first << ":" <<key_pair.first/key_pair.second << '\n';
  }
}