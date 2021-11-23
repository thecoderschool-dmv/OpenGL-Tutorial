#version 330 core
out vec4 FragColor;
in vec2 VertexPosition;

uniform float IKnowWhatItIsButWhenYouAskMeIDont;

void main()
{
    float Frequency = (VertexPosition.y*VertexPosition.x)*(IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont)*(VertexPosition.y*VertexPosition.x);
    float RValue = (sin(IKnowWhatItIsButWhenYouAskMeIDont*(VertexPosition.y*VertexPosition.x)) / 2.0f) + 0.52f;
    float GValue = (sin((IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont)*(VertexPosition.y*VertexPosition.x)) / 4.0f) + 0.25f;
    float BValue = (sin(IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*IKnowWhatItIsButWhenYouAskMeIDont*VertexPosition.y*VertexPosition.x*VertexPosition.x/pow(IKnowWhatItIsButWhenYouAskMeIDont,IKnowWhatItIsButWhenYouAskMeIDont)*VertexPosition.y) / 10.0f * (67326836)) + 0.74f;
    FragColor = vec4(RValue,GValue,BValue, 1.0f);
}