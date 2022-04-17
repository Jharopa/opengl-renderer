#include "mesh.h"

Mesh::Mesh(const std::vector<Vertex> verticies, std::vector<u32> indices)
    : m_indexCount(indices.size())
{
    m_vertexArray = std::make_shared<VertexArray>();

    m_vertexArray->bind();

    m_vertexArray->attachBuffer(BufferType::VERTEX, verticies.size() * sizeof(Vertex), DrawMode::STATIC, &verticies[0]);
    m_vertexArray->attachBuffer(BufferType::INDEX, indices.size() * sizeof(u32), DrawMode::STATIC, &indices[0]);

    m_vertexArray->enableAttribute(0, 3, sizeof(Vertex), (void*)0);
    m_vertexArray->enableAttribute(1, 3, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    m_vertexArray->enableAttribute(2, 2, sizeof(Vertex), (void*)offsetof(Vertex, textureCoord));

    m_vertexArray->unbind();
}
