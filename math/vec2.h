#pragma once

#include <stdbool.h>

typedef struct
{
    float x;
    float y;
} Dry_Vec2;

/* Constructors */
Dry_Vec2 Dry_Vec2_Create(float x, float y);
Dry_Vec2 Dry_Vec2_Zero(void);
Dry_Vec2 Dry_Vec2_One(void);

/* Arithmetic */
Dry_Vec2 Dry_Vec2_Add(Dry_Vec2 a, Dry_Vec2 b);
Dry_Vec2 Dry_Vec2_Sub(Dry_Vec2 a, Dry_Vec2 b);
Dry_Vec2 Dry_Vec2_Mul(Dry_Vec2 v, float scalar);
Dry_Vec2 Dry_Vec2_Div(Dry_Vec2 v, float scalar);

/* Vector Operations */
float     Dry_Vec2_Dot(Dry_Vec2 a, Dry_Vec2 b);
float     Dry_Vec2_Length(Dry_Vec2 v);
float     Dry_Vec2_LengthSquared(Dry_Vec2 v);
Dry_Vec2  Dry_Vec2_Normalize(Dry_Vec2 v);
float     Dry_Vec2_Distance(Dry_Vec2 a, Dry_Vec2 b);
float     Dry_Vec2_DistanceSquared(Dry_Vec2 a, Dry_Vec2 b);

/* Utility */
Dry_Vec2 Dry_Vec2_Lerp(Dry_Vec2 a, Dry_Vec2 b, float t);
Dry_Vec2 Dry_Vec2_Negate(Dry_Vec2 v);
bool     Dry_Vec2_Equals(Dry_Vec2 a, Dry_Vec2 b);
