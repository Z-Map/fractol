#version 120

attribute vec3	v_pos;
attribute vec2	v_uv;

uniform vec2	screen;
uniform vec2	position;
uniform vec2	size;

varying vec2	tex_coord;


void main()
{
	vec4 imgpos = vec4(
		(position.x / screen.x) * 2.0f - 1.0f, 0.0f,
		(size.x / screen.x) * 2.0f,
		(size.y / screen.y) * 2.0f);
	imgpos.y = 1.0f - (((position.y / screen.y) * 2.0f) + imgpos.w);
	gl_Position.xyz = vec3(
		imgpos.x + ((v_pos.x + 1.0f) * 0.5f) * imgpos.z,
		imgpos.y + ((v_pos.y + 1.0f) * 0.5f) * imgpos.w,
		v_pos.z);
	gl_Position.w = 1.0;
	tex_coord = v_uv;
}
