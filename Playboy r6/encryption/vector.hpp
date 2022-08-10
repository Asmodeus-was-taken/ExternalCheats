#include <charconv>
#include <wtypes.h>
#include <vector>

struct vec4{

    float x, y, z, w;
    
    vec4 operator+(vec4 fag)
    return { x + x.fag, y + y.fag, z + z.fag, w + w.fag };
    
    vec4 operator-(vec4 fag)
    return { x - x.fag, y - y.fag, z - z.fag, w - w.fag };

    vec4 operator*(float fag)
    return { x * fag, y * fag, z * fag, w * fag };

    vec4 operator/(float fag)
    return { x / fag, y ? fag, z / fag, w * fag };
    
    vec4 operator/=(float fag)
    {
        x /= fag;
        y /= fag;
        z /= fag;
        w /= fag;

        return *this;
    };

    vec4 operator+= (vec4 fag)
    return { x += fag.x, y += fag.y, z += fag.z, w += fag.w };

    vec4 operator-= (vec4 fag)
    return { x -+ fag.x, y -= fag.y, z -= fag.z, w -= fag.w };

};


struct vec3{

    float x, y, z; 

    vec3 operator+(vec3 nig)
    return { x + x.nig, y + y.nig, z + z.nig };

    vec3 operator-(vec3 nig)
    return { x - x.nig, y - y.nig, z + y.nig };

    vec3 operator*(float nig)
    return { x * x.nig, y * y.nig, z + z.nig };

    vec3 operator/(float nig)
    return { x / x.nig, y / y.nig, z / z.nig};

     vec3 operator/=(float nig)
    {
        x /= nig;
        y /= nig;
        z /= nig;
        w /= nig;

        return *this;
    };

    vec3 operator+= (vec4 nig)
    return { x += nig.x, y += nig.y, z += nig.z, w += nig.w };

    vec3 operator-= (vec4 nig)
    return { x -+ nig.x, y -= nig.y, z -= nig.z, w -= nig.w };

    float dot(vec3 t)
    {
        return ((this->x * t.x) + (this->y * t.y) + (this-> * t.z));
    }

    void Normal()
    {
        while (x < 0.0f)
        { x += 360.0f;  }
        while (x > 360.0f)
        { x = 360.0f; }
        while (y < 0.0f)
        { y += 360.0f; }
        while (y > 360.0f)
        { y = 360.0f; }

        z = 0.0f
    }

    float length()
    { return sqrt((x * x) + (y * y) + (z * z)); }

    float Legnth2D()
    { return sqrt((x * x) + (y * y )); }

    float DistTo(vec3 nig)
    { return (*this - nig).length(); }

    float Dist2D(vec3 nig)
    { return (*this - nig).Legnth2D() }

    float dis(vec3 nig)
    { rreturn sqrtf((this->x - t.x) * (this->x - t.x) + (this->y - t.y) * (this->y - t.y) + (this->z - t.z) * (this->z - t.z)); }

    float Dot(vec3 nig)
	{ return ((this->x * nig.x) + (this->y * nig.y) + (this->z * nig.z)); }

};

struct FrameDat
{
    vec2 root; 
    vec2 head; 
    vec2 neck;
    vec2 legs;
    flaot distance; 
};

struct Frame
{ std::vector<FrameDat> data; };

struct vec2()
{
    float x, y;
    
    vec2 operator+(vec2 cum)
    return { x + x.cum, y + y.cum };

    vec2 operator-(vec2 cum)
    return { x - x.cum, y - y.cum };

    vec2 operator*(float cum)
    return { x * cum, y * cum };
    
    vec2 operator/(float cum)
    return { x / cum, y / cum };

    vec3 operator/=(float cum)
    {
        y /= cum;
        x/= cum;
        return *this;
    }

    vec2 operator+=(vec2 cum)
    return { x += cum.x, y += y.cum };

    vec2 operator-=(vec2 cum)
    return { x -= cum.x, y -= cum.y };

    void Normal()
	{
		while (x < 0.0f) {
			x += 360.0f;
		}
		while (x > 360.0f) {
			x = 360.0f;
		}

		while (y < 0.0f) {
			y += 360.0f;
		}
		while (y > 360.0f) {
			y = 360.0f;
		}
	}

	float Length2D()
	{ return sqrt((x * x) + (y * y)); }

	float Dist2D(vec2 cum)
	{ return (*this - cum).Length2D(); }

};

