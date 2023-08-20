### Overview
The purpose of this project is to learn more about the practical implementation of ray-tracing and computer graphics programming in C++. While I do have plenty of practice using graphics libraries like SFML/SDL, I felt it would be interesting to take a more low-level approach and build the required systems using pure C/C++.

I'm using the excellent resources at https://github.com/RayTracing/raytracing.github.io to guide this project.

### Progress
## Day 1 (20/08/2023)
Today, I've managed to implement the following:
- Camera: This class represents the camera through which we view the scene, and handles things like the aspect ratio, image dimensions, viewport dimensions, focal length etc., as well as calculating the colour value for a given pixel.
- Vec3/Color/Point: This is a simple 3-dimensional vector with several utility functions to do things like add, subtract, divide. `Color` and `Point` using directives have been added for the sake of clarity when handling both colour vectors and points in space.
- Ray: This class represents a ray, represented parametrically by an origin and a direction. Its interface allows us to retrieve those two properties, as well as an `Vec3 at(double t)` which returns the vector in space of a given point _t_ along the ray.
- Impact: This is essentially a struct which holds some information on a ray intersection such as position, face normal, the parametric distance along the ray _t_, and a bool `front_face` which stores whether the ray hit the front-face or the back-face of a surface.
- Surface: This abstract class represents any solid surface which our rays can interact with, and has a single `bool hit(...)` function which determines if a given ray hit this surface. It also takes an `interval` in which to check for the collision, if we want to bound it, and an `Impact&` where we can store hit data.

So far, I've used this to draw two spheres to an image with colouring determined by their respective normal maps. The background colour is a blue gradient which has its hue determined by the x and y positions of the pixel, just so it looks relatively interesting :)

The raw `.ppm` image file can be found in `RayTracingInOneWeekend/`, but you can view it as a `.png` below:

![Ray-traced image of two spheres showing their normal map](/Images/image.png)