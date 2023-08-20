#pragma once

#include "ray.h"

class Impact {
public:
	Point3 p;
	Vec3 normal;
	double t;
	bool front_face;

	void setFaceNormal(const Ray& r, const Vec3& outward_normal) {
		// NOTE: We assume that 'output_normal' is always of unit length
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class Surface {
public:
	virtual ~Surface() = default;

	virtual bool hit(const Ray& t_r, Interval t_interval, Impact& t_impact) const = 0;
};