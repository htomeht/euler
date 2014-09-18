/* 
 * Calculate the difference between the sum of squares and the square of sums
 * of a number. 
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) 
    return 1;

  int numbers = atoi(argv[1]);

  vector<int> squares;

  int sumofsquares = 0;
  int squareofsums = pow((1+numbers)*numbers/2, 2);

  for (int i = 1; i <= numbers; i++) {
    sumofsquares += pow(i, 2);   
  }


  cout << "Square     : " << squareofsums << endl;
  cout << "Sums       : " << sumofsquares << endl;
  cout << "Difference : " << squareofsums-sumofsquares << endl;

}
