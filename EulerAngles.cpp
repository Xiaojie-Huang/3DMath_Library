#include <math.h>

#include "EulerAngles.h"
#include "MathUtil.h"
#include "Quaternion.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"

//全局单位欧拉角常量
const EulerAngles kEulerAnglesIdentity{0.0f,0.0f,0.0f};

//////////////////////////////////////////////
//canonize()
//将欧拉角转换到限制集中
//就表示3D方位的目的而言，它不会改变欧拉角的值
//但对于角速度等，会产生影响
//////////////////////////////////////////////
void EulerAngles::canonize()
{
    //先将pitch转换到-pi到pi之间
    pitch  = wrapPi(pitch);

    //再变换至-pi/2到pi/2之间
    if(pitch < -kPiOver2)
    {
        pitch = -kPi - pitch;
        heading += kPi;
        bank += kPi;
    }
    else if(pitch > kPiOver2)
    {
        pitch = kPi- pitch;
        heading += kPi;
        bank += kPi;
    }

    //检查万向锁的情况
    if(fabs(pitch) > kPiOver2 - 1e-4)
    {
        //在万向锁中，将所有绕垂直轴的旋转赋给heading
        heading += bank;
        bank = 0.0f;
    }
    else
    {
        //非万向锁，将bank限制
        bank = wrapPi(bank);
    }

    heading = wrapPi(heading);
}