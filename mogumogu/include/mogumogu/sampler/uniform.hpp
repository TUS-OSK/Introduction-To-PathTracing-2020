#ifndef _UNIFORM_H
#define _UNIFORM_H
#include "mogumogu/sampler/sampler.hpp"

class UniformSampler : public Sampler {
 public:
  UniformSampler();
  float getNext() override;
};

#endif