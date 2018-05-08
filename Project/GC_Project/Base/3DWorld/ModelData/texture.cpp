#include "texture.h"

namespace __3DWorld__ {



Texture::Texture()
{
    _initialized = false;
}

void Texture::addTexture(QString path) {
    _texture = path;
}

void Texture::initialize() {
    glGenTextures(1, &_texture_id);
    glBindTexture(GL_TEXTURE_2D, _texture_id);
    unsigned char * image = SOIL_load_image(_texture.toLatin1(), &_width, &_heigth, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _heigth, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    _initialized = true;
}

void Texture::use() {
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, _texture_id);
}

}
