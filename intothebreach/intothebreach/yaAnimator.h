#pragma once
#include "yaComponent.h"
#include "yaAnimation.h"

namespace ya {
    class Animator : public Component {
    public:
        struct Event {
            void operator =(function<void()> func) {
                mEvent = move(func);
            }
            void operator()() {
                if (mEvent) 
                    mEvent();
            }
            function<void()> mEvent;
        };
        struct Events {
            Event mStartEvent;
            Event mCompleteEvent;
            Event mEndEvent;
        };
    public:
        Animator(Animator& other);
        Animator();
        ~Animator();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);

        // �� ���Ͽ� �̾����ִ� �ִϸ��̼�
        void CreateAnimation(const wstring& name, Image* image, Vector2 leftTop, Vector2 size, Vector2 offset
            , float columnLegth, UINT spriteLength, float duration, UINT alphaCheck = 0, bool bAffectedCamera = false);
        // ���Ϻ��� �ִ� �ִϸ��̼�
        void CreateAnimations(const wstring& path, const wstring& name, Vector2 offset = Vector2::Zero, float duration = 0.1f);

        Animation* FindAnimation(const wstring& name);
        void Play(const wstring& name, bool loop);

        Events* FindEvents(const wstring name);
        function<void()>& GetStartEvent(const wstring name);
        function<void()>& GetCompleteEvent(const wstring name);
        function<void()>& GetEndEvent(const wstring name);

    private:
        map<wstring, Animation*> mAnimations;
        map<wstring, Events*> mEvents;

        Image* mSpriteSheet;
        Animation* mActiveAnimation;

        bool mbLoop;
    };

    typedef map<wstring, Animation*>::iterator AnimationIter;
    typedef pair<wstring, Animation*> AnimationPair;
}
