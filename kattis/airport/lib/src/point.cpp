#include "../inc/point.h"

#include <cmath>
#include <iostream>

template<typename T>
Point<T>::Point() : x(0), y(0){};

template<typename T>
Point<T>::Point(T x, T y) : x(x), y(y){}

template<typename T>
bool Point<T>::operator==(const Point<T>& other) const {
  return x == other.x && y == other.y;
}

template<typename T>
Point<T> Point<T>::operator+(const Point<T>& other) const {
    return Point(x + other.x, y + other.y);
}

template<typename T>
Point<T>& Point<T>::operator+=(const Point<T>& other) {
  x += other.x, y += other.y;
  return *this;
}

template<typename T>
Point<T> Point<T>::operator-(const Point<T>& other) const {
  return Point<T>(x - other.x, y - other.y);
}

template<typename T>
Point<T>& Point<T>::operator-=(const Point<T>& other) {
  x -= other.x, y -= other.y;
  return *this;
}

template<typename T>
template<typename U>
Point<T> Point<T>::operator*(U scalar) const {
  return Point<T>(x * scalar, y * scalar);
}

template<typename T>
template<typename U>
Point<T>& Point<T>::operator*=(U scalar) {
  x *= scalar, y *= scalar;
  return *this;
}


template<typename T, typename U>
Point<T> operator*(U lhs, Point<T> rhs) {
  rhs *= lhs; return rhs;
}


template<typename T>
template<typename U>
Point<T> Point<T>::operator/(U scalar) const {
  return Point<T>(x / scalar, y / scalar);
}

template<typename T>
template<typename U>
Point<T>& Point<T>::operator/=(U scalar) {
  x /= scalar, y /= scalar;
  return *this;
}

template<typename T>
double Point<T>::operator*(const Point<T>& other) const {
  return x * other.x + y * other.y;
}

  // TODO: is it possible to templatize the return type:
  //template<typename Scalar>
  //Scalar operator^(const Point<T>& other){
template<typename T>
double Point<T>::operator^(const Point<T>& other) const {
  return x * other.y - other.x * y;
}

template<typename T>
double Point<T>::dist(const Point<T>& other) const {
  return sqrt( (other.x - x) * (other.x - x) +
	       (other.y - y) * (other.y - y) );
}

template<typename T>
double Point<T>::norm() const {
  return this->dist(Point<T>(0, 0));
}

template<typename T>
double Point<T>::angle(const Point<T>& other) const {
  return atan2(other.y, other.x) - atan2(y, x);
}
  
template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p){
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

template class Point<int>;
template std::ostream& operator<< <int>(std::ostream& os, const Point<int>& p);
