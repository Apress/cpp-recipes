#pragma once

#include "GL/glew.h"
#include "TGAFile.h"

class Texture
{
private:
    unsigned int m_Width{};
    unsigned int m_Height{};
    unsigned int m_BytesPerPixel{};
    unsigned int m_DataSize{};

    GLuint m_Id{};
    
    void* m_pImageData;

public:
    Texture(const TGAFile& tgaFile)
        : Texture(tgaFile.GetWidth(),
            tgaFile.GetHeight(),
            tgaFile.GetBytesPerPixel(),
            tgaFile.GetDataSize(),
            tgaFile.GetImageData())
    {

    }

    Texture(unsigned int width,
            unsigned int height,
            unsigned int bytesPerPixel,
            unsigned int dataSize,
            void* pImageData)
        : m_Width(width)
        , m_Height(height)
        , m_BytesPerPixel(bytesPerPixel)
        , m_DataSize(dataSize)
        , m_pImageData(pImageData)
    {

    }

    ~Texture() = default;

    GLuint GetId() const
    {
        return m_Id;
    }

    void Init()
    {
        GLint packBits{ 4 };
        GLint internalFormat{ GL_RGBA };
        GLint format{ GL_BGRA };

        glGenTextures(1, &m_Id);
        glBindTexture(GL_TEXTURE_2D, m_Id);
        glPixelStorei(GL_UNPACK_ALIGNMENT, packBits);
        glTexImage2D(GL_TEXTURE_2D,
            0,
            internalFormat,
            m_Width,
            m_Height,
            0,
            format,
            GL_UNSIGNED_BYTE,
            m_pImageData);
    }
};