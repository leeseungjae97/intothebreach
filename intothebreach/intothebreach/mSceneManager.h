#pragma once
namespace m
{
	class Scene;
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();
		static void Destroy();
		static void LoadScene(SCENE_TYPE type);

		static Scene* GetActiveScene() { return mActiveScene; }

	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
	};
}
