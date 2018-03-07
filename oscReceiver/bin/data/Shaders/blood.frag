//#version 150
#version 120

uniform float u_time;
uniform vec2 u_resolution;

#define EULER 2.7182818284590452353602874
#define IEULER 0.367879

//out vec4 outputColor;

float wave(vec2 uv, vec2 emitter, float speed, float phase, float timeshift){
    float dst = distance(uv, emitter);
    return pow(EULER, sin(dst * phase - (u_time + timeshift) * speed));
}
vec2 wavedrag(vec2 uv, vec2 emitter){
    return normalize(uv - emitter);
}
float getwaves(vec2 position){
    float iter = 0.0;
    float phase = 15.0;
    float speed = 1.5;
    float weight = 3.0;
    float w = 0.0;
    float ws = 0.0;
    float iwaterspeed = 1.0;
    for(int i=0;i<123;i++){
        vec2 p = vec2(sin(iter), cos(iter)) * 300.0;
        float res = wave(position, p, speed, phase, 0.0) * IEULER;
        float res2 = wave(position, p, speed, phase, 0.006) * IEULER;
        position -= wavedrag(position, p) * (res - res2) * weight * 5.0 * iwaterspeed;
        w += res * weight;
        iter += 12.0;
        ws += weight;
        weight = mix(weight, 0.0, 0.12);
        phase *= 1.2;
        speed = pow(speed, 1.014);
    }
    return w / ws;
}

void main( ) {
    vec2 position = (gl_FragCoord.xy * 2.0 - 1.0) / u_resolution.xy;
    float w = getwaves(position);
    gl_FragColor = vec4( 1.0 - w*vec4(.8,.6,.3-w*.25,0.0)*8.8 );
//    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}


