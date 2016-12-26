#version 130

in vec2 tex_coord;
uniform sampler2D image;

out vec4 color;

void main()
{
	color = texture2D(image, tex_coord);
}
