//
// Created by GJP on 2020/3/22.
//

#ifndef XPLAY_XSHADER_H
#define XPLAY_XSHADER_H

#include <mutex>

enum XShaderType
{
    XSHADER_YUV420P = 0,  //Y4 U 1 V 1
    XSHADER_NV12 = 25,   //Y4  UV1
    XSHADER_NV21 = 26    //Y4  VU1
};

class XShader {
public:
    virtual bool Init(XShaderType type = XSHADER_YUV420P);
    virtual void Close();
    //获取材质并映射到内存
    virtual void GetTexture(unsigned int index, int width, int height, unsigned char *buf, bool isa = false);
    virtual void Draw();

protected:
    unsigned int vsh = 0;
    unsigned int fsh = 0;
    unsigned int program = 0;
    unsigned int texts[100] = {0};
    std::mutex mux;
};


#endif //XPLAY_XSHADER_H
