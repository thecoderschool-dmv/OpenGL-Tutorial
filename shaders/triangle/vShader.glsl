#version 330 core
layout(location = 0) in vec3 aPos;
out vec4 VertexPosition;
uniform mat4 cheeseburger;

void main()
{
    
    gl_Position = cheeseburger*vec4(aPos.x, aPos.y, aPos.z, 1.0);
    VertexPosition = gl_Position;
}