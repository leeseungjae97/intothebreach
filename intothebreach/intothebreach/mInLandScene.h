#pragma once
#include "mScene.h"
namespace m {
	class Button;
	class Background;
    class InLandScene :
        public Scene {
	public:
		InLandScene(ISLAND_T _type);
		~InLandScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		ISLAND_T mType;
		vector<Background*> mSections;

		Button* upUiBox;
    };
}

