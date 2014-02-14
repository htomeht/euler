#ifndef SPLIT_H_
#define SPLIT_H_

#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>

namespace utl {

  template<typename T>
  std::vector<T> &split(const std::string &s, char delim, std::vector<T> &elems) {
      std::stringstream ss(s);
      std::string token;
      T conversion;
      while(std::getline(ss, token, delim)) {
          std::istringstream tokenizer(token);
          tokenizer >> conversion;
          elems.push_back(conversion);
      }
      return elems;
  }
  
  
  template<typename T>
  std::vector<T> split(const std::string &s, char delim) {
      std::vector<T> elems;
      return split(s, delim, elems);
  }

}
#endif /* GRID_H_ */

