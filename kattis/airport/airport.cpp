#include "lib/inc/point.h"

#include <iostream>
#include <vector>
#include <cmath>



using namespace std;

template<typename T>
double solve(const vector< Point<T> >& points){
  int n = points.size();

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i == j) continue;
      cout << points[i] << " -> " << points[j] << ": " << points[i].dist(points[j]) << endl;
    }
  }
  
  return 0;
}

int main(int argc, char **argv){
  int n = 0;
  cin >> n;
  vector< Point<int> > points;
  for (int i = 0; i < n; i++){
    int x = 0, y = 0;
    cin >> x >> y;
    Point<int> p(x, y);
    points.push_back(p);
  }
  cout << solve(points) << endl;
  
  return 0;
}
