#pragma once

#include "utils.h"

#include "color.h"
#include "surface.h"

class Camera
{
public:
    double aspectRatio = 16.0 / 9.0;
    int imageWidth = 400;

    void render(const Surface& _world, std::ostream& _target) {
        initialize();

        _target << "P3\n" << imageWidth << ' ' << m_imageHeight << "\n255\n";

        for (int j = 0; j < m_imageHeight; ++j)
        {
            std::clog << "\rScanlines remaining: " << (m_imageHeight - j) << ' ' << std::flush;
            for (int i = 0; i < imageWidth; ++i)
            {
                auto pixel_center = m_pixel00_loc + (i * m_pixel_delta_u) + (j * m_pixel_delta_v);
                auto ray_direction = pixel_center - m_center;
                Ray r(m_center, ray_direction);

                Color pixel_color = rayColor(r, _world);
                writeColor(_target, pixel_color);
            }
        }

        std::clog << "\rDone.                 \n";
    }

private:
    int    m_imageHeight;    // Rendered image height
    Point3 m_center;         // Camera center
    Point3 m_pixel00_loc;    // Location of pixel 0, 0
    Vec3   m_pixel_delta_u;  // Offset to pixel to the right
    Vec3   m_pixel_delta_v;  // Offset to pixel below

    void initialize() {
        m_imageHeight = static_cast<int>(imageWidth / aspectRatio);
        m_imageHeight = (m_imageHeight < 1) ? 1 : m_imageHeight;

        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (static_cast<double>(imageWidth) / m_imageHeight);
        auto camera_center = Point3(0, 0, 0);

        // Calculate the vectors across the horizontal and down the vertical viewport edges
        auto viewport_u = Vec3(viewport_width, 0, 0);
        auto viewport_v = Vec3(0, -viewport_height, 0);

        // Calculate the horizontal and vertical delta vectors from pixel to pixel
        m_pixel_delta_u = viewport_u / imageWidth;
        m_pixel_delta_v = viewport_v / m_imageHeight;

        // Calculate the location of the upper-left pixel
        auto viewport_upper_left = camera_center
            - Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
        m_pixel00_loc = viewport_upper_left + 0.5 * (m_pixel_delta_u + m_pixel_delta_v);
    }

    Color rayColor(const Ray& t_r, const Surface& t_world) {
        Impact impact;

        if (t_world.hit(t_r, Interval(0, infinity), impact)) {
            return 0.5 * (impact.normal + Color(1, 1, 1));
        }

        Vec3 unit_direction = unit(t_r.direction());
        auto a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
    }
};

