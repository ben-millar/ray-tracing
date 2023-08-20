#pragma once

#include <memory>
#include <vector>

#include "Interval.h"
#include "Surface.h"

using std::shared_ptr;
using std::make_shared;

class Surfaces :
    public Surface
{
public:
    std::vector<shared_ptr<Surface>> surfaces;

    Surfaces() {}

    template<typename... Args>
    Surfaces(Args... t_surfaces) { add(t_surfaces...); }

    void clear() { surfaces.clear(); }

    template<typename... Args>
    void add(Args... t_surfaces) {
        (surfaces.push_back(t_surfaces), ...);
    }

    bool hit(const Ray& t_r, Interval t_interval, Impact& t_impact) const override {
        Impact temp_impact;
        bool hit_anything = false;
        auto closest_so_far = t_interval.max;

        for (const auto& object : surfaces) {
            if (object->hit(t_r, Interval(t_interval.min, closest_so_far), temp_impact)) {
                hit_anything = true;
                closest_so_far = temp_impact.t;
                t_impact = temp_impact;
            }
        }

        return hit_anything;
    }
};
