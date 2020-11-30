#include "mogumogu/accel/accel.hpp"

Accel::Accel() {}

void Accel::addPrimitive(const Primitive& primitive) { primitives.push_back(primitive); }