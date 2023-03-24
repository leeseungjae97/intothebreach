#pragma once
#include "mUnit.h"
namespace m {
    class Image;
    class Animator;
    class Pilot;
    class Weapon;
    class Alien :
        public Unit {
    public:

        Alien(ALIENS mType, Vector2 _coord, int _range, int _hp, SKILL_T _type, int idx);
        Alien(Alien& _origin);
        ~Alien();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;
        virtual void Release() override;

        virtual void idle() override;
        virtual void broken() override;
        virtual void water() override;
        virtual void emerge() override;

    private:
        ALIENS mAlienType;
        int mIdx;
    };
}

