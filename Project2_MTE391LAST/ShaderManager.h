#pragma once
#include <SDL.h>
#include <GL/glew.h>
class ShaderManager
{
private:
	GLuint shaderProgram;
	GLuint vertexShader;
	GLuint fragmentShader;
	const GLchar* vertexSource;
	const GLchar* fragmentSource; // optional
public:
	ShaderManager(const GLchar* source1, const GLchar* source2);

	void run();

	~ShaderManager();

	GLuint getProgramId();
};


