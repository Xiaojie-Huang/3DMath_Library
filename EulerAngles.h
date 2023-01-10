//////////////////////////////////////////////
// 3D Math for game development
//////////////////////////////////////////////
#ifndef __EULERANGLES_H_INCLUDED__
#define __EULERANGLES_H_INCLUDED__

//预声明
class Quaternion;
class Matrix4x3;
class RotationMatrix;

//该类用于表示heading-pitch-bank欧拉角系统（绕z-y-x轴旋转）
class EulerAngles
{
public:
    //公共数据，弧度表示
    float heading;
    float pitch;
    float bank;

    EulerAngles() {}

    EulerAngles(float h, float p,float b) : heading(h),pitch(p),bank(b) {}

    //置0
    void identity()
    {
        pitch = bank = heading = 0.0f;
    }

    //变换为“限制”欧拉角
    void canonize();

    //从四元数转换到欧拉角
    void fromObjectToInertialQuaternion(const Quaternion& q);
    void fromInertialToObjectQuaternion(const Quaternion& q);

    //从矩阵转换到欧拉角
    void fromObjectToWorldMatrix(const Matrix4x3& m);
    void fromWorldToObjectMatrix(const Matrix4x3& m);

    //从旋转矩阵到欧拉角
    void fromRotationMatrix(const RotationMatrix& m);

};

    //全局的单位欧拉角
    extern const EulerAngles kEulerAnglesIdentity;

#endif