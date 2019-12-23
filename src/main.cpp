#include <iostream>
#include "misc/CFramebuffer.hpp"
#include "math/CRay.hpp"


using devincf::raytracing::misc::Framebuffer;
using devincf::raytracing::math::Vec3;
using devincf::raytracing::math::Ray;

template <typename T>
Vec3<T> color(const Ray<T>& r)
{
    Vec3<T> unit_direction = devincf::raytracing::math::unit_vector(r.direction());
    float t = 0.5f*(unit_direction.y() + 1.0f);
    auto res = (Vec3<T>(0.5f, 0.7f, 1.0f) * (1.0f-t)) + (Vec3<T>(1.0f, 1.0f, 1.0f) * t);
    if(t>0.8f) std::cout << res << '\n';
    return res;
}

int main() 
{
    constexpr int W = 200, H = 100;
    Framebuffer<W,H> fb;

    Vec3<> origin{0.0f,0.0f,0.0f};
    Vec3<> horizontal{4.0f,0.0f,0.0f};
    Vec3<> vertical{0.0f,2.0f,0.0f};
    Vec3<> lower_left_corner{-2.0f,-1.0f,-1.0f};

    for(int i = fb.height()-1;i>=0;i--)
    {
        for (int j = 0;j<fb.width();j++)
        {
            float u = float(j) / float(W);
            float v = float(i) / float(H);
            Ray<float> r(origin, lower_left_corner + (horizontal * u) + (vertical * v));
            fb.set(j,i,color(r));
        }
    }
    fb.write(); 
}
