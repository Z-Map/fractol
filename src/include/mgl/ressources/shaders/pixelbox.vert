#version 130

in vec3 v_pos;
in vec2 v_uv;

out vec2 tex_coord;

void main()
{
	gl_Position.xyz = v_pos;
	gl_Position.w = 1.0;
	tex_coord = v_uv;
}
