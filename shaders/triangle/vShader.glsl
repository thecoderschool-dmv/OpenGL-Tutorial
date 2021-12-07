#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 lo;
out vec4 VertexPosition;
out vec2 TextureCoord;
uniform mat4 cheeseburger;

void main()
{
    
    gl_Position = cheeseburger*vec4(aPos.x, aPos.y, aPos.z, 1.0);
    VertexPosition = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    TextureCoord = lo;
}