#ifndef CVEC_HPP__
#define CVEC_HPP__

#include <cmath>

namespace devincf::raytracing::math
{
template <typename T>
class Vec3
{
public:
    Vec3() {}
    Vec3(T x, T y, T z) : m_elements{x, y, z} {}
    Vec3(const std::array<T, 3> &elements) : m_elements{elements} {}
    Vec3(const std::array<T, 3> &&elements) : m_elements{elements} {}

    inline Vec3<T>& operator+() { return *this; }
    inline Vec3<T>& operator-() { return {-x(), -y(), -z()}; }

    inline T operator[](int i) const { return m_elements[i];}
    inline T& operator[](int i) { return m_elements[i];}

    inline Vec3<T>& operator +=(const Vec3<T>& rhs) { return { x() + rhs.x(), y() + rhs.y(), z() + rhs.z()}; }
    inline Vec3<T>& operator -=(const Vec3<T>& rhs) { return { x() - rhs.x(), y() - rhs.y(), z() - rhs.z()}; }
    inline Vec3<T>& operator *=(const int scalar) { return { x() * scalar, y() * scalar, z() * scalar}; }
    inline Vec3<T>& operator *=(const float scalar) { return { x() * scalar, y() * scalar, z() * scalar}; }
    inline Vec3<T>& operator /=(const int scalar) { return { x() / scalar, y() / scalar, z() / scalar}; }
    inline Vec3<T>& operator /=(const float scalar) { return { x() / scalar, y() / scalar, z() / scalar}; }

    inline T r() const { return m_elements[0]; }
    inline T g() const { return m_elements[1]; }
    inline T b() const { return m_elements[2]; }

    inline T x() const { return m_elements[0]; }
    inline T y() const { return m_elements[1]; }
    inline T z() const { return m_elements[2]; }

    inline float len() const { return std::sqrt(squared_len()); }
    inline float squared_len() const { return x() * x() + y() * y() + z() * z(); }
    inline void make_unit_vector() 
    {         
        float k = 1.0 / len();
        this[0] *= k; 
        this[1] *= k; 
        this[2] *= k; 
    }
private:
    std::array<T, 3> m_elements;
};

template <typename T>
inline std::istream& operator>>(std::istream& iss, Vec3<T>& v)
{
    iss >> v[0] >> v[1] >> v[2];
    return iss;
}
template <typename T>
inline std::ostream& operator>>(std::ostream& oss, Vec3<T>& v)
{
    oss <<  int(255.99*v[0]) << ' ' << int(255.99*v[1]) << ' ' << int(255.99*v[2]);
    return oss;
}

} // namespace devincf::raytracing::math

#endif