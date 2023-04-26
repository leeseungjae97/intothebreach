#pragma once
#include "mUI.h"
namespace m
{
	class Image;
	class Button :
		public UI
	{
	public:
		Button(const wstring& inner
			, const wstring& background
			, int _sizeUp = 0
			, bool _full = false
			, int _direction = LEFT
			, bool _alphaCheck = false);
		~Button();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		bool GetInner() { return bInner; }
		bool GetClicked() { return bClicked; }
		bool GetHover() { return bHover; }
		bool GetBlink() { return bBlink; }
		bool GetApDAp() { return bApDAp; }
		bool GetEndApDAp() { return endApDAp; }
		bool GetSmoothAppear() { return bSmoothAppear; }
		bool GetSmoothDisappear() { return bSmoothDisappear; }
		wstring GetBtnName() { return btnName; }
		Vector2 GetInnerPos() { return innerPos; }
		Image* GetInnerImage() { return innerImage; }
		BYTE GetInnerConstant() { return innerConstant; }
		BYTE GetConstant() { return btConstant; }
		int GetIdVar() { return idVar; }

		void SetOSize(Vector2 _os) { originSize = _os; }
		void SetResize(Vector2 _r) { resizeMax = _r; }
		void SetResizeUnit(Vector2 _u) { resizeUnit = _u; }
		void SetInner(bool _t) { bInner = _t; }
		void SetClicked(bool _b) { bClicked = _b; }
		void ChangeInner(const wstring& _path) { btnName = _path; }
		void UseInnerAlpha(bool _t) { bInnerAlpha = _t; }
		void SetInnerConstant(BYTE _a) { innerConstant = _a; }
		void SetMoveScene(SCENE_TYPE _type) { eBtnMoveScene = _type; }
		void SetInnerPos(Vector2 _textPos) { innerPos = _textPos; }
		void SetReSizeable(bool _b) { bReSzieable = _b; }
		void SetInnerMag(int mag) { iInnerScale = mag; }
		void SetConstant(BYTE _cons) { btConstant = _cons; }
		void SetIdVar(int _iv) { idVar = _iv; }
		void SetHover(bool _b) { bHover = _b; }
		void SetBlink(bool _b) { bBlink = _b; }
		void SmoothAppear(bool _b) { bSmoothAppear = _b; }
		void SmoothDisappear(bool _b) { bSmoothDisappear = _b; }
		void SetApDAp(bool _b) { bApDAp = _b; }

	private:
		Vector2 innerPos;
		Vector2 resizeMax;
		Vector2 resizeUnit;
		Vector2 originSize;
		wstring btnName;

		SCENE_TYPE eBtnMoveScene;
		Image* innerImage;
		bool bInner;
		bool bInnerAlpha;
		bool bReSzieable;
		bool bClicked;
		bool bHover;
		bool bSmoothAppear;
		bool bSmoothDisappear;
		bool bApDAp;
		bool endApDAp;

		int idDir;
		int idVar;
		bool bBlink;

		BYTE btConstant;
		BYTE innerConstant;
		int iInnerScale;
	};
}