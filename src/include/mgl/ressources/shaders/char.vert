#version 130

in vec3 	origin;
in vec2		vertice;
in vec2		offset;
in vec4		metrics;
in vec4		uv;

out vec2 tex_coord;

void main()
{
	vec3 vpos =
	gl_Position.xy = vec3(
		vertice.x * metrics.z + metrics.x + offset.x,
		vertice.y * metrics.w + metrics.y - offset.y,
		0.0f);
	gl_Position.w = 1.0;
	tex_coord = vec2(
		vertice.x * uv.z + uv.x,
		vertice.y * uv.w + uv.y);
}
