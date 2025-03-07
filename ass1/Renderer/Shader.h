//
// Created by roland on 9/24/20.
//

#ifndef SIMPLE_SCENE_SHADER_H
#define SIMPLE_SCENE_SHADER_H

/*enum Primitive_Enum
{
    TriangleStrip = 0,
    Points,
    LineStrip
};*/

class Shader
{
public:
    virtual ~Shader() = default;
    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual void SetInt(std::string const & name, int value ) = 0;
    virtual void SetFloat(std::string const & name, float value ) = 0;
    virtual void SetFloat3(std::string const & name, glm::vec3 const & value ) = 0;
    virtual void SetFloat4(std::string const & name, glm::vec4 const & value ) = 0;
    virtual void SetMat4(std::string const & name, glm::mat4 const & value ) = 0;
    virtual void SetMat3(std::string const & name, glm::mat3 const &  value ) = 0;

    virtual const std::string& GetPath(int pathID) const = 0;
    virtual const std::string& GetName() const = 0;

    static SharedPtr<Shader> Create(std::string const & filePath);
    static SharedPtr<Shader> Create(std::string const & name,
                                    std::string const & vertexSrc,
                                    std::string const & fragmentSrc,
                                    std::string const & geomSrc = std::string());

    virtual void Reload(std::string const & vertexSrc,
                                    std::string const & fragmentSrc,
                                    std::string const & geomSrc) = 0;
};

class ShaderLibrary
{

public:
    ShaderLibrary();

    void Add(std::string const & name, SharedPtr<Shader> const & shader);
    void Add(SharedPtr<Shader> const & shader);

    SharedPtr<Shader> Load(std::string const & filepath);
    SharedPtr<Shader> Load(std::string const &name, std::string const &filepath);

    SharedPtr<Shader> Get(std::string const & name);
    bool Exists(std::string const & name) const;

    const SharedPtr<Shader>& Reload(std::string const &name);

private:
    std::unordered_map<std::string,SharedPtr<Shader>> Shaders;
    std::unordered_map<std::string, std::tuple<std::string, std::string, std::string>> ShaderFilePaths;

    SharedPtr<Shader> DefaultShader;

    friend void ImGui_ShaderLibrary(ShaderLibrary & shaderlib);
};

#endif //SIMPLE_SCENE_SHADER_H
