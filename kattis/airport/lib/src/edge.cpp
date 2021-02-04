#include "../inc/edge.h"

template<typename T>
Edge<T>::Edge() : p1(), p2(), type(EdgeType::LINE){}

template<typename T>
Edge<T>::Edge(T x1, T y1, T x2, T y2, EdgeType type) : p1(Point<T>(x1, y1)), p2(Point<T>(x2, y2)), type(type){}

template<typename T>
Edge<T>::Edge(const Point<T>& p1, const Point<T>& p2, EdgeType type) : p1(p1), p2(p2), type(type){}


template<typename T>
Edge<T>& Edge<T>::operator=(const Edge<T>& rhs){
  p1 = rhs.p1;
  p2 = rhs.p2;
  return *this;
}

template<typename T>
inline double Edge<T>::dist() const{
  return p1.dist(p2);
}

template<typename T>
double Edge<T>::dist(const Edge<T>& other)const{
  /*
    Vector   u = S1.P1 - S1.P0;
    Vector   v = S2.P1 - S2.P0;
    Vector   w = S1.P0 - S2.P0;
    float    a = dot(u,u);         // always >= 0
    float    b = dot(u,v);
    float    c = dot(v,v);         // always >= 0
    float    d = dot(u,w);
    float    e = dot(v,w);
    float    D = a*c - b*b;        // always >= 0
    float    sc, sN, sD = D;       // sc = sN / sD, default sD = D >= 0
    float    tc, tN, tD = D;       // tc = tN / tD, default tD = D >= 0
  */
  
  
  Point<T> u = p2 - p1;
  Point<T> v = other.p2 - other.p1;
  Point<T> w = p1 - other.p1;
  
  double udotu = u * u;
  double udotv = u * v;
  double vdotv = v * v;
  double udotw = u * w;
  double vdotw = v * w;
  
  double den  = udotu * vdotv - udotv * udotv;
  
  std::cout << "u * u = " << udotu << std::endl;
  std::cout << "u * v = " << udotv << std::endl;
  std::cout << "v * v = " << vdotv << std::endl;
  std::cout << "u * w = " << udotw << std::endl;
  std::cout << "v * w = " << vdotw << std::endl;
  std::cout << "den = "   << den << std::endl;
  
  
  double sc = 0;
  double tc = 0;
  
  //return 0; //w.norm();
  
  if (den < EPSILON){
    std::cout << "den < EPSILON case" << std::endl;
  }
  else{
    sc = (udotv * vdotw - vdotv * udotw) / den;
    tc = (udotu * vdotw - udotv * udotw) / den;
    
    if (sc < 0)      sc = 0;
    else if (sc > 1) sc = 1;
    
    if (tc < 0)      tc = 0;
    else if (tc > 1) tc = 1;
    
    Point<T> pE1 = this->p1 + sc * u;
    Point<T> pE2 = other.p1 + tc * v;
    return pE1.dist(pE2);
  }
  
  return 0;
}
