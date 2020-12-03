#ifndef _SAMPLER_H
#define _SAMPLER_H
#include "mogumogu/sampler/rng.hpp"

class Sampler {
 private:
  RNG rng;

 public:
  Sampler();

  void setSeed(uint64_t seed);
  virtual float getNext() = 0;
};

#endif