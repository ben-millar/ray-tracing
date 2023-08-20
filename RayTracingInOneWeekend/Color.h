#pragma once

#include <iostream>
#include "vec3.h"

using Color = Vec3;

void writeColor(std::ostream& t_out, Color t_pixelColor) {
    // Write the translated [0,255] value of each color component.
    t_out << static_cast<int>(255.999 * t_pixelColor.x()) << ' '
        << static_cast<int>(255.999 * t_pixelColor.y()) << ' '
        << static_cast<int>(255.999 * t_pixelColor.z()) << '\n';
}
