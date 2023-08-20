#pragma once

#include "surface.h"
#include "vec3.h"

class Sphere :
    public Surface
{
public:
    Sphere(Point3 t_center, double t_radius)
        : m_center(t_center), m_radius(t_radius) {}

    bool hit(const Ray& t_r, Interval t_interval, Impact& t_impact) const override {
        Vec3 oc = t_r.origin() - m_center;
        auto a = t_r.direction().lengthSquared();
        auto half_b = dot(oc, t_r.direction());
        auto c = oc.lengthSquared() - m_radius * m_radius;

        auto discriminant = half_b * half_b - a * c;
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root within our interval [ray_t]
        auto root = (-half_b - sqrtd) / a;
        if (!t_interval.surrounds(root)) {
            root = (-half_b + sqrtd) / a;
            if (!t_interval.surrounds(root))
                return false;
        }

        t_impact.t = root;
        t_impact.p = t_r.at(t_impact.t);
        t_impact.normal = (t_impact.p - m_center) / m_radius;

        return true;
    }

private:
    Point3 m_center;
    double m_radius;
};
