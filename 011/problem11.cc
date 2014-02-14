#include <fstream>
#include <iostream>
#include <vector>

#include "grid.h"
#include "split.h"

using namespace std;

int product(vector<int> v) {
  int p = 1; 
  for(int i = 0; i < v.size(); ++i) {
    p *= v[i]; 
  }
  return p;
}

int main(int argc, char* argv[]) {

  const int size = 20;
  if (argc != 2) { return -1; }

  ifstream file(argv[1]);
  string line;
  
  if(!file) { return -1; }
  
  utl::Grid<int, size> grid = utl::Grid<int, size>();
  
  // Populate grid
  int i = 0;
  while(getline(file, line)) {
    vector<int> tokens = utl::split<int>(line, ' ');
    grid.set_row(i, tokens);
    ++i;
  }
  
  int max = 0;
  vector<int> maxv;

  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      vector<int> row = grid.get_row(i, j, 4);
      int product_row = product(row);

      vector<int> col = grid.get_col(i, j, 4);
      int product_col = product(col);

      vector<int> slope = grid.get_slope(i, j, 4);
      int product_slope = product(slope);
      vector<int> hill = grid.get_hill(i, j, 4);
      int product_hill = product(hill);
      
      if (product_row > max) {
        cout << product_row << " from row ";
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        max = product_row;
      }
      if (product_col > max) {
        cout << product_col << " from column ";
        copy(col.begin(), col.end(), ostream_iterator<int>(cout, " "));
        cout << product_col << endl;
        max = product_col;
      }
      if (product_slope > max) {
        cout << product_slope << " from slope ";
        copy(slope.begin(), slope.end(), ostream_iterator<int>(cout, " "));
        cout << product_slope << endl;
        max = product_slope;
      }
      if (product_hill > max) {
        cout << product_hill << " from hill ";
        copy(hill.begin(), hill.end(), ostream_iterator<int>(cout, " "));
        cout << product_hill << endl;
        max = product_hill;
      }
    }
  }

  cout << grid.get(7,6) << endl;
  cout << max << endl;
}

