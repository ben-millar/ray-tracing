#pragma once

#include <random>
#include <cstdlib>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.1415926535897932385;

inline double deg2rad(double degrees) {
	return degrees * pi / 180.0;
}

inline double random(double t_min = 0.0,double t_max = 1.0) {
	static std::uniform_real_distribution<double> distribution(t_min, t_max);
	static std::mt19937_64 generator;
	return distribution(generator);
}

#include "interval.h"
#include "ray.h"
#include "vec3.h"
