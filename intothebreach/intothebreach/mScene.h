#pragma once
#include "mEntity.h"
namespace m
{
	class Unit;
	class Alien;
	class Mech;
	class Layer;
	class Tile;
	class Building;
	class Scene : public Entity
	{
	public:
		typedef vector<vector<Tile*>> TILES;
		typedef vector<vector<Building*>> BUILDINGS;
		typedef int(*INT_ARR)[TILE_Y];
		struct Vector2_1 {
			Vector2 coord;
			int level;
			int parentIdx;
		};
		Scene();
		virtual ~Scene();
		
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();
		virtual void Destroy();

		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;

	public:
		void MoveMech();
		void AddGameObject(GameObject* obj, LAYER_TYPE layer);
		void MakeTile(int iX, int iY, TILE_T _type, TILE_HEAD_T _type2);
		void MakeVariTile(int iX, int iY);
		void HighlightTile();
		void DrawSkillRangeTile();
		void ClearMTiles(TILE_T _type, TILE_HEAD_T _hT);
		void ClearMap();
		void DrawFootTile();

		Vector2 GetCoordCenterPos(Vector2 _coord);

		TILES GetPosTiles() { return mPosTiles; }
		TILES GetTiles() { return mTiles; }
		vector<Mech*>& GetMechs() { return mMechs; }
		vector<Alien*>& GetAliens() { return mAliens; }


		void DrawMoveRangeTile();
		void DrawMoveDirectionTile();
		void DrawOutLineTile();
		void CheckMouseOutOfMapRange();
		void RobotDrag();
		void ActiveSkill();
		void ClearSkillRangeMap();
		void MoveEffectUnit(Unit* unit);
		void CheckSkillDirection(Vector2 curSkillPos);

		Mech* GetMouseFollower() { return mMouseFollower; }
		Mech* GetAlphaFollower() { return mAlphaFollower; }

		void SetMouseFollower(Mech* _mM);
		void SetAlphaFollower(Mech* _mM);
		void SetAlphaState(GameObject::STATE state);

	private:
		void SetMap(int y, int x);
		
 	private:
		vector<Layer> mLayers;
		TILES mTiles;
		TILES mPosTiles;
		TILES mPosOutLineTiles;
		TILES mBoundaryTiles;
		TILES mArrowTiles;
		TILES mEffectedTiles;
		TILES mEnemyEmerge;

		vector<Unit*> effectUnits[TILE_Y][TILE_X];


		BUILDINGS mStruturesTiles;

		vector<Vector2_1> pathQueue;
		Vector2 endSkillPosQueue[4];
		vector<Vector2> ll;
		vector<Mech*> mMechs;
		vector<Alien*> mAliens;

		Mech* mMouseFollower;
		Mech* mAlphaFollower;

		int isAttack;			// 스킬 선택 후 조준 중 일때. -1 = idle, 1 = 조준
		int index;				// 선택 스킬
		bool firing;			// 스킬이 이동 중일 때.
		int map[TILE_Y][TILE_X]{};
		int skill_range_map[TILE_Y][TILE_X]{};
	};
}
