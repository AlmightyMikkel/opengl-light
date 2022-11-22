#pragma  once
#include <iostream>
#include "glfw3.h"
#include <OpenGL/gl3.h> //THIS IS NEEDED FOR MACOS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <numbers>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <cassert>
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texcoords;
    glm::vec3 tangent;
    glm::vec3 bitangent;
    //bone indexes which will influence this vertex
    int m_BoneIDs[4];
    //weights from each bone
    float m_Weights[4];
};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh {

private:
    GLuint vbo, ebo;
    void setup();

public:
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;
    GLuint vao;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    void draw(GLuint shader_program_id);
};
