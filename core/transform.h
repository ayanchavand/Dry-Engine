#pragma once

#include "../math/vec2.h"

typedef struct
{
    Dry_Vec2 position;
    Dry_Vec2 scale;
    float rotation;
} Dry_Transform;

/* Constructors */
Dry_Transform Dry_Transform_Create(Dry_Vec2 position,
                                   Dry_Vec2 scale,
                                   float rotation);

Dry_Transform Dry_Transform_Default(void);

/* Operations */
void Dry_Transform_Translate(Dry_Transform* transform, Dry_Vec2 delta);
void Dry_Transform_Rotate(Dry_Transform* transform, float angle);
void Dry_Transform_SetScale(Dry_Transform* transform, Dry_Vec2 scale);
void Dry_Transform_Scale(Dry_Transform* transform, Dry_Vec2 amount);
