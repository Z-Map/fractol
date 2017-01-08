#version 120

attribute vec3 v_pos;
attribute vec2 v_uv;

varying vec2 tex_coord;

void main()
{
	gl_Position.xyz = v_pos;
	gl_Position.w = 1.0;
	tex_coord = v_uv;
}
