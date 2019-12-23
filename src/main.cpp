#include <iostream>
#include "misc/CFramebuffer.hpp"



using devincf::raytracing::misc::Framebuffer;

int main() 
{
    Framebuffer<300,200> fb;

    for(int i = 0;i<fb.width();i++)
    {
        for (int j = 0;j<fb.height();j++)
        {
            fb.set(i,j,{1.0f,0.0f,1.0f});
        }
    }
    fb.write(); 
}
