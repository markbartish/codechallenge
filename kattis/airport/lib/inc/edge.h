#ifndef __EDGE_H__
#define __EDGE_H__

#include "consts.h"
#include "point.h"

enum EdgeType{
  LINE = 0,
  RAY,
  SEGMENT
};

template<typename T>
class Edge{
  Point<T> p1;
  Point<T> p2;
  EdgeType type;
  
public:
  Edge();
  Edge(T x1, T y1, T x2, T y2, EdgeType type = EdgeType::LINE);
  Edge(const Point<T>& p1, const Point<T>& p2, EdgeType type = EdgeType::LINE);

  Edge<T>& operator=(const Edge<T>& rhs);
  
  inline double dist() const;

  double dist(const Edge<T>& other) const;
};

#endif //__EDGE_H__
