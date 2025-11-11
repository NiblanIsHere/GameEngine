#include "renderer/renderer.h"


void Renderer::setup(MeshManager& meshManagerClassPtr)
{
	// Get the mesh manager class pointer
	meshManagerClass = &meshManagerClassPtr;

	// Load textures
	textureClass.LoadTexture(textureClass.LINEAR, "resources/textures/bwaaa.png");
	textureClass.LoadTexture(textureClass.NEAREST, "resources/textures/gun_item.png");
	textureClass.LoadTexture(textureClass.LINEAR, "resources/textures/grass.png");
	
	// Setup Shaders
	test_BufferObjects.CreateBufferObjects(testVertices, testIndices);
	test_Shader.CreateShaderProgram("basic.vert", "basic.frag");

	// Enable the Z-Buffer
	glEnable(GL_DEPTH_TEST);
}

void Renderer::update()
{
	// Clear screen
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//  Render Meshes
	// ---------------

	// Use the shader
	glUseProgram(test_Shader.shaderProgram);
	// Send camera matrices to shader
	cameraClass.SetMatrices(test_Shader.shaderProgram);

	// Draw all meshes
	for (auto mesh : meshManagerClass->meshObjects)
	{
		// Bind texture to the draw call
		glBindTexture(GL_TEXTURE_2D, mesh.textureIndex);

		// Send Mesh data to the shader
		glBindBuffer(GL_ARRAY_BUFFER, test_BufferObjects.VBO);
		glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(float), mesh.vertices.data(), GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, test_BufferObjects.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), mesh.indices.data(), GL_DYNAMIC_DRAW);

		// Send position data to shader
		unsigned int transformLoc = glGetUniformLocation(test_Shader.shaderProgram, "model");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(mesh.GetModelMatrix()));

		// Draw
		glBindVertexArray(test_BufferObjects.VAO);
		glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);
	}
}

void Renderer::end()
{

}