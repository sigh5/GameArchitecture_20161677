#version 330 core

in vec2 UV;
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 LightDirection_cameraspace;

out vec3 color;

uniform sampler2D myTextureSampler2;
uniform mat4 StarMV;
uniform vec3 LightPosition_worldspace2;

void main() {

	vec3 LightColor = vec3(1, 1, 0);
	float LightPower = 50.0f;

	vec3 MaterialDiffuseColor = texture(myTextureSampler2, UV).rgb;

	float distance = length(LightPosition_worldspace2 - Position_worldspace);

	vec3 n = normalize(Normal_cameraspace);
	vec3 l = normalize(LightDirection_cameraspace);
	float cosTheta = clamp(dot(n, l), 0, 1);

	vec3 m = normalize(LightDirection_cameraspace);
	float cosTheta2 = clamp(dot(n, m), 0, 1);

	vec3 E = normalize(EyeDirection_cameraspace);
	vec3 R = reflect(-l, n);
	float cosAlpha = clamp(dot(E, R), 0, 10);

	color = MaterialDiffuseColor * LightColor * LightPower * cosTheta / (distance * distance) +
		MaterialDiffuseColor * (0.1);
}