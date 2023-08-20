#include <iostream>
#include <fstream>

#include "utils.h"

#include "Camera.h"
#include "Surfaces.h"
#include "Sphere.h"


int main() {
    Surfaces world;
    world.add(make_shared<Sphere>(Point3(0.0, 0.0, -1.0), 0.5));
    world.add(make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100.0));

    Camera cam;

    cam.aspectRatio = 16.0 / 9.0;
    cam.imageWidth = 400;

    std::ofstream file;
    file.open("image.ppm");

    cam.render(world, file);

    file.close();

    return 0;
};