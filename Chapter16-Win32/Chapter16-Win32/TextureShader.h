#pragma once

#include "Shader.h"
#include <cassert>
#include <memory>
#include "Texture.h"

class Geometry;

class TextureShader
    : public Shader
{
private:
    const Texture& m_Texture;

    GLint m_PositionAttributeHandle;
    GLint m_TextureCoordinateAttributeHandle;
    GLint m_SamplerHandle;

public:
    TextureShader(const Texture& texture)
        : m_Texture(texture)
    {
        m_VertexShaderCode =
            "attribute  vec4 a_vPosition;                   \n"
            "attribute  vec2 a_vTexCoord;                   \n"
            "varying    vec2 v_vTexCoord;                   \n"
            "                                               \n"
            "void main() {                                  \n"
            "   gl_Position = a_vPosition;                  \n"
            "   v_vTexCoord = a_vTexCoord;                  \n"
            "}                                              \n";

        m_FragmentShaderCode =
            "#version 150                                   \n"
            "                                               \n"
            "varying vec2 v_vTexCoord;                      \n"
            "uniform sampler2D s_2dTexture;                 \n"
            "                                               \n"
            "void main() {                                  \n"
            "   gl_FragColor =                              \n"
            "       texture2D(s_2dTexture, v_vTexCoord);    \n"
            "}                                              \n";
    }

    ~TextureShader() override = default;

    void Link() override
    {
        Shader::Link();

        m_PositionAttributeHandle = glGetAttribLocation(m_ProgramId, "a_vPosition");
        m_TextureCoordinateAttributeHandle = glGetAttribLocation(m_ProgramId, "a_vTexCoord");

        m_SamplerHandle = glGetUniformLocation(m_ProgramId, "s_2dTexture");
    }

    void Setup(const Geometry& geometry) override
    {
        Shader::Setup(geometry);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_Texture.GetId());
        glUniform1i(m_SamplerHandle, 0);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glVertexAttribPointer(
            m_PositionAttributeHandle,
            geometry.GetNumVertexPositionElements(),
            GL_FLOAT,
            GL_FALSE,
            geometry.GetVertexStride(),
            geometry.GetVertices());
        glEnableVertexAttribArray(m_PositionAttributeHandle);

        glVertexAttribPointer(
            m_TextureCoordinateAttributeHandle,
            geometry.GetNumTexCoordElements(),
            GL_FLOAT,
            GL_FALSE,
            geometry.GetVertexStride(),
            geometry.GetTexCoords());
        glEnableVertexAttribArray(m_TextureCoordinateAttributeHandle);
    }
};