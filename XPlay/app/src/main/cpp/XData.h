//
// Created by GJP on 2020/3/21.
//

#ifndef XPLAY_XDATA_H
#define XPLAY_XDATA_H


struct XData {
    unsigned char *data = 0;
    int size = 0;
    void Drop();
};


#endif //XPLAY_XDATA_H
