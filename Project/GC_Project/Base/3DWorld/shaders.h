#ifndef SHADERS_H
#define SHADERS_H

#include <QString>


    static QString vertexShader =
            "#version 330 core\n"
            "\n"
            "layout(location = 0) in vec3 vertexPosition;\n"
            "layout(location = 1) in vec3 vertexNormal;\n"
            "\n"
            "out vec3 normal;\n"
            "out vec3 position;\n"
            "\n"
            "uniform mat4 MV;\n"
            "uniform mat3 N;\n"
            "uniform mat4 MVP;\n"
            " \n"
            "void main()\n"
            "{\n"
            "    normal = normalize( N * vertexNormal );\n"
            "    position = vec3( MV * vec4( vertexPosition, 1.0 ) );\n"
            "    gl_Position = MVP * vec4( vertexPosition, 1.0 );\n"
            "}\n"
            ;

    static QString fragmentShader =
            "#version 330 core\n"
            "\n"
            "in vec3 normal;\n"
            "in vec3 position;\n"
            "\n"
            "layout (location = 0) out vec4 fragColor;\n"
            "\n"
            "struct Light\n"
            "{\n"
            "    vec4 position;\n"
            "    vec3 intensity;\n"
            "};\n"
            "uniform Light light;\n"
            "\n"
            "struct Material {\n"
            "    vec3 Ka;\n"
            "    vec3 Kd;\n"
            "    vec3 Ks;\n"
            "    float shininess;\n"
            "};\n"
            "uniform Material material;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    vec3 n = normalize( normal);\n"
            "    vec3 s = normalize( light.position.xyz - position);\n"
            "    vec3 v = normalize( -position.xyz);\n"
            "    vec3 h = normalize( v + s);\n"
            "    float sdn = dot( s, n);\n"
            "    vec3 ambient = material.Ka;\n"
            "    vec3 diffuse = material.Kd * max( sdn, 0.0);\n"
            "    vec3 specular = material.Ks * mix( 0.0, pow( dot(h, n), material.shininess), step( 0.0, sdn));\n"
            "    fragColor = vec4(light.intensity * (ambient + diffuse + specular), 1);\n"
            "}\n"
            ;



#endif // SHADERS_H
