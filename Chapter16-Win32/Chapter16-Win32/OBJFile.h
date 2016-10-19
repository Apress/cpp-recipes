#pragma once

#include <fstream>
#include <sstream>
#include <string>

class OBJFile
{
public:
    using Vertices = vector < float > ;
    using TextureCoordinates = vector < float > ;
    using Normals = vector < float > ;
    using Indices = vector < unsigned short > ;

private:
    Vertices m_VertexPositions;
    TextureCoordinates m_TextureCoordinates;
    Normals m_Normals;

    Indices m_Indices;

public:
    OBJFile(const std::string& filename)
    {
        std::ifstream fileStream{ filename, std::ios_base::in };
        if (fileStream.is_open())
        {
            while (!fileStream.eof())
            {
                std::string line;
                getline(fileStream, line);

                stringstream lineStream{ line };
                
                std::string firstSymbol;
                lineStream >> firstSymbol;

                if (firstSymbol == "v")
                {
                    float vertexPosition{};

                    for (unsigned int i = 0; i < 3; ++i)
                    {
                        lineStream >> vertexPosition;
                        m_VertexPositions.emplace_back(vertexPosition);
                    }
                }
                else if (firstSymbol == "vt")
                {
                    float textureCoordinate{};

                    for (unsigned int i = 0; i < 2; ++i)
                    {
                        lineStream >> textureCoordinate;
                        m_TextureCoordinates.emplace_back(textureCoordinate);
                    }
                }
                else if (firstSymbol == "vn")
                {
                    float normal{};

                    for (unsigned int i = 0; i < 3; ++i)
                    {
                        lineStream >> normal;
                        m_Normals.emplace_back(normal);
                    }
                }
                else if (firstSymbol == "f")
                {
                    char separator;
                    unsigned short index{};

                    for (unsigned int i = 0; i < 3; ++i)
                    {
                        for (unsigned int j = 0; j < 3; ++j)
                        {
                            lineStream >> index;
                            m_Indices.emplace_back(index);

                            if (j < 2)
                            {
                                lineStream >> separator;
                            }
                        }
                    }
                }
            }
        }
    }

    const Vertices& GetVertices() const
    {
        return m_VertexPositions;
    }

    const TextureCoordinates& GetTextureCoordinates() const
    {
        return m_TextureCoordinates;
    }

    const Normals& GetNormals() const
    {
        return m_Normals;
    }

    const Indices& GetIndices() const
    {
        return m_Indices;
    }
};