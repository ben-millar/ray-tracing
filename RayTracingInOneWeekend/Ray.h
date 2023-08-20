#pragma once

#include "vec3.h"

class Ray
{
public:
	Ray() {}
	Ray(const Point3& t_origin, const Vec3& t_direction)
		: m_orig(t_origin), m_dir(t_direction) {}

	Point3 origin() const { return m_orig; }
	Vec3 direction() const { return m_dir; }

	Point3 at(double t_dist) const {
		return m_orig + t_dist * m_dir;
	}

private:
	Point3 m_orig;
	Vec3 m_dir;
};
