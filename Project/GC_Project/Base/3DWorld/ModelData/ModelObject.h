#ifndef MODEL_OBJECT
#define MODEL_OBJECT


#include <QString>
#include <windows.h> // Needed to compile gl.h
#include <gl/GL.h>
#include <gl/GLU.h>
#include <modelloader.h>
#include "Settings.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief
 */



class ModelObject {
public:
    ModelObject(QString Path);
    void draw(GLenum s_mode, GLenum f_mode);
    GLuint initialize();



private:

    ModelLoader _loader;

    std::vector<MLMesh> _meshes;
};
}

#endif MODEL_OBJECT
