#include "mBackground.h"
#include "mResources.h"
#include "mSelectGDI.h"
#include "mApplication.h"
#include "mCamera.h"
#include "func.h"
#include "mTime.h"
extern m::Application application;
namespace m {
	Background::Background(const wstring& key
		, const wstring& path
		, int _sizeUp
		, bool _full
		, int _direction
		, bool _alphaCheck

	)
		: UI(key
			, path
			, _sizeUp
			, _full
			, _direction
			, _alphaCheck)
	{
		iConstant = -1;
		idVar = 1;
		idDir = 1;
		vMovement = Vector2::Zero;
		bSmoothDisappear = false;
		bSmoothAppear = false;
	}
	Background::~Background() {
	}
	void Background::Initialize() {

		
	}
	void Background::Update() {
		GameObject::Update();
		
		if (vMovement != Vector2::Zero)
		{
			if (GetAlphaConstant() < 10) object::Destory(this);
			vMovement.Normalize();
			Vector2 nPos;
			nPos.x = GetPos().x + vMovement.x * 50.f * Time::fDeltaTime();
			nPos.y = GetPos().y + vMovement.y * 50.f * Time::fDeltaTime();
			SetAlphaConstant(GetAlphaConstant() - 10);
			SetPos(nPos);
		}
	}

	void Background::Render(HDC hdc) {
		//GameObject::Render(hdc);
		Transform* tr = GetComponent<Transform>();
		Vector2 mPos = tr->GetPos();

		UINT iWidth;
		UINT iHeight;
		if (mImage == nullptr)
		{
			SelectGDI tmp(hdc, BRUSH_TYPE::CUSTOM_BLACK);
			Rectangle(hdc, 0, 0, application.GetResolutionWidth()
				, application.GetResolutionHeight());
		}
		else
		{
			if (mIsFull)
			{
				iWidth = application.GetResolutionWidth();
				iHeight = application.GetResolutionHeight();
			}
			else
			{
				iWidth = mImage->GetWidth();
				iHeight = mImage->GetHeight();
			}

			if (mSizeUp != 0)
			{
				iWidth *= mSizeUp;
				iHeight *= mSizeUp;
			}

			if (mDir & CENTER)
			{
				if (!cutPos)
				{
					mPos.x = (float)application.GetResolutionWidth() / 2;
					mPos.y = (float)application.GetResolutionHeight() / 2;
					mPos.x -= iWidth / 2;
					mPos.y -= iHeight / 2;
				}
				
			}
			if (mDir & BOTTOM)
			{
				if (!cutPos)
					mPos.y = (float)application.GetResolutionHeight();

				mPos.y -= iHeight;
			}
			if (mDir & RIGHT)
			{
				if (!cutPos)
					mPos.x = (float)application.GetResolutionWidth();

				mPos.x -= iWidth;
				mPos.x += (float)application.GetResolutionWidth() / 2;
			}
			if (mDir & TOP)
			{
				if (!cutPos)
					mPos.y = (float)0;

				mPos.y += 30;
			}
			if (mDir & LEFT)
			{
				if (!cutPos)
					mPos.x = (float)0;

				mPos.x += 50;
			}
			mPos += mImage->GetOffset();
			SetScale(Vector2((float)iWidth, (float)iHeight));
			if (effectCamera)
				mPos = Camera::CalculatePos(mPos);

			if (mAlpha)
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = mAlpha;

				if (bBlink)
				{
					iConstant += idVar * idDir;
					if (iConstant >= 255 || iConstant <= 0) idDir *= -1;
				}
				
				if(iConstant != -1 ) func.SourceConstantAlpha = iConstant;
				else func.SourceConstantAlpha = 125;

				if (bSmoothDisappear)
				{
					idDir = -1;
					if (iConstant <= 0)
					{
						bSmoothDisappear = false;
					}
					else iConstant += idVar * idDir;
				}
				if (bSmoothAppear)
				{
					idDir = 1;
					if (iConstant >= 255 - idVar)
					{
						bSmoothAppear = false;
					}
					else
					{
						iConstant += idVar * idDir;
					}	
				}

				AlphaBlend(hdc
					, (int)(mPos.x)
					, (int)(mPos.y)
					, (int)(iWidth)
					, (int)(iHeight)
					, mImage->GetHdc()
					, 0
					, 0
					, (int)(mImage->GetWidth())
					, (int)(mImage->GetHeight())
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, (int)(mPos.x)
					, (int)(mPos.y)
					, (int)(iWidth)
					, (int)(iHeight)
					, mImage->GetHdc()
					, 0
					, 0
					, (int)(mImage->GetWidth())
					, (int)(mImage->GetHeight())
					, RGB(255, 0, 255));
			}
		}
	}
	void Background::Release() {
		GameObject::Release();
	}
}