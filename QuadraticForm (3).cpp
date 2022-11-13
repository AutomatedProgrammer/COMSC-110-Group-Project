#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  int a, b, c;
  double total1, total2;
  cout << "Enter A: ";
  cin >> a;
  cout << "Enter B: ";
  cin >> b;
  cout << "Enter C: ";
  cin >> c;

  total1 = ((-b + (sqrt((pow(b,2)) - 4 * a * c))) / 2*a);
  total2 = ((-b - (sqrt((pow(b,2)) - 4 * a * c))) / 2*a);
  cout << "x = " << total1 << "  or  x = "<< total2 << endl;
}