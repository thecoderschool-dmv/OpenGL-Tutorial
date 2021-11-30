#version 330 core
out vec4 FragColor;
in vec4 VertexPosition;

uniform float t;

void main()
{
    float Frequency = (VertexPosition.y*VertexPosition.x)*(t*t*t*t*t)*(VertexPosition.y*VertexPosition.x);
    float RValue = (sin(t*(VertexPosition.y*VertexPosition.x)) / 2.0f) + 0.52f;
    float GValue = (sin((t*t*t*t)*(VertexPosition.y*VertexPosition.x)) / 4.0f) + 0.25f;
    float BValue = (sin(t*t*t*t*t*t*t*t*t*t*t*t*t*t*t*t*VertexPosition.y*VertexPosition.x*VertexPosition.x/pow(t,t)*VertexPosition.y) / 10.0f * (67326836)) + 0.74f;
    FragColor = vec4(RValue,GValue,BValue, 1.0f);
}