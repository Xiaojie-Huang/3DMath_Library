//////////////////////////////////////////////
// 3D Math for game development
//////////////////////////////////////////////
#ifndef __MATHUTIL_H_INCLUDED__
#define __MATHUTIL_H_INCLUDED__

#include "math.h"

const float kPi = 3.14159265f;
const float k2Pi = kPi * 2.0f;
const float kPiOver2 = kPi / 2.0f;
const float k1OverPi = 1.0f / kPi;
const float k1Over2Pi = 1.0f / k2Pi;

//通过增加适当的2Pi倍数将角度限制在-Pi和Pi之间
extern float wrapPi(float theta);


//安全的反三角函数
extern float safeAcos(float x);

//得到某角度的sin和cos值，在某些平台上，如果需要这两值，同时计算比分开算快
inline void sinCos(float* returnSin,float* returnCos,float theta)
{
    *returnSin = sin(theta);
    *returnCos = cos(theta);
}

#endif