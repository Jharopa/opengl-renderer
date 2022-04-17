#include <glm/glm.hpp>

#include <vector>
#include <memory>
#include <optional>

#include "defines.h"
#include "vertexarray.h"
#include "renderer.h"
#include "texture.h"

struct Vertex 
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoord;
};

class Mesh
{
    private:
        std::shared_ptr<VertexArray> m_vertexArray;
        u32 m_indexCount;

    public:
        Mesh(const std::vector<Vertex> verticies, std::vector<u32> indices);

        [[nodiscard]] std::shared_ptr<VertexArray> getVertexArray() const { return m_vertexArray; }
        [[nodiscard]] u32 getIndexCount() const { return m_indexCount; }
};
