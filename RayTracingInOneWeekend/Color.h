#pragma once

#include <iostream>
#include "vec3.h"

using Color = Vec3;

void writeColor(std::ostream& t_out, Color t_pixelColor, int samplesPerPixel) {
    auto r = t_pixelColor.x();
    auto g = t_pixelColor.y();
    auto b = t_pixelColor.z();

    // Divide by the number of samples to get the mean
    auto scale = 1.0 / samplesPerPixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component.
    t_out << static_cast<int>(256 * std::clamp(r, 0.000, 0.999)) << ' '
        << static_cast<int>(256 * std::clamp(g, 0.000, 0.999)) << ' '
        << static_cast<int>(256 * std::clamp(b, 0.000, 0.999)) << '\n';
}
