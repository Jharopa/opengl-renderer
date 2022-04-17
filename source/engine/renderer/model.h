#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>
#include <memory>

#include "defines.h"
#include "mesh.h"

class Model
{
    private:
        std::vector<Mesh> m_meshes;
        std::string m_directory;

    public:
        Model(const std::string& path);

        std::vector<Mesh> getMeshes() { return m_meshes; }

    private:
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
};
