#version 460 core
in vec3 outColor;
in vec2 outTex;

uniform sampler2D ourTexture;

out vec4 FragColor;
void main()
{
    FragColor = vec4(outColor, 1.0) * texture(ourTexture, outTex);
}
