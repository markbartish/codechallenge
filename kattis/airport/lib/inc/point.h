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
  Point();
  Point(T x, T y);


  bool operator==(const Point<T>& other) const;
  
  Point operator+(const Point<T>& other) const;

  Point& operator+=(const Point<T>& other);

  Point operator-(const Point<T>& other) const;
  
  Point& operator-=(const Point<T>& other); 

  template<typename U>
  Point<T> operator*(U scalar) const;
  
  template<typename U>
  Point<T>& operator*=(U scalar);
  
  template<typename U>
  friend Point<T> operator*(U lhs, Point<T> rhs);

  template<typename U>
  Point operator/(U scalar) const;
  
  template<typename U>
  Point& operator/=(U scalar);

  double operator*(const Point<T>& other) const;

  // TODO: is it possible to templatize the return type:
  //template<typename Scalar>
  //Scalar operator^(const Point<T>& other){
  double operator^(const Point<T>& other) const;
  
  double dist(const Point<T>& other) const;

  double norm() const;
  
  double angle(const Point<T>& other) const;
  
  template<typename U>
  friend std::ostream& operator<<(std::ostream& os, const Point<U>& p);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p);


#endif //__POINT_H__
