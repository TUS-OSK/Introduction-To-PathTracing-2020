#include "mogumogu/sampler/rng.hpp"

RNG::RNG() {}

void RNG::setSeed(uint64_t seed) { pcg32State.state = seed; }

float RNG::uniformFloat() { return pcg32_random_r(&pcg32State) * uint32MaxInv; }