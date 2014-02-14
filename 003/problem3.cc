#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iterator>
#include "factorize"

using namespace std;

ostream& operator<< (ostream& out, const vector<long> v) {
  copy(v.begin(), v.end(), ostream_iterator<int> (out, " "));
  return out;
  }

int main(int argc, char* argv[]) {
/* 
 * A program which taken an input nr 
 * 
 */

  long input_nr;
  vector<long> factors;

  if (argc != 2) {
    //usage();
    return 1;
  }

  try {
    max = atol(argv[1]); 
  catch (Exception e) {
    cout << "Argument must be a composite number or prime" << endl;
    return 1;
  }

  utl::Factorization factorization = utl::Factorization(max);
  factors = factorization.get_factors();

  cout << "Max = " << max << endl;
  cout << "Biggest factor = " << factors.back() << endl;
  cout << "Vector = [ " << factors << "]a" << endl;

  return 0;

}
