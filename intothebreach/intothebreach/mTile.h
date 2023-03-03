#pragma once
#include "mGameObject.h"
#include "mResources.h"
namespace m {
    class Image;
    class Tile :
        public GameObject {
    public:
        Tile(Vector2 _coord);
        Tile();
        Tile(int m);
        ~Tile();
   

    public:
        void SetTileTexture(const wstring& key, const wstring& path) {
            mTileTex = Resources::Load<Image>(key, path);
            SetScale(Vector2((float)(mTileTex->GetWidth() * 2), (float)(mTileTex->GetHeight() * 2)));
        }
        void SetTileType(TILE_T _type) {
            mTileType = _type;
        }
        Vector2 GetCoord() { return mCoord; }
        Vector2 GetCenterPos() 
        { 
            return Vector2(GetPos().x + mTileTex->GetWidth() / 2, GetPos().y + mTileTex->GetHeight() / 2);
        }
    private:
        virtual void Update() override;
        virtual void Render(HDC hdc) override;

    private:
        Image*      mTileTex;
        TILE_T      mTileType;
        Vector2     mCoord;
    };
}

