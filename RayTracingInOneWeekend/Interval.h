#pragma once

#include "utils.h"

class Interval
{
public:
	double min, max;

	Interval() : min(+infinity), max(-infinity) {}
	Interval(double _min, double _max) : min(_min), max(_max) {}

	bool contains(double t_x) const {
		return min <= t_x && t_x <= max;
	}

	bool surrounds(double t_x) const {
		return min < t_x && t_x < max;
	}

	static const Interval empty, universe;
};

const static Interval EMPTY(+infinity, -infinity);
const static Interval UNIVERSE(-infinity, +infinity);
