#pragma once
#include "Creature.h"

class CreatureContainer
{
private:
    Creature** data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void copyFrom(const CreatureContainer& other);
    void moveFrom(CreatureContainer&& other);
    void free();
    
    void resize(size_t newCap);

public:
    CreatureContainer();

    CreatureContainer(const CreatureContainer& other);
    CreatureContainer& operator=(const CreatureContainer& other);

    CreatureContainer(CreatureContainer&& other) noexcept;
    CreatureContainer& operator=(CreatureContainer&& other) noexcept;

    ~CreatureContainer();

    const Creature* getCreature(size_t index) const;
    Creature* getCreature(size_t index);

    void addCreature(const Creature& obj);
    void removeCreature(size_t index);

    size_t fight(size_t index) const;
};


    