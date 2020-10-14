#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal_modelspace;

out vec2 UV;
out vec3 Position_worldspace;
out vec3 Normal_cameraspace;
out vec3 EyeDirection_cameraspace;
out vec3 LightDirection_cameraspace;

uniform mat4 StarMVP;
uniform mat4 StarV;
uniform mat4 StarM;
uniform vec3 LightPosition_worldspace2;

void main() {

	gl_Position = StarMVP * vec4(vertexPosition_modelspace, 1);

	Position_worldspace = (StarM * vec4(vertexPosition_modelspace, 1)).xyz;

	vec3 vertexPosition_cameraspace = (StarV * StarM * vec4(vertexPosition_modelspace, 1)).xyz;
	EyeDirection_cameraspace = vec3(0, 0, 0) - vertexPosition_cameraspace;

	vec3 LightPosition_cameraspace = (StarV * vec4(LightPosition_worldspace2, 1)).xyz;
	LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;

	Normal_cameraspace = (StarV * StarM * vec4(vertexNormal_modelspace, 0)).xyz;

	UV = vertexUV;
}