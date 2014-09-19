#include<algorithm>
#include<fstream>
#include<iostream>
#include<iterator>
#include<numeric>
#include<vector>

using namespace std;

int main(int argc, char* argv[]) {

  if (argc != 2) {
    cerr << "USAGE" << endl;
    return 1;
  }

  ifstream file_stream("numbers");

  if (!file_stream) {
    cerr << "Could not open file " << argv[1] << endl;
    return 1;
  }

  string s;
  vector<int> numbers;

  file_stream >> s;
  
  for (int n = 0; n < s.size(); ++n) {
    numbers.push_back(s[n]-48);
  }

  int max = 0;

  for (int i = 0; i < numbers.size(); ++i) {
    int product = 1;
    for (int j = i; j < i+5; ++j) {
      product *= numbers[j];
    }


    if (product > max)
      max = product;
  }
  cout << max << endl;
}
