#ifndef _SCENARIO_H
#define _SCENARIO_H

#include <map>

class Block
{
public:
    GLint model_uniform;
    GLint view_uniform;
    GLint projection_uniform;
    GLint render_as_black_uniform;
    bool isFixedBlock;
    Block(bool isFixed, GLuint program_id)
    {
        isFixedBlock = isFixed;
        model_uniform = glGetUniformLocation(program_id, "model");
        view_uniform = glGetUniformLocation(program_id, "view");
        projection_uniform = glGetUniformLocation(program_id, "projection");
        render_as_black_uniform = glGetUniformLocation(program_id, "render_as_black");
    };

    void placeOnScene(std::map<const char*, SceneObject> g_VirtualScene, float positionX, float positionZ)
    {
        glm::mat4 model;
        model = Matrix_Translate(positionX, 0.0f, positionZ);

        glUniformMatrix4fv(model_uniform, 1, GL_FALSE, glm::value_ptr(model));

        glUniform1i(render_as_black_uniform, false);

        glDrawElements(
            g_VirtualScene["cube_faces"].rendering_mode,
            g_VirtualScene["cube_faces"].num_indices,
            GL_UNSIGNED_INT,
            (void*)g_VirtualScene["cube_faces"].first_index
        );

        glLineWidth(4.0f);

        glUniform1i(render_as_black_uniform, true);

        glDrawElements(
            g_VirtualScene["cube_edges"].rendering_mode,
            g_VirtualScene["cube_edges"].num_indices,
            GL_UNSIGNED_INT,
            (void*)g_VirtualScene["cube_edges"].first_index
        );
    };

    void explode()
    {
        if (!isFixedBlock)
        {

        }
    };
};

#endif // _SCENARIO_H
