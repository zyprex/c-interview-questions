/*
 * rgb color convert:
 *     ---> hex     00 00 00 ~ ff ff ff
 *     ---> hsl     hue(0~360) saturation(0~1) lightness(0-1)
 *     ---> hsb/hsv hue(0~360) saturation(0~1) value/brightness(0-1)
 *     ---> cmyk    cyan(0-1) magenta(0-1) yellow(0-1) black(0-1)
 */
#include <stdio.h>
#include <string.h>

typedef struct RGBvalue {
    int r;
    int g;
    int b;
}RGB_t;


void rgb2hex(RGB_t rgb)
{
    char hex[7];
    sprintf(hex,"%02x%02x%02x",rgb.r,rgb.g,rgb.b);
    printf("#%s\n",hex);
}

void rgb2hsv(RGB_t rgb)
{
    int r = rgb.r;
    int g = rgb.g;
    int b = rgb.b;
    int max = (r > g) ? (r > b ? r : b) : (g > b ? g : b);
    int min = (r < g) ? (r < b ? r : b) : (g < b ? g : b);
    int pan = max - min;

    int h;
    if (pan == 0){
        h = 0;
    }
    else if(max == r){
        if( g >= b ){
            h = 60*(g-b)/pan;
        }
        else{
            h = 60*(g-b)/pan+360;
        }
    }
    else if(max == g){
        h = 60*(b-r)/pan+120;
    }
    else if(max == b){
        h = 60*(r-g)/pan+240;
    }

    float s = max ? pan*1.0/max : 0;
    float v = max*1.0/255;
    printf("h:%dD s:%g%% v:%g%%\n",h,s*100,v*100);

}

void rgb2hsl(RGB_t rgb)
{
    int r = rgb.r;
    int g = rgb.g;
    int b = rgb.b;
    int max = (r > g) ? (r > b ? r : b) : (g > b ? g : b);
    int min = (r < g) ? (r < b ? r : b) : (g < b ? g : b);
    int pan = max - min;
    int uni = max + min;

    int h;
    if (pan == 0){
        h = 0;
    }
    else if(max == r){
        if( g >= b ){
            h = 60*(g-b)/pan;
        }
        else{
            h = 60*(g-b)/pan+360;
        }
    }
    else if(max == g){
        h = 60*(b-r)/pan+120;
    }
    else if(max == b){
        h = 60*(r-g)/pan+240;
    }

    float s;
    if(pan == 0 || uni == 0){
        s = 0;
    }
    else if(uni <= 128){
        s = pan*1.0/uni;
    }
    else{
        s = pan*1.0/(510-uni);
    }

    float l = uni*1.0/510;
    printf("h:%dD s:%g%% l:%g%%\n",h,s*100,l*100);
}

void rgb2cmyk(RGB_t rgb)
{
    int r = rgb.r;
    int g = rgb.g;
    int b = rgb.b;
    int max = (r > g) ? (r > b ? r : b) : (g > b ? g : b);
    int min = (r < g) ? (r < b ? r : b) : (g < b ? g : b);

    float C = 1-r*1.0/255;
    float M = 1-g*1.0/255;
    float Y = 1-b*1.0/255;
    float k = (C < M) ? (C < Y ? C : Y) : (M < Y ? M : Y);
    if(k == 1.0f){
        puts("c:0 m:0 y:0 k:1");
    }
    else if(k > 0.0f){
        float c = (C-k)/(1-k);
        float m = (M-k)/(1-k);
        float y = (Y-k)/(1-k);
        printf("c:%g m:%g y:%g k:%g\n",c,m,y,k);
    }
}

void rgb2cmy(RGB_t rgb)
{
    int r = rgb.r;
    int g = rgb.g;
    int b = rgb.b;
    float c = (1-r*1.0/255);
    float m = (1-g*1.0/255);
    float y = (1-b*1.0/255);
    printf("c:%g%% m:%g%% y:%g%%\n",c*100,m*100,y*100);

}

int ch2i(char c)
{
    if (c >= 'a' && c <= 'f'){
        c = c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F'){
        c = c - 'A' + 10;
    }
    else if(c >='0' && c <= '9'){
        c = c - '0';
    }
    else{
        return 0;
    }
    return c;
}

void hex2rgb(char* hex)
{
    int r=0, g=0, b=0;
    r = ch2i(hex[0]) * 16 + ch2i(hex[1]);
    g = ch2i(hex[2]) * 16 + ch2i(hex[3]);
    b = ch2i(hex[4]) * 16 + ch2i(hex[5]);
    printf("r:%d g:%d b:%d\n", r, g, b);
}

int main(int argc, const char* argv[])
{
//     RGB_t rgb = {0,2,10};
//     rgb2hex(rgb);
//     rgb2hsv(rgb);
//     rgb2hsl(rgb);
//     rgb2cmyk(rgb);
//     rgb2cmy(rgb);
    hex2rgb("Ff0aaa");

    return 0;
}

