#include "mogumogu/sampler/sampler.hpp"

Sampler::Sampler() {}

void Sampler::setSeed(uint64_t seed) { rng.setSeed(seed); }