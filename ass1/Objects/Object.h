//
// Created by roland on 9/30/20.
//

#ifndef SIMPLE_SCENE_OBJECT_H
#define SIMPLE_SCENE_OBJECT_H

#include "glm/glm.hpp"
#include "stdafx.h"

#include "OpenGL/OpenGLMesh.h"
#include "OpenGL/OpenGLBuffer.h"
#include "OpenGL/OpenGLShader.h"

class VertexArray;
class Shader;

class Object {
private:
    glm::mat4 transform = glm::mat4(-1.0f);
    SharedPtr<VertexArray> VAO;
public:
    // Transform
    const glm::mat4 & GetTransformMatrix() const;
    void SetTransform(glm::mat4 const& transform);

    // VAO
    void SetVAO(SharedPtr<VertexArray> const & VAO);
    SharedPtr<VertexArray> & GetVAO();

    // Shader
    std::vector<SharedPtr<Shader>> const & GetShaders() const;
    void AddShaderPass(SharedPtr<Shader> const & shader);
    void ReplaceShader(SharedPtr<Shader> const & shader);

    // Children
    std::vector<SharedPtr<Object>> children;
    void AddChild(SharedPtr<Object> const & child);

    // Update function
    void SetUpdate(std::function<void(Object&, glm::mat4 const &)> lambda);
    void Update(glm::mat4 const & objMatrix = glm::mat4(1.0f));

    bool Renderable = true;
private:
    std::function<void(Object&, glm::mat4 const &)> updateFunction;
    std::vector<SharedPtr<Shader>> shaders;
};


#endif //SIMPLE_SCENE_OBJECT_H
