#include "Mech.h"
#include "mTime.h"
#include "mSceneManager.h"
#include "mInput.h"
#include "mResources.h"
#include "mImage.h"
#include "mTransform.h"
#include "mTime.h"
#include "mAnimator.h"
#include "mCamera.h"
#include "mCollider.h"
namespace m
{
	Mech::Mech(MECHS _mech)
		: mMechType(_mech)
		, mPilot(nullptr)
		, mWeapon(nullptr)
		, curImage(nullptr)
		, mAnimator(nullptr)
	{
		AddComponent(new Animator());
		AddComponent(new Transform());
		AddComponent(new Collider());


		mImages.resize((UINT)COMBAT_CONDITION_T::END);
		for (UINT i = 0; i < (UINT)COMBAT_CONDITION_T::END; i++) {
			mImages[i] = Resources::Load<Image>(
				MAKE_COMBAT_MECH_KEY(mMechType, (COMBAT_CONDITION_T)i)
				, MAKE_COMBAT_MECH_PATH(mMechType, (COMBAT_CONDITION_T)i));
			if (nullptr == mImages[i]) continue;
			mImages[i]->SetOffset(Vector2(0, 0));
		}
		GetComponent<Collider>()->SetScale(Vector2(100.f, 100.f));

		mAnimator = GetComponent<Animator>();

		mAnimator->CreateAnimation(
			MAKE_COMBAT_MECH_KEY(mMechType, COMBAT_CONDITION_T::IDLE)
			, mImages[(UINT)COMBAT_CONDITION_T::IDLE]
			, Vector2(Vector2::Zero)
			, Vector2(MECH_IDLE_SIZE_X, MECH_IDLE_SIZE_Y)
			, mImages[(UINT)COMBAT_CONDITION_T::IDLE]->GetOffset()
			, 4
			, 0.1f
			, AC_SRC_ALPHA
		);
		mAnimator->Play(MAKE_COMBAT_MECH_KEY(mMechType, COMBAT_CONDITION_T::IDLE), true);
		mState = eMechState::Idle;
	}
	Mech::~Mech()
	{
	}
	void Mech::Initialize() {
	}
	void Mech::Update()
	{

		GameObject::Update();
		if (KEY_PREESED(KEYCODE_TYPE::Q)) {
			mState = eMechState::Broken;
		}
		if (KEY_PREESED(KEYCODE_TYPE::E)) {
			mState = eMechState::Idle;
		}
		switch (mState) {
		case m::Mech::eMechState::Idle:
			idle();
			break;
		case m::Mech::eMechState::Broken:
			broken();
			break;
		case m::Mech::eMechState::Water:
			water();
			break;
		case m::Mech::eMechState::End:

			break;
		default:
			break;
		}
		
	}
	void Mech::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		
		if (nullptr != curImage) {
			Vector2 mPos = GetComponent<Transform>()->GetPos();
			mPos += curImage->GetOffset();
			mPos = Camera::CalculatePos(mPos);
			TransparentBlt(hdc
				, (int)(mPos.x - curImage->GetWidth() / 2.f)
				, (int)(mPos.y - curImage->GetHeight() / 2.f)
				, (int)(curImage->GetWidth())
				, (int)(curImage->GetHeight())
				, curImage->GetHdc()
				, 0
				, 0
				, (int)(curImage->GetWidth())
				, (int)(curImage->GetHeight())
				, RGB(255, 0, 255));
		}
	}
	void Mech::Release()
	{
		GameObject::Release();

	}
	void Mech::SetSkill() {
	}
	void Mech::ChangePilotSlot() {
	}
	Weapon* Mech::ChangeWeaponSlot(int index) {
		return nullptr;
	}
	void Mech::idle() {
		mAnimator->Play(MAKE_COMBAT_MECH_KEY(mMechType, COMBAT_CONDITION_T::IDLE), true);
		curImage = nullptr;
	}
	void Mech::broken() {
		mAnimator->Stop();
		curImage = mImages[(UINT)COMBAT_CONDITION_T::BROKEN];
		//mAnimator;
	}
	void Mech::water() {
		
	}
}
