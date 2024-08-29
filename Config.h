#ifndef CONFIG_H
#define CONFIG_H
#define GOD_MODE 0
#define NUM_MONSTER 4
const float WEAPON_DMG[3] = {10, 20, 12};
const float BUFF_ENTITY= 10;
const int BOSS_HP = 1000;
const float BOSS_COOLDOWN = 800;
const float PLAYER_SPEED = 0.4;
const float BOSS_SPEED = 0.1;
const int LVL_X_LIMIT = 2000;
const int LVL_Y_LIMIT = 2000;
const int MENU_X_LIMIT = 1000;
const int MENU_Y_LIMIT = 1000;
const int NUM_ROCKSPRING2 = 4;
const int NUM_ROCKSUMMER2 = 4;
const int NUM_ROCKAUTUMN2 = 4;
const int NUM_ROCKWINTER2 = 4;
const int NUM_FLOWERSPRING2 = 3;
const int NUM_FLOWERSUMMER2 = 3;
const int NUM_FLOWERAUTUMN2 = 3;
const int NUM_FLOWERWINTER2 = 3;
const int NUM_TREESPRING = 3;
const int NUM_TREESUMMER = 3;
const int NUM_TREEAUTUMN = 3;
const int NUM_TREEWINTER = 3;
const int SPAWN_SPEED = 500;
const int MAX_LIFES = 3;
const float SEASON_SPEED = 0.2;
const float SEASON_COOLDOWN = 200;
const float SEASON_HP = 20;
const float POWER_MULTIPLY = 1.2;
const float MAX_MONS = 6;
const float MISS_RATE = 0.1;
const float MISS_CHANGE = 0.05;
const float CRIT_RATE = 0.1;
const float CRIT_CHANGE = 0.05;
const float COOLDOWN_CHANGE = 0.035;
const float ROCK_W = 32;
const float ROCK_H = 32;
const float FLOWER_W = 16;
const float FLOWER_H = 32;
const float TREE_W = 80;
const float TREE_H = 112;
const float INIT_COOLDOWN = 500;
const float INIT_HP = 100;
const float PLAYER_W = 64;
const float PLAYER_H = 64;
const float WEAPON_SIZE = 64;
const float BULLET_SIZE = 16;
const float MONS_SIZE[7][2] = { {64,72},{150,150},{150,150},{150,150},{64,64} ,{64,64} ,{64,64} };
const char ITEM_HARD_NAME[3][4][15] = {{"dirtMorning", "treeMorning", "item1Morning", "item2Morning"}, {"dirtAfternoon", "treeAfternoon", "item1Afternoon", "item2Afternoon"}, {"dirtNight", "treeNight", "item1Night", "item2Night"}};
const char MONS_NAME[7][2][15] = { {"BigMonster1", "BigMonster2"},{"FlyingEye1", "FlyingEye2"}, {"Goblin1", "Goblin2"}, {"Skeleton1", "Skeleton2"},{"heal", "heal"}, {"dmg", "dmg"}, {"speed", "speed"}};
const string AVATAR[8] = {"witch", "white", "blue", "pink","witchCook","whiteCook","blueCook","pinkCook"};
#endif // !
