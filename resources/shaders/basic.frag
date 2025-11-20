#version 330 core
out vec4 FragColor;

in vec3 FragPos; 
in vec2 TexCoord;
in vec3 Normal;

uniform float time;
uniform vec3 viewPos;
uniform sampler2D Texture;

vec3 lightPos = vec3(-100, 100, 100);
vec3 lightColor = vec3(1,1,1);

float ambientStrength = 0.2;
float specularStrength = 0.5;

void main()
{
    // Ambient lighting
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse lighting
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 norm = normalize(Normal); // Get normalize value of the normal
    float diff = max(dot(norm, lightDir), 0.0); 
    vec3 diffuse = diff * lightColor;
    
    // Specular lighting
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;  

    // Final lighting
    vec3 lighting = diffuse + ambient + specular;

    // Final color
    FragColor = texture(Texture, TexCoord) * vec4(lighting, 1);
} 