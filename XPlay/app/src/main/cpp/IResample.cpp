//
// Created by GJP on 2020/3/23.
//

#include "IResample.h"
#include "XLog.h"

void IResample::Update(XData data)
{
    XData d = this->Resample(data);
    //XLOGE("this->Resample(data) %d", d.size);
    if(d.size > 0) {
        this->Notify(d);
    }
}