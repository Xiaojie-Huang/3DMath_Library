#include<cmath>

class Vector3
{
public:
    //默认构造函数
    Vector3(){}

    //复制构造函数
    Vector3(const Vector3& a) : x(a.x),y(a.y),z(a.z) {}

    Vector3(float nx,float ny,float nz) : x(nx),y(ny),z(nz) {}

    Vector3 &operator=(const Vector3& a)
    {
        x = a.x;
        y = a.y;
        z = a.z;
        return *this;
    }

    bool operator==(const Vector3& a) const
    {
        return x==a.x&&y==a.y&&z==a.z;
    }

    bool operator!=(const Vector3& a) const
    {
        return x != a.x || y != a.y || z != a.z;
    }

    //向量运算

    //置为零向量
    void zero()
    {
        x = y = z = 0.0f;
    }

    Vector3 operator-() const
    {
        return Vector3(-x,-y,-z);
    }

    Vector3 operator-(const Vector3& a) const
    {
        return Vector3(x+a.x,y+a.y,z+a.z);
    }

    Vector3 operator+(const Vector3& a) const
    {
        return Vector3(x+a.x,y+a.y,z+a.z);
    }

    //标量乘除法
    Vector3 operator *(float a) const
    {
        return Vector3(a*x,a*y,a*z);
    }

    Vector3 operator/(float a) const
    {
        //不对/0做检查
        float oneOverA = 1.0f/a;
        return Vector3(x*oneOverA,y*oneOverA,z*oneOverA);
    }

    Vector3& operator+=(const Vector3 a) 
    {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }

    Vector3& operator-=(const Vector3 a) 
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }

    Vector3& operator*=(float a) 
    {
        x *= a;
        y *= a;
        z *= a;
        return *this;
    }

    Vector3& operator/=(float a) 
    {
        float oneOvera = 1.0f/a;
        x *= oneOvera;
        y *= oneOvera;
        z *= oneOvera;
        return *this;
    }

    void normalize()
    {
        float length = x*x + y*y + z*z;
        if(length > 0)
        {
            float oneOverLength = 1.0f/sqrt(length);
            x *= oneOverLength;
            y *= oneOverLength;
            z *= oneOverLength;
        }
    }

    //向量点乘
    float operator*(const Vector3 a) const
    {
        return x*a.x+y*a.y+z*a.z;
    }
public:
    float x,y,z;
};

///////////////////////////////////
//非成员函数
///////////////////////////////////

inline float VectorLength(const Vector3& a) 
{
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

//计算差乘
inline Vector3 CrossProduct(const Vector3& a,const Vector3& b)
{
    return Vector3(
        a.y*b.z-a.z*b.y,
        a.z*b.x-a.x*b.z,
        a.x*b.y-a.y*b.x
    );
}

//标量左乘
inline Vector3 operator * (float k,const Vector3& a)
{
    return Vector3(k*a.x,k*a.y,k*a.z);
}

inline float Distance(const Vector3& a,const Vector3& b)
{
    float dx = a.x-b.x;
    float dy = a.y-b.y;
    float dz = a.z-b.z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}



///////////////////////////////////
//全局变量
///////////////////////////////////
extern const Vector3 ZeroVector;


