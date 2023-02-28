#pragma once
#include "def.h"

enum class eSceneType
{
	Intro,
	Title,
	SelectRobot,
	SelectLand,
	InLand,
	Combat,
	Ending,
	Max,
};

enum class eLayerType
{
	BackGround,
	Monster,
	Player,
	Test,
	Effect,
	UI,
	End,
};
enum class ePlayerInfos {
	Skill,
	Weapon,
	Pilot,
};
enum class eComponentType {
	Transform,
	//Collider,
	//SpriteRenderer,
	Animator,
	//Audio,
	End,
};

enum class BRUSH_TYPE {
	HOLLOW,
	BLACK,
	CUSTOM_BLACK,
	GRAY,
	END,
};
enum class PEN_TYPE {
	RED,
	GREEN,
	BLUE,
	END
};

enum class TERRAIN_T {
	grass,
	sand,
	snow,
	acid,
	volcano,
	cave,
	common,
	End
};
enum class GROUND_T {
	ground,
	forest,
	building,
	building_water,
	building_collapse,
	mountain,

};
enum class MECH_T {
	Prime,
	Brute,
	Range,
	Science,
	Cyborg,
	End,
};
enum class MECHS {
	electrice,
	flame,
	guard,
	judo,
	laser,
	leap,
	punch,

	charge,
	jet,
	mirror,
	tank,
	unstable,
	wall,

	artillery,
	dstrike,
	ice,
	ignite,
	rockart,
	rocket,

	grav,
	nano,
	pulse,
	science,
	tele,

	End
};
int MECHS_T_HT[(UINT)MECHS::End]{
	(int)MECH_T::Prime,
	(int)MECH_T::Prime,
	(int)MECH_T::Prime,
	(int)MECH_T::Prime,
	(int)MECH_T::Prime,
	(int)MECH_T::Prime,
	(int)MECH_T::Prime,

	(int)MECH_T::Brute,
	(int)MECH_T::Brute,
	(int)MECH_T::Brute,
	(int)MECH_T::Brute,
	(int)MECH_T::Brute,
	(int)MECH_T::Brute,

	(int)MECH_T::Range,
	(int)MECH_T::Range,
	(int)MECH_T::Range,
	(int)MECH_T::Range,
	(int)MECH_T::Range,
	(int)MECH_T::Range,

	(int)MECH_T::Science,
	(int)MECH_T::Science,
	(int)MECH_T::Science,
	(int)MECH_T::Science,
	(int)MECH_T::Science,
};

static wstring MECHS_RESOURCES_PATH[(UINT)MECHS::End]{
	L"mech_electrice",
	L"mech_flame",
	L"mech_guard",
	L"mech_judo",
	L"mech_laser",
	L"mech_leap",
	L"mech_punch",

	L"mech_charge",
	L"mech_jet",
	L"mech_mirror",
	L"mech_tank",
	L"mech_unstable",
	L"mech_wall",

	L"mech_artillery",
	L"mech_dstrike",
	L"mech_ice",
	L"mech_ignite",
	L"mech_rockart",
	L"mech_rocket",

	L"mech_grav",
	L"mech_nano",
	L"mech_pulse",
	L"mech_science",
	L"mech_tele",

};

enum class PRIME_T {
	electrice,
	flame,
	guard,
	judo,
	laser,
	leap,
	punch,
	End,
};
enum class BRUTE_T {
	charge,
	jet,
	mirror,
	tank,
	unstable,
	wall,
	End,
};
enum class RANGE_T {
	artillery,
	dstrike,
	ice,
	ignite,
	rockart,
	rocket,
	End,
};
enum class SCIENCE_T {
	grav,
	nano,
	pulse,
	science,
	tele,
	End,
};
enum class COMMON_CONDITION_T {
	NONE,
	HOLO,
	NO_S,
	End
};
enum class COMBAT_CONDITION_T {
	IDLE,
	BROKEN,
	WATER,
	WATER_BROKEN,
	End
};
static wstring RESOURCES_PATH[RESOURCES_1]{
	L"alien",
	L"combat",
	L"effect",
	L"player",
	L"skill",
	L"structures",
	L"terrain",
	L"ui",
	L"units",
	L"weapons",
};

static wstring MECH_S_PATH[(UINT)MECH_T::End]{
	L"prime\\",
	L"brute\\",
	L"range\\",
	L"science\\"
};
static wstring PRIME_MECH_NAMES[(UINT)PRIME_T::End]{
	L"mech_electrice",
	L"mech_flame",
	L"mech_guard",
	L"mech_judo",
	L"mech_laser",
	L"mech_leap",
	L"mech_punch"
};
static wstring BRUTE_MECH_NAMES[(UINT)BRUTE_T::End]{
	L"mech_charge",
	L"mech_jet",
	L"mech_mirror",
	L"mech_tank",
	L"mech_unstable",
	L"mech_wall"
};
static wstring RANGE_MECH_NAMES[(UINT)RANGE_T::End]{
	L"mech_artillery",
	L"mech_dstrike",
	L"mech_ice",
	L"mech_ignite",
	L"mech_rockart",
	L"mech_rocket"
};
static wstring SCIENCE_MECH_NAMES[(UINT)SCIENCE_T::End]{
	L"mech_grav",
	L"mech_nano",
	L"mech_pulse",
	L"mech_science",
	L"mech_tele"
};

static wstring WEAPONS_PATH[WEAPONS_]{
	L"EnemyWeapons",
	L"passives",
	L"PlayerWeapons"
};
static wstring MECH_CONDITION[(UINT)COMBAT_CONDITION_T::End]{
	L"_a",
	L"_broken",
	L"_w"
	L"_w_broken"
};
static wstring COMMON_MECH_T[(UINT)COMMON_CONDITION_T::End]{
	L"",
	L"_ns",
	L"_h"
};
static wstring GROUND_PATH[(UINT)TERRAIN_T::End]{
	L"grass\\",
	L"sand\\",
	L"snow\\",
	L"acid\\",
	L"volcano\\",
	L"cave\\",
	L""
};
static wstring& MAKE_COMBAT_MECH_KEY(MECHS _mech, COMBAT_CONDITION_T _cond) {
	wstring* path = new wstring(L"");
	int _type = MECHS_T_HT[(UINT)_mech];

	wstring path_1 = MECH_S_PATH[_type];
	wstring path_2 = MECHS_RESOURCES_PATH[(UINT)_mech];
	wstring path_3 = MECH_CONDITION[(UINT)_cond];
	path->append(path_1);
	path->append(path_2);
	path->append(path_3);

	return (*path);
}
static wstring& MAKE_COMBAT_MECH_PATH(MECHS _mech, COMBAT_CONDITION_T _cond) {
	wstring* path = new wstring(L"..\\Resources\\texture\\player\\"); 
	int _type = MECHS_T_HT[(UINT)_mech];

	wstring path_1 = MECH_S_PATH[_type];
	wstring path_2 = MECHS_RESOURCES_PATH[(UINT)_mech];
	wstring path_3 = MECH_CONDITION[(UINT)_cond];
	path->append(path_1);
	path->append(path_2);
	path->append(path_3);
	path->append(L".bmp");

	return (*path);
}