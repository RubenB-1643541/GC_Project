#ifndef TEXTURE_H
#define TEXTURE_H

#include <windows.h>
#include <gl/GL.h>

#include <SOIL.h>

#include <string>

namespace __3DWorld__ {

class Texture
{
public:
    Texture();
    static GLuint create(std::string path);
};

}

#endif // TEXTURE_H
