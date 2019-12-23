#ifndef CVEC_HPP__
#define CVEC_HPP__

#include <cmath>
#include <istream>
#include <ostream>

namespace devincf::raytracing::math
{
template <typename T = float>
class Vec3
{
public:
    Vec3() {}
    Vec3(const T x, const T y, const T z) : m_elements{x, y, z} {}
    Vec3(const std::array<T, 3> &elements) : m_elements{elements} {}
    Vec3(const std::array<T, 3> &&elements) : m_elements{elements} {}

    inline Vec3<T>& operator+() { return *this; }
    inline Vec3<T> operator-() { return Vec3<T>(-x(), -y(), -z()); }

    inline T operator[](int i) const { return m_elements[i];}
    inline T& operator[](int i) { return m_elements[i];}

    inline Vec3<T> operator +=(const Vec3<T>& rhs) { m_elements[0] += rhs.x();m_elements[1] += rhs.y();m_elements[2] += rhs.z(); return *this; }
    inline Vec3<T> operator -=(const Vec3<T>& rhs) { m_elements[0] -= rhs.x();m_elements[1] -= rhs.y();m_elements[2] -= rhs.z(); return *this; }
    inline Vec3<T> operator *=(const float rhs) { m_elements[0] *= rhs;m_elements[1] *= rhs;m_elements[2] *= rhs; return *this; }
    inline Vec3<T> operator *=(const int rhs) { m_elements[0] *= rhs;m_elements[1] *= rhs;m_elements[2] *= rhs; return *this; }
    inline Vec3<T> operator /=(const float rhs) { m_elements[0] /= rhs;m_elements[1] /= rhs;m_elements[2] /= rhs; return *this; }
    inline Vec3<T> operator /=(const int rhs) { m_elements[0] /= rhs;m_elements[1] /= rhs;m_elements[2] /= rhs; return *this; }

    inline Vec3<T> operator +(const Vec3<T>& rhs) const { return Vec3<T>(x() + rhs.x(), y() + rhs.y(), z() + rhs.z()); }
    inline Vec3<T> operator -(const Vec3<T>& rhs) const { return Vec3<T>( x() - rhs.x(), y() - rhs.y(), z() - rhs.z()); }
    inline Vec3<T> operator *(const int scalar) const { return Vec3<T>( x() * scalar, y() * scalar, z() * scalar); }
    inline Vec3<T> operator *(const float scalar) const { return Vec3<T>( x() * scalar, y() * scalar, z() * scalar); }
    inline Vec3<T> operator /(const int scalar) const { return Vec3<T>( x() / scalar, y() / scalar, z() / scalar); }
    inline Vec3<T> operator /(const float scalar) const { return Vec3<T>( x() / scalar, y() / scalar, z() / scalar); }

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
        this *= k;
    }
private:
    std::array<T, 3> m_elements;
};

template <typename T>
Vec3<T> unit_vector(const Vec3<T>& v) 
{
    return v / v.len();
}

template <typename T>
inline std::istream& operator>>(std::istream& iss, const Vec3<T>& v)
{
    iss >> v[0] >> v[1] >> v[2];
    return iss;
}
template <typename T>
inline std::ostream& operator<<(std::ostream& oss, const Vec3<T>& v)
{
    oss <<  int(255.99*v[0]) << ' ' << int(255.99*v[1]) << ' ' << int(255.99*v[2]);
    return oss;
}
} // namespace devincf::raytracing::math

#endif