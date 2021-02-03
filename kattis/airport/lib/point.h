#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include <cmath>

/*
   punktvis addition/subtraktion
   multiplikation/division med skalär
   skalärprodukt
   kryssprodukt
   avstånd
   vinklar 
 */

template<typename T>
class Point{
  T x;
  T y;

public:
  Point() : x(0), y(0){};
  Point(T x, T y) : x(x), y(y){}


  bool operator==(const Point<T>& other) const {
    return x == other.x && y == other.y;
  }
  
  Point operator+(const Point<T>& other) const {
    return Point(x + other.x, y + other.y);
  }

  Point& operator+=(const Point<T>& other) {
    x += other.x, y += other.y;
    return *this;
  }

  Point operator-(const Point<T>& other) const {
    return Point(x - other.x, y - other.y);
  }
  Point& operator-=(const Point<T>& other) {
    x -= other.x, y -= other.y;
    return *this;
  }  

  template<typename U>
  Point operator*(U scalar) const {
    return Point(x * scalar, y * scalar);
  }
  template<typename U>
  Point& operator*=(U scalar) {
    x *= scalar, y *= scalar;
    return *this;
  }
  template<typename U>
  friend Point<T> operator*(U lhs, Point<T> rhs) { rhs *= lhs; return rhs; }

  template<typename U>
  Point operator/(U scalar) const {
    return Point(x / scalar, y / scalar);
  }
  template<typename U>
  Point& operator/=(U scalar) {
    x /= scalar, y /= scalar;
    return *this;
  }

  double operator*(const Point<T>& other){
    return x * other.x + y * other.y;
  }

  // TODO: is it possible to templatize the return type:
  //template<typename Scalar>
  //Scalar operator^(const Point<T>& other){
  double operator^(const Point<T>& other){
    return x * other.y - other.x * y;
  }
  
  double dist(const Point<T>& other) const {
    return sqrt( (other.x - x) * (other.x - x) +
		 (other.y - y) * (other.y - y) );
  }

  double norm() const {
    return this->dist(Point<T>(0, 0));
  }
  
  double angle(const Point<T>& other) const {
    return atan2(other.y, other.x) - atan2(y, x);
  }
  
  template<typename U>
  friend std::ostream& operator<<(std::ostream& os, const Point<U>& p);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p){
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

#endif //__POINT_H__
