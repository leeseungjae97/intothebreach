#include "mSkill.h"
#include "mSelectGDI.h"
#include "mTime.h"
#include "mTransform.h"
#include "mAnimator.h"
#include "func.h"
#include "mApplication.h"
#include "mImage.h"
extern m::Application application;
namespace m {
	Skill::Skill(SKILL_T _type)
		: mType(_type)
	{
		AddComponent(new Transform);
		AddComponent(new Animator);

		mTheta = -PI / 4.f;
	}
	Skill::Skill(Skill& _origin) {
	}
	Skill::Skill() 
	{
		AddComponent(new Transform);
		AddComponent(new Animator);

		mTheta = -PI / 4.f;
	}
	Skill::~Skill() {
	}
	void Skill::Initialize() {
		
	}
	void Skill::PreCal() {
		fEndHeight = mFinalEdPos.y - mStPos.y;
		fHeight = 50 - mStPos.y;

		fg = 2 * fHeight / (fMaxTime * fMaxTime);
		fy = sqrtf(1 * fg * fHeight);

		float a = fg;
		float b = - 2 * fy;
		float c = 2 * fEndHeight;

		fEndTime = (-b + sqrtf(b * b - 4 * a * c)) / (2 * a);

		fx = -(mStPos.x - mFinalEdPos.x) / fEndTime;
	}
	void Skill::Update() {
		Vector2 mPos = GetPos();
		
		switch (mType) {
		case SKILL_T::ARC:
		{
			PreCal();
			fTime += Time::fDeltaTime();

			mPos.x = mStPos.x - fx * fTime;
			mPos.y = mStPos.y - (fy * fTime) - (0.5f * fg * fTime * fTime);

			wchar_t szFloat[500] = {};
			swprintf_s(szFloat, 500, L"x : %f, y : %f", fx * fTime, fy * fTime);
			size_t iLen = wcsnlen_s(szFloat, 500);
			RECT rt = { 50, 100, 150, 200 };
			DrawText(application.GetHdc(), szFloat, iLen, &rt, DT_CENTER | DT_WORDBREAK);

		}
		break;
		case SKILL_T::ST:
		{
			mPos.x += 500.f * mEdPos.x * Time::fDeltaTime();
			mPos.y += 500.f * mEdPos.y * Time::fDeltaTime();
		}
		break;
		case SKILL_T::END:
		{

		}
		break;
		default:
			break;
		}
		if (mStPos.x > mFinalEdPos.x) {
			if (mFinalEdPos.y <= mPos.y) {
				object::Destory(this);
			}
		}
		if (mFinalEdPos <= mPos) {
			object::Destory(this);
		}
		SetPos(mPos);
	}
	void Skill::Render(HDC hdc) {
		Vector2 mPos = GetPos();
		Vector2 md = mPos;
		md.Normalize();
		float _theta = atan2(md.y, md.x);

	    Image* im = Resources::Load<Image>(L"missile", L"..\\Resources\\texture\\effect\\shotup_tribomb_missile.bmp");

		//wchar_t szFloat[500] = {};
		//swprintf_s(szFloat, 500, L"degree : %f, cos : %lf, sin : %lf", _theta, cos(_theta), sin(_theta));
		//size_t iLen = wcsnlen_s(szFloat, 500);
		//RECT rt = { 50, 100, 200, 200 };
		//DrawText(hdc, szFloat, iLen, &rt, DT_CENTER | DT_WORDBREAK);



		bitmap::RotateBitmap(hdc, mPos,
			im->GetBitmap(), im->GetWidth()
			, im->GetHeight(), _theta, im->GetHdc());
	}
	void Skill::Release() {
	}
}