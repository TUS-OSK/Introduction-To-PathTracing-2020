#include "mogumogu/sampler/uniform.hpp"

UniformSampler::UniformSampler() {}

float UniformSampler::getNext() { return rng.uniformFloat(); }