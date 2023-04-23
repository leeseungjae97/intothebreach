#include "Building.h"
#include "mTransform.h"
#include "mResources.h"
#include "mSceneManager.h"
#include "mPlayerInfo.h"
#include "mComponent.h"
#include "mAnimator.h"
#include "mScene.h"
#include "mTile.h"
#include "mImage.h"
namespace m {
	Building::Building(STRUCTURES _type, Vector2 _coord, int idx, TILE_T _mapType)
		: Unit(_coord, 0, 0, WEAPON_T::NONE, idx, 0)
		, mType(_type)
		, mapType(_mapType)
	{
		

		if (mType == STRUCTURES::mountain)
		{
			gridIcon = nullptr;
			Image* imn = Resources::Load<Image>(MAKE_TILE_KEY(mapType, TILE_HEAD_T::mountain)
				, MAKE_TILE_PATH(mapType, TILE_HEAD_T::mountain));
			SetCurImage(imn);
			imn->SetOffset(Vector2(10.f, -35.f));
			SetState(STATE::Idle);

			Image* im = Resources::Load<Image>(MAKE_TILE_KEY(mapType, TILE_HEAD_T::mountain_explode)
				, MAKE_TILE_PATH(mapType, TILE_HEAD_T::mountain_explode));
			im->SetOffset(Vector2(-6.f, -19.f));

			if (nullptr == GetAnimator()->FindAnimation(MAKE_TILE_KEY(mapType, TILE_HEAD_T::mountain_explode)))
			{
				GetAnimator()->CreateAnimation(
					MAKE_TILE_KEY(mapType, TILE_HEAD_T::mountain_explode)
					, im
					, Vector2::Zero
					, Vector2((im->GetWidth() / 13.f), (float)im->GetHeight())
					, im->GetOffset()
					, 13
					, 0.1f
					, (UINT)AC_SRC_OVER
				);
			}
		}
		else
		{
			gridIcon = Resources::Load<Image>(L"gridPowerIcon", L"..\\Resources\\texture\\combat\\icons\\icon_gridpower_glow_y.bmp");
			GetMImages().resize((UINT)STRUCTURES::END);
			for (UINT i = 0; i < (UINT)STRUCTURES_CONDITION_T::END; i++)
			{
				GetMImages()[i] = Resources::Load<Image>(
					MAKE_UNIT_KEY(_type, (STRUCTURES_CONDITION_T)i)
					, MAKE_UNIT_PATH(_type, (STRUCTURES_CONDITION_T)i)
				);

				if (nullptr == GetMImages()[i])continue;
				GetMImages()[i]->SetOffset(STRUCTURES_OFFSET[(UINT)_type]);
			}


			SetCurImage(GetMImages()[(UINT)STRUCTURES_CONDITION_T::On]);
			SetState(GameObject::STATE::Idle);
		}
	
		//Image* im;
		//if (_type == STRUCTURES::Mountain) {
		//	im =Resources::Load<Image>(L"testMoutain", L"..\\Resources\\texture\\terrain\\green\\mountain_0.bmp");
		//}
		//else {
		//	im = Resources::Load<Image>(SQUARE__KEY, SQUARE__PATH);
		//}
		//im->SetOffset(Vector2(47.f, -18.f));
		//SetScale(Vector2((float)(im->GetWidth() * 2), (float)(im->GetHeight() * 2)));
		//SetCurImage(im);
	}
	Building::~Building() {

	}
	void Building::Update() {
		Unit::Update();
		switch (GetState())
		{
		case m::GameObject::STATE::Idle:
		{
			idle();
		}
			break;
		case m::GameObject::STATE::Broken:
		{
			broken();
		}
			break;
		case m::GameObject::STATE::Explo:
		{
			explo();
		}
			break;
		case m::GameObject::STATE::Water:
		{
			water();
		}
			break;
		default:
			break;
		}
	}
	void Building::Render(HDC hdc) {
		Unit::Render(hdc);
		//Vector2 mPos = GetPos();

		//mPos.x += GetCurImage()->GetWidth() / 2;
		if (gridIcon)
		{
			Vector2 mCenterPos = SceneManager::GetActiveScene()->GetPosTile((int)GetCoord().y, (int)GetCoord().x)->GetCenterPos();
			mCenterPos.y -= GetCurImage()->GetHeight();
			//mCenterPos.x += gridIcon->GetWidth();
			TransparentBlt(hdc
				, (int)(mCenterPos.x + gridIcon->GetWidth() / 2.f)
				, (int)(mCenterPos.y - gridIcon->GetHeight() / 2.f)
				, (int)(gridIcon->GetWidth() * 2)
				, (int)(gridIcon->GetHeight() * 2)
				, gridIcon->GetHdc()
				, 0
				, 0
				, (int)(gridIcon->GetWidth())
				, (int)(gridIcon->GetHeight())
				, RGB(255, 0, 255));
		}
	}
	void Building::Hit(int damage)
	{
		if (GetState() == STATE::Broken)
		{
			if (mType == STRUCTURES::mountain)
			{
				SetState(STATE::Explo);
			}
		}
		else
		{
			if (mType != STRUCTURES::mountain)
			{
				PlayerInfo::gridPower -= 1;
				gridIcon = nullptr;
			}
			SetState(STATE::Broken);
		}
		
	}
	void Building::idle()
	{
		if (mType != STRUCTURES::mountain)
		{
			SetCurImage(GetMImages()[(UINT)STRUCTURES_CONDITION_T::On]);
			if (nullptr == gridIcon)
				gridIcon = Resources::Load<Image>(L"gridPowerIcon", L"..\\Resources\\texture\\combat\\icons\\icon_gridpower_glow_y.bmp");
		}
		else
		{
			Image* imn = Resources::Load<Image>(MAKE_TILE_KEY(mapType, TILE_HEAD_T::mountain)
				, MAKE_TILE_PATH(mapType, TILE_HEAD_T::mountain));
			imn->SetOffset(Vector2(10.f, -35.f));
			SetCurImage(imn);
		}
	}
	void Building::broken()
	{
		if (mType == STRUCTURES::mountain)
		{
			Image* im = Resources::Load<Image>(MAKE_TILE_KEY(mapType, TILE_HEAD_T::mountain_broken)
				, MAKE_TILE_PATH(mapType, TILE_HEAD_T::mountain_broken));
			SetCurImage(im);
			im->SetOffset(Vector2(10.f, -35.f));
		}
		else
		{
			SetCurImage(GetMImages()[(UINT)STRUCTURES_CONDITION_T::Broken]);
		}
		
	}
	void Building::water()
	{
		//SetCurImage(GetMImages()[(UINT)STRUCTURES_CONDITION_T::Off]);
	}
	void Building::explo()
	{
		GetAnimator()->Stop();
		GetAnimator()->Play(MAKE_TILE_KEY(mapType, TILE_HEAD_T::mountain_explode), false);
		SetCurImage(nullptr);
	}

}