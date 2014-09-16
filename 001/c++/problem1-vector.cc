#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;

class Counter {
public: 
  Counter() 
  : _count(0) {}

  int operator()() {
    return ++_count;
  }

private:
  int _count; 
};

bool mymod(const int n) {
  bool mod3 = n % 3 == 0;
  bool mod5 = n % 5 == 0;

  //return !((mod3 || mod5) && !mod15);
  return (!mod3 && !mod5);// || mod15;
}

int main () {

  Counter counter = Counter();
  vector<int> numbers(999);
  generate_n(numbers.begin(), 999, counter); 

  //copy(numbers.begin(), numbers.end(), ostream_iterator<int, char>(cout, " "));

  numbers.erase(remove_if(numbers.begin(), numbers.end(), mymod), numbers.end()); 

  copy(numbers.begin(), numbers.end(), ostream_iterator<int, char>(cout, " "));

  int sum = accumulate(numbers.begin(), numbers.end(), 0);
  
  cout << "Sum is : " << sum << endl;
  
}
