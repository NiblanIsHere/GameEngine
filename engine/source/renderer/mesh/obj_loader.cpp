#include "renderer/mesh/obj_loader.h"


void objLoader::LoadModel(const char* filePath)
{
    vertices.clear();
    indices.clear();

    std::vector <vec3> vertexPositions;
    std::vector <vec2> vertexTextureCoords;
    std::vector <vec3> vertexNormals;
    std::vector <faceData> faces;

    std::string line;
    std::ifstream file(filePath);
    std::cout << "Load model from file: " << filePath << "\n";

    // Read model file
    if (file.is_open())
    {
        while (getline(file, line))
        {
            // Get the prefix of the line
            std::istringstream ss(line);
            std::string prefix;
            ss >> prefix;

            if (prefix == "v")
            {
                vec3 pos;
                ss >> pos.x >> pos.y >> pos.z;
                vertexPositions.push_back(pos);
            }
            if (prefix == "vt")
            {
                vec2 text;
                ss >> text.x >> text.y;
                vertexTextureCoords.push_back(text);
            }
            if (prefix == "vn")
            {
                vec3 normal;
                ss >> normal.x >> normal.y >> normal.z;
                vertexNormals.push_back(normal);
            }
            if (prefix == "f")
            {
                faceData face;

                std::string v1, v2, v3;
                ss >> v1 >> v2 >> v3;

                auto parseVertex = [](const std::string& s) 
                {
                    uvec3 out = { 0, 0, 0 };

                    std::stringstream vs(s);
                    std::string vStr, vtStr, vnStr;

                    std::getline(vs, vStr,  '/');
                    std::getline(vs, vtStr, '/');
                    std::getline(vs, vnStr, '/');

                    // Convert if present
                    out.x = vStr.empty()  ? 0 : std::stoi(vStr );
                    out.y = vtStr.empty() ? 0 : std::stoi(vtStr);
                    out.z = vnStr.empty() ? 0 : std::stoi(vnStr);

                    return out;
                };

                face.vertex1 = parseVertex(v1);
                face.vertex2 = parseVertex(v2);
                face.vertex3 = parseVertex(v3);

                faces.push_back(face);
            }
        }
        file.close();
    }


    // Add space in memory
    vertices.reserve(faces.size() * 15);

    for (faceData face : faces)
    {
        // Add vertex 1
        // Add vertex pos
        vertices.push_back(vertexPositions[face.vertex1.x - 1].x);
        vertices.push_back(vertexPositions[face.vertex1.x - 1].y);
        vertices.push_back(vertexPositions[face.vertex1.x - 1].z);
        // Add vertex texCoords
        vertices.push_back(vertexTextureCoords[face.vertex1.y - 1].x);
        vertices.push_back(vertexTextureCoords[face.vertex1.y - 1].y);
        // Add vertex normals
        vertices.push_back(vertexNormals[face.vertex1.z - 1].x);
        vertices.push_back(vertexNormals[face.vertex1.z - 1].y);
        vertices.push_back(vertexNormals[face.vertex1.z - 1].z);

        // Add vertex 2
        // Add vertex pos
        vertices.push_back(vertexPositions[face.vertex2.x - 1].x);
        vertices.push_back(vertexPositions[face.vertex2.x - 1].y);
        vertices.push_back(vertexPositions[face.vertex2.x - 1].z);
        // Add vertex texCoords
        vertices.push_back(vertexTextureCoords[face.vertex2.y - 1].x);
        vertices.push_back(vertexTextureCoords[face.vertex2.y - 1].y);
        // Add vertex normals
        vertices.push_back(vertexNormals[face.vertex2.z - 1].x);
        vertices.push_back(vertexNormals[face.vertex2.z - 1].y);
        vertices.push_back(vertexNormals[face.vertex2.z - 1].z);

        // Add vertex 3
        // Add vertex pos
        vertices.push_back(vertexPositions[face.vertex3.x - 1].x);
        vertices.push_back(vertexPositions[face.vertex3.x - 1].y);
        vertices.push_back(vertexPositions[face.vertex3.x - 1].z);
        // Add vertex texCoords
        vertices.push_back(vertexTextureCoords[face.vertex3.y - 1].x);
        vertices.push_back(vertexTextureCoords[face.vertex3.y - 1].y);
        // Add vertex normals
        vertices.push_back(vertexNormals[face.vertex3.z - 1].x);
        vertices.push_back(vertexNormals[face.vertex3.z - 1].y);
        vertices.push_back(vertexNormals[face.vertex3.z - 1].z);

        // Add indices
        unsigned int baseIndex = (vertices.size() / 8) - 3;
        indices.push_back(baseIndex + 0);
        indices.push_back(baseIndex + 1);
        indices.push_back(baseIndex + 2);
    }
}