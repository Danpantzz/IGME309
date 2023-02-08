#version 330

in vec3 Color;

uniform vec3 SolidColor = vec3(-1,-1,-1);
uniform bool Compliment = false;

out vec4 Fragment;

void main()
{
	
	vec3 thisColor = Color;
	
	if(SolidColor.r != -1.0 && SolidColor.g != -1.0 && SolidColor.b != -1.0) {
		thisColor = SolidColor;
	}
	if (Compliment == true) {
		thisColor = vec3(1.0f, 1.0f, 1.0f) - thisColor;
	}
	Fragment = vec4(thisColor,1);

	return;
}