#include "renderer/renderer.h"


void Renderer::setup()
{
	textureClass.LoadTexture("resources/textures/test.png");

	test_BufferObjects.CreateBufferObjects(testVertices, testIndices);
	test_Shader.CreateShaderProgram("basic.vert", "basic.frag");
}

void Renderer::update()
{
	// Clear screen
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Use the shader
	glUseProgram(test_Shader.shaderProgram);
	// Send camera matrices to shader
	cameraClass.SetMatrices(test_Shader.shaderProgram);
	// Bind texture to the draw call
	glBindTexture(GL_TEXTURE_2D, 1);
	// Draw
	glBindVertexArray(test_BufferObjects.VAO);
	glDrawElements(GL_TRIANGLES, testIndices.size(), GL_UNSIGNED_INT, 0);
}

void Renderer::end()
{

}