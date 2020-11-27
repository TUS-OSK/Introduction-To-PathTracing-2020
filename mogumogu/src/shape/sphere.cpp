#include "mogumogu/shape/sphere.hpp"

Sphere::Sphere(const Vec3& _center, float _radius) : center(_center), radius(_radius) {}

bool Sphere::intersect(const Ray& ray, IntersectInfo& info) const { return false; }