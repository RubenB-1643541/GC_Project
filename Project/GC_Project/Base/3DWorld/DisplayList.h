#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include <windows.h>
#include <gl/GL.h>

#include "modelloader.h"

namespace __3DWorld__ {

class DisplayList
{
public:
    DisplayList();
    static GLuint create(std::string path);
};

}

#endif // DISPLAYLIST_H
