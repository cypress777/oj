#include <iostream>

using namespace std;
int main() {
  int height;
  int lader;
  int num;
  cin >> height;
  cin >> lader;
  cin >> num;
  height += lader;

  int pickable = 0;
  int appHeight;

  while (num) { 
    cin >> appHeight;
    if (appHeight <= height) pickable++;
    num--;
  }
  
  cout << pickable;
  return 0;
}
