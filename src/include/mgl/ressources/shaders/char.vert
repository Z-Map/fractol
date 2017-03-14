#version 120

attribute vec2	vertice;
attribute vec2	offset;
attribute vec4	uv;
attribute vec4	metrics;

uniform vec3 		origin;

varying vec2	tex_coord;

void main()
{
	gl_Position.xyz = vec3(
		vertice.x * metrics.z + metrics.x + offset.x,
		vertice.y * metrics.w + metrics.y - offset.y,
		0.0f);
	gl_Position.w = 1.0;
	tex_coord = vec2(
		vertice.x * uv.z + uv.x,
		vertice.y * uv.w + uv.y);
}
