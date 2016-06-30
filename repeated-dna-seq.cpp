#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
   std::map<std::string, int> strMap;
   std::vector<std::string> res;

   for (int i = 0; i < s.size(); i++) {
      auto substr = s.substr(i, 10);
      if (substr.size() < 10)
         break;
      strMap[substr]++;
   }
   for (auto s : strMap) {
      if (s.second > 1) {
           res.push_back(s.first);
      }
   }
   return res;
}

int main(int argc, char *argv[])
{
	auto seqs = findRepeatedDnaSequences(argv[1]);
	for (auto &seq : seqs) 
		std::cout << seq << std::endl;
	return 0;
}
