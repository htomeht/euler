#include <vector>
#include <map>
#include <cmath>

using namespace std;

namespace utl {
  class Factorization {
  public: 
    Factorization(long number) 
    : _number(number) {
      factorize();
      _root = sqrt(_number);
    }
    
    vector<long> get_factors() { return _factors; }
    map<long, int> get_map() { return _factor_map; }
    long get_size() { return _factors.size(); } 
  
    
  
  private:
    long _number;
    long _root;
    map<long, int> _factor_map;
    vector<long> _factors;
  
    void factorize() {
        //_factor_map[_number]++;
        for (long i = 2; i <= _number ; ) {
          if (_number % i == 0) { // Factor in number
            _factors.push_back(i);
            _factor_map[i]++;
            _number = _number/i;
          }
          else ++i;
        }
      _factors.push_back(_number);
    }
  };
}

