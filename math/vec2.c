#include "vec2.h"

#include <math.h>

Dry_Vec2 Dry_Vec2_Create(float x, float y)
{
    return (Dry_Vec2){x, y};
}

Dry_Vec2 Dry_Vec2_Zero(void)
{
    return (Dry_Vec2){0.0f, 0.0f};
}

Dry_Vec2 Dry_Vec2_One(void)
{
    return (Dry_Vec2){1.0f, 1.0f};
}

Dry_Vec2 Dry_Vec2_Add(Dry_Vec2 a, Dry_Vec2 b)
{
    return (Dry_Vec2){a.x + b.x, a.y + b.y};
}

Dry_Vec2 Dry_Vec2_Sub(Dry_Vec2 a, Dry_Vec2 b)
{
    return (Dry_Vec2){a.x - b.x, a.y - b.y};
}

Dry_Vec2 Dry_Vec2_Mul(Dry_Vec2 v, float scalar)
{
    return (Dry_Vec2){v.x * scalar, v.y * scalar};
}

Dry_Vec2 Dry_Vec2_Div(Dry_Vec2 v, float scalar)
{
    return (Dry_Vec2){v.x / scalar, v.y / scalar};
}

float Dry_Vec2_Dot(Dry_Vec2 a, Dry_Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

float Dry_Vec2_LengthSquared(Dry_Vec2 v)
{
    return Dry_Vec2_Dot(v, v);
}

float Dry_Vec2_Length(Dry_Vec2 v)
{
    return sqrtf(Dry_Vec2_LengthSquared(v));
}

Dry_Vec2 Dry_Vec2_Normalize(Dry_Vec2 v)
{
    float length = Dry_Vec2_Length(v);

    if (length == 0.0f)
        return Dry_Vec2_Zero();

    return Dry_Vec2_Div(v, length);
}

float Dry_Vec2_DistanceSquared(Dry_Vec2 a, Dry_Vec2 b)
{
    return Dry_Vec2_LengthSquared(Dry_Vec2_Sub(a, b));
}

float Dry_Vec2_Distance(Dry_Vec2 a, Dry_Vec2 b)
{
    return sqrtf(Dry_Vec2_DistanceSquared(a, b));
}

Dry_Vec2 Dry_Vec2_Lerp(Dry_Vec2 a, Dry_Vec2 b, float t)
{
    return (Dry_Vec2)
    {
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t
    };
}

Dry_Vec2 Dry_Vec2_Negate(Dry_Vec2 v)
{
    return (Dry_Vec2){-v.x, -v.y};
}

bool Dry_Vec2_Equals(Dry_Vec2 a, Dry_Vec2 b)
{
    return a.x == b.x && a.y == b.y;
}
