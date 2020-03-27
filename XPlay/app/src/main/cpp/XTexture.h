//
// Created by GJP on 2020/3/22.
//

#ifndef XPLAY_XTEXTURE_H
#define XPLAY_XTEXTURE_H

enum XTextureType
{
    XTEXTURE_YUV420p = 0,  //Y4 U 1 V 1
    XTEXTURE_NV12 = 25,    //Y4  UV1
    XTEXTURE_NV21 = 26     //Y4  VU1
};

class XTexture {
public:
    static XTexture *Create();
    virtual bool Init(void *win, XTextureType type = XTEXTURE_YUV420p) = 0;
    virtual void Draw(unsigned char *data[], int width, int height) = 0;
    virtual void Drop() = 0;
    virtual ~XTexture() {};

protected:
    XTexture() {};
};


#endif //XPLAY_XTEXTURE_H
