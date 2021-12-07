#version 330 core
out vec4 FragColor;
in vec2 VertexPosition;
in vec2 TextureCoord;

uniform vec3 CurrentColor;
uniform sampler2D texture1;

void main()
{
    
    FragColor = vec4(1,0,1,1);
}