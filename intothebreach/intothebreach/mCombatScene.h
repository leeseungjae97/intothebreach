#pragma once
#include "mScene.h"
namespace m {
	class Tile;
	class TileHead;
	class Button;
	class CombatScene : public Scene {
	public:
		CombatScene();
		~CombatScene();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;;
		
		int GetTextTurnNumber() { return iTurn; }
		void RandSpawnAlien(int number);
		void SetTextTurnNumber(int _turn);
		void PutUnitBeforeCombat();
		void PlayerTurnBackground();
		void AlienTurnBackground();
		void AlienIndexReSort();
		void ButtonActivationCondition();
	private:
		vector<Background*> combatBack;
		bool bSetPosition;
		//bool bConfirm;
		Button* textDeploy;
		Button* btnConfirm;
		Button* textTurn;
		Button* textTurnNum;

		Button* gridPowerBox;
		vector<Button*> gridPowers;

		Button* textDefence1;
		Button* textDefence2;
		Button* btnTurnEnd;
		Button* btnUndoMove;
		Button* btnInitTurn;



		Button* textBattleEnd;
		Button* showPlayerInfo;

		int mechIdx;
		int iTurn;
	};
}

