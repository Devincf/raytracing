#ifndef CRAY_HPP__
#define CRAY_HPP__

#include "CVec.hpp"

namespace devincf::raytracing::math
{
    template <typename T = float>
    class Ray
    {
        public:
        Ray() { }
        Ray(const Vec3<T>& a, const Vec3<T>& b)
        {
            A = a;
            B = b;
        }

        Vec3<T> origin() const { return A;}
        Vec3<T> direction() const { return B;}
        Vec3<T> point_at_parameter(T t) const { return A + (B * t); }

        Vec3<T> A;
        Vec3<T> B;
    };
}

#endif