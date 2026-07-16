#include "transform.h"

Dry_Transform Dry_Transform_Create(Dry_Vec2 position,
                                   Dry_Vec2 scale,
                                   float rotation)
{
    return (Dry_Transform)
    {
        .position = position,
        .scale = scale,
        .rotation = rotation
    };
}

Dry_Transform Dry_Transform_Default(void)
{
    return (Dry_Transform)
    {
        .position = Dry_Vec2_Zero(),
        .scale = Dry_Vec2_One(),
        .rotation = 0.0f
    };
}

void Dry_Transform_Translate(Dry_Transform* transform, Dry_Vec2 delta)
{
    transform->position = Dry_Vec2_Add(transform->position, delta);
}

void Dry_Transform_Rotate(Dry_Transform* transform, float angle)
{
    transform->rotation += angle;
}

void Dry_Transform_SetScale(Dry_Transform* transform, Dry_Vec2 scale)
{
    transform->scale = scale;
}

void Dry_Transform_Scale(Dry_Transform* transform, Dry_Vec2 amount)
{
    transform->scale = Dry_Vec2_Add(transform->scale, amount);
}
