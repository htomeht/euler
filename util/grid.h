#ifndef GRID_H_
#define GRID_H_

#include <string>
#include <vector>

namespace utl {

template<typename T, int size>
class Grid {
  public:
    Grid() : _size(size) {}

    T get(int x, int y) const { return _grid[x][y]; }
    void set(int x, int y, T val) { _grid[x][y] = val; }

    void set_row(int &i, std::vector<T> & elems) {
      for (int j = 0; j < elems.size(); j++) {
        set(i, j, elems[j]);
      }
    }

    std::vector<T> get_row(int x, int y, int n) {
      std::vector<T> v;
      if(y+n < size) {
        for(int i = 0; i < n; ++i) {
          v.push_back(get(x, y+i));
        }
      }
      return v;
    }

    std::vector<T> get_col(int x, int y, int n) {
      std::vector<T> v;
      if(x+n < size) {
        for(int i = 0; i < n; ++i) {
          v.push_back(get(x+i, y));
        }
      }
      return v;
    }
    

    std::vector<T> get_slope(int x, int y, int n) {
      std::vector<T> v;
      if(x+n < size && y+n < size) {
        for (int i = 0; i < n; ++i) {
          v.push_back(get(x+i,y+i));
        }
      }
      return v;
    }
    std::vector<T> get_hill(int x, int y, int n) {
      std::vector<T> v;
      if(x+n < size && y-n > 0) {
        for (int i = 0; i < n; ++i) {
          v.push_back(get(x+i,y-i));
        }
      }
      return v;
    }
    

  private:
    
    const int _size;
    T _grid[size][size];
};

}
#endif /* GRID_H_ */
