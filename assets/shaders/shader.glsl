#shader vertex
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec4 ourColor;
out vec2 TexCoord;

void main()
{
   ourColor = vec4(aColor, 1.0);
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   TexCoord = aTexCoord;
}

#shader fragment
#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
   //FragColor = texture(texture0, TexCoord) * ourColor;
   FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord*2), 0.2);
}
