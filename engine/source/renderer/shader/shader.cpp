#include "renderer/shader/shader.h"


std::string Shader::ReadFile(const char* fileName)
{
    shaderCode = "";
    std::string line;
    std::ifstream file(shaderFolder + fileName); // Shader file 
    std::cout << shaderFolder + fileName << "\n";

    if (file.is_open())
    {
        // Loop through every line and add the line to shaderCode
        while (getline(file, line))
        {
            shaderCode += line + "\n";
        }
        // Close file and return the data
        file.close();
        return shaderCode;
    }
    // If failed to open the file, print error message and return "ERROR"
    std::cout << "Error: Can't open file: " << shaderFolder + fileName << "\n";
    return "ERROR";
}

void Shader::CreateShaderProgram(const char* vertexShaderName, const char* fragmentShaderName)
{
    // Load shader code it to variables
    std::string vertexShaderCode = ReadFile(vertexShaderName);
    std::string fragmentShaderCode = ReadFile(fragmentShaderName);
    // Convert it to the file source code of chars instead of string so opengl can read it
    const char* vertexShaderSource = vertexShaderCode.c_str();
    const char* fragmentShaderSource = fragmentShaderCode.c_str();

    //  Vertex shader
    // ---------------

    // Create vertex shader object
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Add the vertex shader source code to the vertex shader object, and compile the shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // Check for compiling errors
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Error: Failed to compile the vertex shader\n" << infoLog << "\n";
    }


    //  Fragment shader
    // -----------------

    // Create fragment shader object
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Add the fragment shader source code to the fragment shader object, and compile the shader
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // Check for compiling errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Error: Failed to compile the fragment shader\n" << infoLog << "\n";
    }


    //  Shader program
    // ----------------

    // Create shader program object
    shaderProgram = glCreateProgram();
    // Link the shader to the shader program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Error: Failed to link the shader program\n" << infoLog << "\n";
    }

    // Delete shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::setFloat(const char* variableName, float value)
{
    unsigned int variableLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniform1f(variableLoc, value);
}

void Shader::setVec3(const char* variableName, vec3 value)
{
    unsigned int variableLoc = glGetUniformLocation(shaderProgram, variableName);
    glUniform3f(variableLoc, value.x, value.y, value.z);
}