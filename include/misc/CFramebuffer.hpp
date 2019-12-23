#ifndef CFRAMEBUFFER_HPP__
#define CFRAMEBUFFER_HPP__

#include <fstream>
#include <array>
#include "math/CVec.hpp"

using devincf::raytracing::math::Vec3;

namespace devincf::raytracing::misc
{
    template <int W, int H>
    class Framebuffer
    {
        public:
        void write()
        {
            std::ofstream f("file.ppm");
            f << "P3\n" << W << ' ' << H << '\n' << 255 << '\n'; 
            for(size_t r = 0;r<H;r++)
            {
                for(size_t c = 0;c<W;c++)
                {
                    if(c != 0) f << ' ';

                    f << m_pixels[r][c];
                }
                f << '\n';
            }
        }

        void set(int c, int r, const Vec3<>& color)
        {
            m_pixels[r][c] = std::move(color);
        }
        void set(int c, int r, Vec3<>&& color)
        {
            m_pixels[r][c] = std::move(color);
        }

        constexpr int width(){ return W;}
        constexpr int height(){ return H;}
        private:
        std::array<std::array<Vec3<>,W>,H> m_pixels;
    };
}

#endif