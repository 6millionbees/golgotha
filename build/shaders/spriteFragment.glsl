#version 460 core
in vec2 outTex;

uniform vec3 spriteColor;
uniform sampler2D ourTexture;

out vec4 FragColor;

void main()
{
    FragColor = vec4(spriteColor, 1.0) * texture(ourTexture, outTex);
}
