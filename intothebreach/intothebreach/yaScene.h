#pragma once
#include "yaEntity.h"
#include "yaLayer.h"

namespace ya
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();
		
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;

		void AddGameObeject(GameObject* obj, eLayerType layer);

	private:
		std::vector<Layer> mLayers;
	};
}
