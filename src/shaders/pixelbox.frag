#version 120

varying vec2 tex_coord;
uniform sampler2D image;

// out vec4 color;

void main()
{
	gl_FragColor = texture2D(image, tex_coord);
	// gl_FragColor = vec4(1.0f,0.0f,0.0f,1.0f);
}
