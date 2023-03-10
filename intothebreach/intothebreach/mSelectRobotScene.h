#pragma once
#include "mScene.h"
#include "Mech.h"
namespace m
{
	class SelectRobotScene : public Scene
	{
	public:
		SelectRobotScene();
		~SelectRobotScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Mech* mMech;
	};
}
