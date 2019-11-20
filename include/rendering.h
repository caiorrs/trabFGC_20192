#ifndef _RENDERING_H
#define _RENDERING_H

// Definimos uma estrutura que armazenar� dados necess�rios para renderizar
// cada objeto da cena virtual.
struct SceneObject
{
    const char*  name;        // Nome do objeto
    void*        first_index; // �ndice do primeiro v�rtice dentro do vetor indices[] definido em BuildTriangles()
    int          num_indices; // N�mero de �ndices do objeto dentro do vetor indices[] definido em BuildTriangles()
    GLenum       rendering_mode; // Modo de rasteriza��o (GL_TRIANGLES, GL_TRIANGLE_STRIP, etc.)
};

#endif // _RENDERING_H
