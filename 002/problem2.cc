#include<vector>
#include<iostream>
#include<iterator>
#include<numeric>
#include<algorithm>

using namespace std;

class Fibonacci {

public:
  Fibonacci() {_numbers.push_back(0); _numbers.push_back(1);}
  
  vector<int> operator()(const int n) {
    _max = n;
    
    int next_number = _numbers.back() + *(_numbers.rbegin()+1);
    while(next_number < _max) {
      //int next_val = _numbers.back() + *(_numbers.rbegin() +1);
      _numbers.push_back(next_number);
      next_number = _numbers.back() + *(_numbers.rbegin()+1);
    }
      //cout << next_number << endl;
    return _numbers;
  }

private: 
  vector<int> _numbers;
  int _max;
};

bool mod2(const int n) { return n%2==0; }

int main() {
 
  Fibonacci fib = Fibonacci();
  vector<int> v = fib(4000000);
  v.erase(remove_if(v.begin(), v.end(), mod2), v.end());
  //copy(v.begin(), v.end(), ostream_iterator<int, char>(cout, " "));
  int sum = accumulate(v.begin(), v.end(), 0);
  cout << sum << endl;
  
}
