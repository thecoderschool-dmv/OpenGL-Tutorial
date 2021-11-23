#version 330 core
out vec4 FragColor;
in vec2 VertexPosition;

uniform vec3 CurrentColor;

void main()
{
    FragColor = vec4(CurrentColor.xyz, 1.0f);
}