#include <iostream>
#include <vector>

using namespace std;

class Point{
  int x;
  int y;

public:
  Point() : x(0), y(0){};
  Point(int x, int y) : x(x), y(y){}
};

double solve(const vector<Point>& points){
  int n = points.size();
  
  return 0;
}

int main(int argc, char **argv){
  int n = 0;
  cin >> n;
  vector<Point> points;
  for (int i = 0; i < n; i++){
    int x = 0, y = 0;
    cin >> x >> y;
    Point p(x, y);
    points.push_back(p);
  }
  cout << solve(points) << endl;
  
  return 0;
}
