#pragma once
#include "yaScene.h"
namespace ya {
    class InLandScene :
        public Scene {
	public:
		InLandScene();
		~InLandScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
    };
}

