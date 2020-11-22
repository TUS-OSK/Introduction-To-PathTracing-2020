#ifndef _INTERSECT_INFO_H
#define _INTERSECT_INFO_H

#include "mogumogu/type.hpp"
#include "mogumogu/vec.hpp"

struct IntersectInfo {
  IntersectInfo() {}

  Real t;
  Vec3 hitPos;
  Vec3 hitNormal;
  Vec3 dpdu;
  Vec3 dpdv;
};

#endif