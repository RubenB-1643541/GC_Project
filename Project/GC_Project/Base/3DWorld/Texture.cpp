#include "Texture.h"
#include <QDebug>

namespace __3DWorld__ {

Texture::Texture()
{

}

GLuint Texture::create(std::string path) {
    GLuint id;

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    int width, height;
    unsigned char* image = SOIL_load_image(path.c_str() , &width, &height, 0, SOIL_LOAD_RGB);
    qDebug() << width << height;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)width, (GLsizei)height, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*)image);
    int error = glGetError();
    if (error == GL_INVALID_VALUE)
        qDebug() << "GL_INVALID_VALUE" << error;
    if (error == GL_INVALID_OPERATION)
        qDebug() << "GL_INVALID_OPERATION" << error;

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    return id;
}

}
