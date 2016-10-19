#pragma once

#include "Geometry.h"
#include "Shader.h"

class BasicShader
    : public Shader
{
private:
    GLint	m_PositionAttributeHandle;

public:
    BasicShader()
    {
        m_VertexShaderCode =
            "attribute vec4 a_vPosition;                    \n"
            "void main(){                                   \n"
            "     gl_Position = a_vPosition;                \n"
            "}                                              \n";

        m_FragmentShaderCode =
            "#version 150                                   \n"
            "precision mediump float;  						\n"
            "void main(){              						\n"
            "    gl_FragColor = vec4(0.2, 0.2, 0.2, 1.0);   \n"
            "}                         						\n";
    }

    ~BasicShader() override = default;

    void Link() override
    {
        Shader::Link();

        m_PositionAttributeHandle = glGetAttribLocation(m_ProgramId, "a_vPosition");
    }

    void Setup(const Geometry& geometry) override
    {
        Shader::Setup(geometry);

        glVertexAttribPointer(
            m_PositionAttributeHandle,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            geometry.GetVertices());
        glEnableVertexAttribArray(m_PositionAttributeHandle);
    }
};
