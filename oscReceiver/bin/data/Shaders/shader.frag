#version 150

uniform sampler2DRect image;
uniform vec2 u_resolution;
uniform float u_time;

in vec2 texCoord;
out vec4 outputColor;

const float PI = 3.1415926;
const int oct = 8;
const float per = 0.5;

float easy_random (vec2 p) {
    return fract(sin(dot(p, vec2(12.9898, 4.1414))) * 43758.5453);
}

float interpolate (float a, float b, float x) {
    float f = (1.0 - cos(x * PI)) * 0.5;
    return a * (1.0 - f) + b * f;
}

float irnd(vec2 p) {
    vec2 i = floor(p);
    vec2 f = fract(p);
    vec4 v = vec4(easy_random(vec2(i.x,     i.y    )),
                  easy_random(vec2(i.x+1.0, i.y    )),
                  easy_random(vec2(i.x,     i.y+1.0)),
                  easy_random(vec2(i.x+1.0, i.y+1.0)));
    return interpolate(interpolate(v.x, v.y, f.x), interpolate(v.z, v.w, f.x), f.y);
}

float noise (vec2 p) {
    float t = 0.0;
    for (int i = 0; i < oct; i++) {
        float freq = pow(2.0, float(i));
        float amp = pow(per, float(oct - i));
        t += irnd(vec2(p.x / freq, p.y / freq)) * amp;
    }
    return t * 10.;
}

void main ()
{
    vec2 p = (gl_FragCoord.xy * 2.0 - 1.0) / u_resolution.xy;
    vec4 col = texture(image,texCoord);
    vec4 col_r = texture(image,texCoord + vec2(-35.0*(noise(p.xy)+easy_random(p.xy+mod(u_time, 2.0))),0));
    vec4 col_l = texture(image,texCoord + vec2( 35.0*(noise(p.xy)+easy_random(p.xy+mod(u_time, 2.0))),0));
    vec4 col_g = texture(image,texCoord + vec2( -7.5*(noise(p.xy)+easy_random(p.xy+mod(u_time, 2.0))),0));
    
    
    col.b = col.b + col_r.b*max(1.0,sin(p.x*1.2)*3.5)*(noise(p.xy)+easy_random(p.xy+mod(u_time, 2.0)));
    col.r = col.r + col_l.r*max(1.0,sin(p.y*1.2)*3.5)*(noise(p.xy)+easy_random(p.xy+mod(u_time, 2.0)));
    col.g = col.g + col_g.g*max(1.0,sin(p.y*1.2)*3.5)*(noise(p.xy)+easy_random(p.xy+mod(u_time, 2.0)));
    
    outputColor = col.rgba;
    //    outputColor = vec4(1.0, 0.0, 0.0, 1.0);
}

