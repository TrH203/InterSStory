#include "Game.h"
#include "Config.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init()
{
	skin = 0; skinBoss = 0;
	window.create(VideoMode(1000, 1000), "ZOMBIEEE!! AAGAHRG!!1!!!!!1!", Style::Fullscreen);
	view.setSize(window.getSize().x, window.getSize().y);
	window.setView(view);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
	//window.setFramerateLimit(20);
	srand(time(NULL));
	cursor.init(&window, &view, &player);
	cursor.setLimit(Vector2f(LVL_X_LIMIT, LVL_Y_LIMIT));
	missRate = MISS_RATE;
	critRate = CRIT_RATE; //FIX
	max_mons = MAX_MONS;
	godMode = GOD_MODE;
	resetPos = false;
	defaultTime = -1;
	setScreen(-1);

	// Skin1 -------------------------------------
	texManager.add("witch1", "image/Witch.png"); // Need to be writen on a txt file
	texManager.add("witch2", "image/Witch.png");
	// Player
	texManager.add("witchBOSS1", "image/Witch_BOSS.png"); // Need to be writen on a txt file
	texManager.add("witchBOSS2", "image/Witch_BOSS.png");

	// Player
	texManager.add("witchCook1", "image/Witch_Cook.png"); // Need to be writen on a txt file
	texManager.add("witchCook2", "image/Witch_Cook.png");
	// Player
	texManager.add("witchCookBOSS1", "image/Witch_BOSSCook.png"); // Need to be writen on a txt file
	texManager.add("witchCookBOSS2", "image/Witch_BOSSCook.png");

	// Skin2 ------------------------------------- WHITE
	texManager.add("white1", "image/White1.png"); // Need to be writen on a txt file
	texManager.add("white2", "image/White2.png");
	// Player
	texManager.add("whiteBOSS1", "image/White1_BOSS.png"); // Need to be writen on a txt file
	texManager.add("whiteBOSS2", "image/White2_BOSS.png");

	// Player
	texManager.add("whiteCook1", "image/White1_Cook.png"); // Need to be writen on a txt file
	texManager.add("whiteCook2", "image/White2_Cook.png");
	// Player
	texManager.add("whiteCookBOSS1", "image/White1_BOSSCook.png"); // Need to be writen on a txt file
	texManager.add("whiteCookBOSS2", "image/White2_BOSSCook.png");

	// Skin3 -------------------------------------
	texManager.add("pink1", "image/Pink1.png"); // Need to be writen on a txt file
	texManager.add("pink2", "image/Pink2.png");
	// Player
	texManager.add("pinkBOSS1", "image/Pink1_BOSS.png"); // Need to be writen on a txt file
	texManager.add("pinkBOSS2", "image/Pink2_BOSS.png");

	// Player
	texManager.add("pinkCook1", "image/Pink1_Cook.png"); // Need to be writen on a txt file
	texManager.add("pinkCook2", "image/Pink2_Cook.png");
	// Player
	texManager.add("pinkCookBOSS1", "image/Pink1_BOSSCook.png"); // Need to be writen on a txt file
	texManager.add("pinkCookBOSS2", "image/Pink2_BOSSCook.png");

	// Skin4 -------------------------------------
	texManager.add("blue1", "image/Blue1.png"); // Need to be writen on a txt file
	texManager.add("blue2", "image/Blue2.png");

	// Player
	texManager.add("blueBOSS1", "image/Blue1_BOSS.png"); // Need to be writen on a txt file
	texManager.add("blueBOSS2", "image/Blue2_BOSS.png");

	// Player
	texManager.add("blueCook1", "image/Blue1_Cook.png"); // Need to be writen on a txt file
	texManager.add("blueCook2", "image/Blue2_Cook.png");
	// Player
	texManager.add("blueCookBOSS1", "image/Blue1_BOSSCook.png"); // Need to be writen on a txt file
	texManager.add("blueCookBOSS2", "image/Blue2_BOSSCook.png");

	// Paterns
	texManager.add("wood", "image/wood.png");
	texManager.add("grass", "image/grass.png");
	texManager.add("bullet", "image/bullet1.png");
	texManager.add("boss_bullet", "image/boss_bullet.png");
	texManager.add("weed", "image/weed.png");
	//texManager.add("tree", "image/tree.png");
	texManager.add("shortGun", "image/gun.png");
	texManager.add("AWM", "image/gun1.png");
	texManager.add("bazoka", "image/bazoka.png");
	texManager.add("fireRed", "image/fireRed2.png");
	texManager.add("fireGreen", "image/fireGreen2.png");
	texManager.add("fireBlack", "image/fireBlack2.png");
	texManager.add("master", "image/master.png");
	texManager.add("masterIcon", "image/masterIcon.png");
	texManager.add("kissIcon", "image/kissIcon.png");
	texManager.add("heart", "image/heart.png");

	texManager.add("heal", "image/heal.png");
	texManager.add("dmg", "image/dmg.png");
	texManager.add("speed", "image/speed.png");

	texManager.add("mode", "image/mode.png");
	texManager.add("target", "image/target.png");
	texManager.add("doormat", "image/doormat.png");
	texManager.add("frame", "image/frame.png");

	// Map
	texManager.add("dirtSpring","image/dirtSpring.png");
	texManager.add("dirtSummer","image/dirtSummer.png");
	texManager.add("dirtAutumn","image/dirtAutumn.png");
	texManager.add("dirtWinter","image/dirtWinter.png");
	/*texManager.add("rockSpring1","image/rockSpring1.png");
	texManager.add("rockSummer1","image/rockSummer1.png");
	texManager.add("rockAutumn1","image/rockAutumn1.png");
	texManager.add("rockWinter1","image/rockWinter1.png");*/
	texManager.add("rockSpring2","image/rockSpring2.png");
	texManager.add("rockSummer2","image/rockSummer2.png");
	texManager.add("rockAutumn2","image/rockAutumn2.png");
	texManager.add("rockWinter2","image/rockWinter2.png");
	/*texManager.add("flowerSpring1","image/flowerSpring1.png");
	texManager.add("flowerSummer1","image/flowerSummer1.png");
	texManager.add("flowerAutumn1","image/flowerAutumn1.png");
	texManager.add("flowerWinter1","image/flowerWinter1.png");*/
	texManager.add("flowerSpring2","image/flowerSpring2.png");
	texManager.add("flowerSummer2","image/flowerSummer2.png");
	texManager.add("flowerAutumn2","image/flowerAutumn2.png");
	texManager.add("flowerWinter2","image/flowerWinter2.png");
	texManager.add("treeSpring","image/treeSpring.png");
	texManager.add("treeSummer","image/treeSummer.png");
	texManager.add("treeAutumn","image/treeAutumn.png");
	texManager.add("treeWinter","image/treeWinter.png");
	texManager.add("treeMorning","image/tree1.png");
	texManager.add("treeAfternoon","image/tree2.png");
	texManager.add("treeNight","image/tree3.png");
	texManager.add("item1Morning", "image/itemMorning1.png");
	texManager.add("item2Morning", "image/itemMorning2.png");
	texManager.add("item1Afternoon", "image/itemAfternoon1.png");
	texManager.add("item2Afternoon", "image/itemAfternoon2.png");
	texManager.add("item1Night", "image/itemNight1.png");
	texManager.add("item2Night", "image/itemNight2.png");
	texManager.add("dirtMorning", "image/dirtMorning.png");
	texManager.add("dirtAfternoon", "image/dirtAfternoon.png");
	texManager.add("dirtNight", "image/dirtNight.png");

	//  Scenes
	texManager.add("DT", "image/DT.png");
	texManager.add("SS", "image/SS.png");
	texManager.add("HN", "image/HaNoi.png");
	texManager.add("DN", "image/DaNang.png");
	texManager.add("lake", "image/lake.png");
	texManager.add("river", "image/sea1.png");
	//texManager.add("summon", "image/summon.png");
	texManager.add("summonStart", "image/summonStart.png");
	texManager.add("startLight", "image/summonStartLight.png");
	texManager.add("tower1", "image/tower1.png");
	texManager.add("tower2", "image/tower2.png");
	texManager.add("tower3", "image/tower3.png");
	texManager.add("circle1", "image/circle1.png");
	texManager.add("circles1", "image/circles1Light.png");
	texManager.add("circle1Light", "image/circle1Light.png");
	texManager.add("circle2", "image/circle2.png");
	texManager.add("circles2", "image/circles2Light.png");
	texManager.add("circle2Light", "image/circle2Light.png");
	texManager.add("circle3", "image/circle3.png");
	texManager.add("circles3", "image/circles3Light.png");
	texManager.add("circle3Light", "image/circle3Light.png");
	texManager.add("circle4", "image/circle4.png");
	texManager.add("circles4", "image/circles4Light.png");
	texManager.add("circle4Light", "image/circle4Light.png");

	// Monsters
	texManager.add("BigMonster1", "image/BigMonster.png");
	texManager.add("BigMonster2", "image/BigMonster.png");
	texManager.add("FlyingEye1", "image/FlyingEye.png");
	texManager.add("FlyingEye2", "image/FlyingEye.png");
	texManager.add("Goblin1", "image/Goblin.png");
	texManager.add("Goblin2", "image/Goblin.png");
	texManager.add("Skeleton1", "image/Skeleton.png");
	texManager.add("Skeleton2", "image/Skeleton.png");

	// Effects
	texManager.add("hitEffect", "image/hitEffect.png");
	texManager.add("deadEffect" , "image/deadEffect.png");
	texManager.add("shootEffect", "image/shootEffect.png");
	return true;
}

void Game::movePlayer(Time& elapsed, int x, int y, int w, int h) {
	if (Keyboard::isKeyPressed(Keyboard::W))
		player.addForce(0, -PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::A))
		player.addForce(-PLAYER_SPEED, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))
		player.addForce(0, PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::D))
		player.addForce(PLAYER_SPEED, 0);
	if (Keyboard::isKeyPressed(Keyboard::LShift))
		player.speedMod(player.getMaxSpeed() * 2.0);
	if (Keyboard::isKeyPressed(Keyboard::Up))
		player.addForce(0, -PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::Left))
		player.addForce(-PLAYER_SPEED, 0);
	if (Keyboard::isKeyPressed(Keyboard::Down))
		player.addForce(0, PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::Right))
		player.addForce(PLAYER_SPEED, 0);

	if (player.getPos().x + player.getSize().x / 2.f > x + w)
	{
		player.setPos(Vector2f(x + w - player.getSize().x / 2.f - 1, player.getPos().y));
	}
	else if (player.getPos().x - player.getSize().x / 2.f < x)
	{
		player.setPos(Vector2f(x + player.getSize().x / 2.f + 1, player.getPos().y));
	}
	if (player.getPos().y + player.getSize().y / 2.f > y + h)
	{
		player.setPos(Vector2f(player.getPos().x, y + h - player.getSize().y / 2.f - 1));
	}
	else if (player.getPos().y - player.getSize().y / 2.f < y)
	{
		player.setPos(Vector2f(player.getPos().x, y + player.getSize().y / 2.f + 1));
	}

	int lastDir = player.getDir();
	player.look(cursor.getCursor().getPosition(), elapsed);
	player.update(elapsed);

	if (player.getAngle() <= 180) {
		player.setDir(0);
	}
	else {
		player.setDir(1);
	}
	if (player.getDir() == 0 && lastDir == 1) {
		player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6, 1)));
	}
	else if (player.getDir() == 1 && lastDir == 0) {
		player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "2"), Vector2i(6, 1)));
	}
}

void Game::movePlayerObstacle(Time& elapsed, int x, int y, int w, int h, vector<Obstacle> _obstacles) {
	if (Keyboard::isKeyPressed(Keyboard::W))
		player.addForce(0, -PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::A))
		player.addForce(-PLAYER_SPEED, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))
		player.addForce(0, PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::D))
		player.addForce(PLAYER_SPEED, 0);
	if (Keyboard::isKeyPressed(Keyboard::LShift))
		player.speedMod(player.getMaxSpeed() * 2.0);
	if (Keyboard::isKeyPressed(Keyboard::Up))
		player.addForce(0, -PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::Left))
		player.addForce(-PLAYER_SPEED, 0);
	if (Keyboard::isKeyPressed(Keyboard::Down))
		player.addForce(0, PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::Right))
		player.addForce(PLAYER_SPEED, 0);

	for (Obstacle& object : _obstacles) {
		if (!object.isCollided(player, object.getSize().x, object.getSize().x, false)) continue;
		else
		{
			if (player.getPos().x < object.getPos().x - object.getSize().x / 2.f) {
				player.setForce(Vector2f(-PLAYER_SPEED / 2, 0));
			}
			if (player.getPos().y < object.getPos().y - object.getSize().y / 2.f) {
				player.setForce(Vector2f(0, -PLAYER_SPEED / 2));
			}
			if (player.getPos().x > object.getPos().x + object.getSize().x / 2.f) {
				player.setForce(Vector2f(PLAYER_SPEED / 2, 0));
			}
			if (player.getPos().y > object.getPos().y + object.getSize().y / 2.f) {
				player.setForce(Vector2f(0, PLAYER_SPEED / 2));
			}
		}
	}

	if (player.getPos().x + player.getSize().x / 2.f > x + w)
	{
		player.setPos(Vector2f(x + w - player.getSize().x / 2.f - 1, player.getPos().y));
	}
	else if (player.getPos().x - player.getSize().x / 2.f < x)
	{
		player.setPos(Vector2f(x + player.getSize().x / 2.f + 1, player.getPos().y));
	}
	if (player.getPos().y + player.getSize().y / 2.f > y + h)
	{
		player.setPos(Vector2f(player.getPos().x, y + h - player.getSize().y / 2.f - 1));
	}
	else if (player.getPos().y - player.getSize().y / 2.f < y)
	{
		player.setPos(Vector2f(player.getPos().x, y + player.getSize().y / 2.f + 1));
	}

	int lastDir = player.getDir();
	player.look(cursor.getCursor().getPosition(), elapsed);
	player.update(elapsed);

	if (player.getAngle() <= 180) {
		player.setDir(0);
	}
	else {
		player.setDir(1);
	}
	if (player.getDir() == 0 && lastDir == 1) {
		player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6, 1)));
	}
	else if (player.getDir() == 1 && lastDir == 0) {
		player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "2"), Vector2i(6, 1)));
	}
}

void Game::run()
{
	int chaos = 0;
	sf::FloatRect textRect;
	SoundBuffer bufferDead;
	SoundBuffer bufferEasyMode;
	SoundBuffer bufferHardMode;
	SoundBuffer bufferAWM;
	SoundBuffer bufferCook;

	Sound soundDead;
	Sound soundEasyMode;
	Sound soundHardMode;
	Sound soundAWM;
	Sound soundCook;

	int GameMode = 1; // => HIEN FIX

	bufferDead.loadFromFile("sound/Dead.wav");
	bufferEasyMode.loadFromFile("sound/easyMode.wav");
	bufferHardMode.loadFromFile("sound/hardMode.wav");
	bufferAWM.loadFromFile("sound/AWM.wav");
	bufferCook.loadFromFile("sound/letHimCook.wav");

	soundDead.setBuffer(bufferDead);
	soundEasyMode.setBuffer(bufferEasyMode);
	soundHardMode.setBuffer(bufferHardMode);
	soundAWM.setBuffer(bufferAWM);
	soundCook.setBuffer(bufferCook);

	vector<Character> vz;
	Projectile p, shootEffect;
	vector<Projectile> vp, vef;
	vector<Animation> vHitEffect;
	Animation emoji, winScreen;
	vector<Animation> vDeadEffect;
	vector<Obstacle> obstacles, treeDay, audio, sound, mute;
	Obstacle fireAudio, fireSound, fireMute;
	vector<Sprite> hearts;
	for(int i=0; i<MAX_LIFES; i++) {
		Sprite temp;
		temp.setTextureRect(IntRect(0,0,36,33));
		temp.setTexture(*texManager.get("heart"));
		hearts.push_back(temp);
	}

	winScreen.init(Vector2f(0, 0), Animator(100, Vector2f(0,0), Vector2f(1200, 674), texManager.get("master"), Vector2i(12,1)));
	fireAudio.init(Vector2f(0, 0), Animator(50, Vector2f(0, 0), Vector2f(96, 96), texManager.get("fireRed"), Vector2i(4, 4)));
	fireSound.init(Vector2f(0, 0), Animator(50, Vector2f(0, 0), Vector2f(96, 96), texManager.get("fireGreen"), Vector2i(4, 4)));
	fireMute.init(Vector2f(0, 0), Animator(50, Vector2f(0, 0), Vector2f(96, 96), texManager.get("fireBlack"), Vector2i(4, 4)));
	for (int i = 0; i <= 10; i++) {
		fireAudio.setPos(Vector2f(LVL_X_LIMIT / 2.f - 350, LVL_Y_LIMIT - 300 + 60 * i));
		audio.push_back(fireAudio);
		fireSound.setPos(Vector2f(LVL_X_LIMIT / 2.f + 350, LVL_Y_LIMIT - 300 + 60 * i));
		sound.push_back(fireSound);
		fireMute.setPos(Vector2f(LVL_X_LIMIT / 2.f - 350, LVL_Y_LIMIT - 300 + 60 * i));
		mute.push_back(fireMute);
		fireMute.setPos(Vector2f(LVL_X_LIMIT / 2.f + 350, LVL_Y_LIMIT - 300 + 60 * i));
		mute.push_back(fireMute);
	}
	audioVolumn = 10;
	soundVolumn = 10;
	int x_rand, y_rand;

	Sprite floor, grass, lake, river, floorSpring, floorSummer, floorAutumn, floorWinter, smallTree, item1, item2;
	grass.setTextureRect(IntRect(0, 0, LVL_X_LIMIT, LVL_Y_LIMIT));
	floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT));
	floorSpring.setTextureRect(IntRect(0,0,LVL_X_LIMIT / 2,LVL_Y_LIMIT / 2));
	floorSummer.setTextureRect(IntRect(0,0,LVL_X_LIMIT / 2,LVL_Y_LIMIT / 2));
	floorAutumn.setTextureRect(IntRect(0,0,LVL_X_LIMIT / 2,LVL_X_LIMIT / 2));
	floorWinter.setTextureRect(IntRect(0,0,LVL_X_LIMIT / 2,LVL_Y_LIMIT / 2));
	smallTree.setTextureRect(IntRect(0,0,32,32));
	item1.setTextureRect(IntRect(0,0,48,32));
	item2.setTextureRect(IntRect(0,0,32,48));

	texManager.get("dirtSpring")->setRepeated(true);
	floorSpring.setTexture(*texManager.get("dirtSpring"));
	floorSpring.setPosition(Vector2f(0, 0));

	texManager.get("dirtSummer")->setRepeated(true);
	floorSummer.setTexture(*texManager.get("dirtSummer"));
	floorSummer.setPosition(Vector2f(LVL_X_LIMIT/2, 0));

	texManager.get("dirtAutumn")->setRepeated(true);
	floorAutumn.setTexture(*texManager.get("dirtAutumn"));
	floorAutumn.setPosition(Vector2f(0, LVL_Y_LIMIT/2));

	texManager.get("dirtWinter")->setRepeated(true);
	floorWinter.setTexture(*texManager.get("dirtWinter"));
	floorWinter.setPosition(Vector2f(LVL_X_LIMIT/2, LVL_Y_LIMIT/2));

	for(int i=0; i<4; i++) {
		Obstacle temp = Obstacle(Vector2f(0,0), Animator(1, Vector2f(0,0), Vector2f(80,96), texManager.get("treeMorning"), Vector2i(1,1)));
		treeDay.push_back(temp);
	}

	for (int i = 0; i < NUM_TREESPRING; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(TREE_W, TREE_H), texManager.get("treeSpring"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}
	for (int i = 0; i < NUM_TREESUMMER; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT/2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(TREE_W, TREE_H), texManager.get("treeSummer"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}
	for (int i = 0; i < NUM_TREEAUTUMN; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(TREE_W, TREE_H), texManager.get("treeAutumn"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}
	for (int i = 0; i < NUM_TREEWINTER; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(TREE_W, TREE_H), texManager.get("treeWinter"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}

	/*for (int i = 0; i < NUM_ROCKSPRING1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("rockSpring1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_ROCKSPRING2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(ROCK_W, ROCK_H), texManager.get("rockSpring2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}
	/*for (int i = 0; i < NUM_FLOWERSPRING1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("flowerSpring1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_FLOWERSPRING2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(FLOWER_W, FLOWER_H), texManager.get("flowerSpring2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}

	/*for (int i = 0; i < NUM_ROCKSUMMER1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT/2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("rockSummer1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_ROCKSUMMER2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT/2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(ROCK_W, ROCK_H), texManager.get("rockSummer2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}
	/*for (int i = 0; i < NUM_FLOWERSUMMER1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT/2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("flowerSummer1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_FLOWERSUMMER2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT/2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(FLOWER_W, FLOWER_H), texManager.get("flowerSummer2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}


	/*for (int i = 0; i < NUM_ROCKAUTUMN1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("rockAutumn1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_ROCKAUTUMN2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(ROCK_W, ROCK_H), texManager.get("rockAutumn2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}
	/*for (int i = 0; i < NUM_FLOWERAUTUMN1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("flowerAutumn1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_FLOWERAUTUMN2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(FLOWER_W, FLOWER_H), texManager.get("flowerAutumn2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}

	/*for (int i = 0; i < NUM_ROCKWINTER1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT / 2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("rockWinter1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_ROCKWINTER2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(ROCK_W, ROCK_H), texManager.get("rockWinter2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}
	/*for (int i = 0; i < NUM_FLOWERWINTER1; i++)
	{
	x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT / 2 - 16;
	y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
	Sprite temp;
	temp.setTexture(*texManager.get("flowerWinter1"));
	temp.setPosition(x_rand,y_rand);
	object.push_back(temp);
	}*/
	for (int i = 0; i < NUM_FLOWERWINTER2; i++)
	{
		x_rand = rand() % LVL_X_LIMIT / 2 + LVL_X_LIMIT / 2 - 16;
		y_rand = rand() % LVL_Y_LIMIT / 2 + LVL_Y_LIMIT / 2 - 16;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(1, Vector2f(0, 0), Vector2f(FLOWER_W, FLOWER_H), texManager.get("flowerWinter2"), Vector2i(1, 1)));
		obstacles.push_back(temp);
	}

	Font f;
	f.loadFromFile("BAUHS93.TTF");

	Text life, endLife;
	life.setFont(f);
	life.setFillColor(Color::Red);
	life.setPosition(view.getCenter() - view.getSize() / 2.f + Vector2f(10, 10));
	life.setCharacterSize(30);
	endLife.setFont(f);
	endLife.setFillColor(Color::Red);
	endLife.setPosition(view.getCenter() - view.getSize() / 2.f + Vector2f(10, 10));
	endLife.setCharacterSize(30);
	vector<FloatingText> vt;

	FloatingText t;

	t.init("DEAD", 1000, 0.05);
	t.setFont(f);
	t.setSize(20);
	t.setFillColor(Color::Red);

	player.setMaxSpeed(PLAYER_SPEED);
	player.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6, 1))); // FIX
	player.setCoolDown(INIT_COOLDOWN);
	player.setFull(INIT_HP);

	int points = 0;
	bool lvlUp = false;
	int lvl = 1;

	life.setString("HP: " + player.getHp());

	Character BigMonster = Character(0);
	Character FlyingEye = Character(1);
	Character Goblin = Character(2);
	Character Skeleton = Character(3);
	Character heal = Character(4);
	Character dmg = Character(5);
	Character speed = Character(6);
	// Need to config origin vector 
	BigMonster.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[0][0], MONS_SIZE[0][1]), texManager.get(MONS_NAME[BigMonster.type][0]), Vector2i(1, 1)));
	BigMonster.setDmg(10);
	BigMonster.setMaxSpeed(0.3);
	BigMonster.setFull(50);
	BigMonster.setCoolDown(1000);

	FlyingEye.init(Vector2f(0, 0), Animator(100, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[1][0], MONS_SIZE[1][1]), texManager.get(MONS_NAME[FlyingEye.type][0]), Vector2i(1, 1)));
	FlyingEye.setDmg(10);
	FlyingEye.setMaxSpeed(0.8);
	FlyingEye.setFull(20);
	FlyingEye.setCoolDown(1200);

	Goblin.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[2][0], MONS_SIZE[2][1]), texManager.get(MONS_NAME[Goblin.type][0]), Vector2i(1, 1)));
	Goblin.setDmg(20);
	Goblin.setMaxSpeed(0.3);
	Goblin.setFull(30);
	Goblin.setCoolDown(500);

	Skeleton.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[3][0], MONS_SIZE[3][1]), texManager.get(MONS_NAME[Skeleton.type][0]), Vector2i(1, 1)));
	Skeleton.setDmg(100);
	Skeleton.setMaxSpeed(0.15);
	Skeleton.setFull(150);
	Skeleton.setCoolDown(500);

	heal.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[heal.type][0]), Vector2i(1, 1)));
	heal.setDmg(-20);
	heal.setMaxSpeed(0.01);
	heal.setFull(5000);
	heal.setCoolDown(10);

	dmg.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[dmg.type][0]), Vector2i(1, 1)));
	dmg.setDmg(0);
	dmg.setMaxSpeed(0.01);
	dmg.setFull(5000);
	dmg.setCoolDown(10);

	speed.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[speed.type][0]), Vector2i(1, 1)));
	speed.setDmg(0);
	speed.setMaxSpeed(0.01);
	speed.setFull(5000);
	speed.setCoolDown(10);

	int choosed = 0;
	Weapon bazoka = Weapon(2);
	bazoka.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("bazoka"), Vector2i(1, 1)));
	bazoka.setCoolDown(INIT_COOLDOWN);

	Weapon AWM = Weapon(1);
	AWM.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("AWM"), Vector2i(4, 1)));
	AWM.setCoolDown(INIT_COOLDOWN);

	Weapon shortGun = Weapon(0);
	shortGun.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("shortGun"), Vector2i(4, 1)));
	shortGun.setCoolDown(INIT_COOLDOWN);

	player.chooseWeapon(shortGun);

	skinBoss = skin;
	Character BOSS(-1);
	BOSS.setMaxSpeed(BOSS_SPEED);
	BOSS.init(Vector2f(600,600), Animator(200, Vector2f(0, 0), Vector2f(176, 176), texManager.get(AVATAR[skinBoss] + "BOSS" + "1"), Vector2i(6, 1))); // FIX
	BOSS.setCoolDown(BOSS_COOLDOWN);
	BOSS.setFull(BOSS_HP);

	int deadMode = 0;
	Counter nextSpawn(SPAWN_SPEED), letHimCook(11000);

	Counter buff_duration(5000);
	buff_duration.setEmpty();
	RectangleShape buff_duration_bar;

	Clock clock;
	Time elapsed;

	int edge;
	int x, y, kind, dir=0;
	int buff_count=0;
	Sprite frame, wpPic1, wpPic2, wpPic3, DN, HN;
	Obstacle buildSkin, buildWeapon, buildOption, buildStart, doormat, DT, SS;
	Obstacle targetWeapon[3], chooseSkin[4];
	DN.setTexture(*texManager.get("DN"));
	DN.setTextureRect(IntRect(0,0,400,251));
	DN.setOrigin(200,125);
	HN.setTexture(*texManager.get("HN"));
	HN.setTextureRect(IntRect(0,0,350,403));
	HN.setOrigin(175,201);
	DT.init(Vector2f(LVL_X_LIMIT / 2.f - 300, LVL_Y_LIMIT / 2.f + 200), Animator(200, Vector2f(0, 0), Vector2f(450, 324), texManager.get("DT"), Vector2i(1, 1)));
	SS.init(Vector2f(LVL_X_LIMIT / 2.f - 250, 300), Animator(200, Vector2f(0, 0), Vector2f(400, 400), texManager.get("SS"), Vector2i(1, 1)));

	buildSkin.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(100, 300), texManager.get("tower1"), Vector2i(1, 1)));
	buildWeapon.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(100, 300), texManager.get("tower2"), Vector2i(1, 1)));
	buildOption.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(100, 300), texManager.get("tower3"), Vector2i(1, 1)));
	buildStart.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(600, 600), texManager.get("summonStart"), Vector2i(1, 1)));
	doormat.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(150, 100), texManager.get("doormat"), Vector2i(1, 1)));
	for (int i = 0; i < 3; i++) {
		targetWeapon[i].init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(64, 64), texManager.get("target"), Vector2i(1, 1)));
	}
	chooseSkin[0].init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(100, Vector2f(0, 0), Vector2f(135, 135), texManager.get("circle1"), Vector2i(1, 1)));
	chooseSkin[1].init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(100, Vector2f(0, 0), Vector2f(135, 135), texManager.get("circle2"), Vector2i(1, 1)));
	chooseSkin[2].init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(100, Vector2f(0, 0), Vector2f(135, 135), texManager.get("circle3"), Vector2i(1, 1)));
	chooseSkin[3].init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(100, Vector2f(0, 0), Vector2f(135, 135), texManager.get("circle4"), Vector2i(1, 1)));
	Counter wait;
	bool isIn[5] = { false };
	float RADIUS = 350, S_RADIUS = 250;
	char circles[4][3][30] = { {"circle1", "circles1", "circle1Light"}, {"circle2", "circles2", "circle2Light"}, {"circle3", "circles3", "circle3Light"}, {"circle4", "circles4", "circle4Light"} };
	soundEasyMode.play();
	int lastDir;
	RectangleShape c;
	c.setFillColor(Color::Black);
	c.setSize(Vector2f(LVL_X_LIMIT, LVL_Y_LIMIT));
	c.setPosition(Vector2f(0, 0));
	while (window.isOpen())
	{
		sf::Event event;
		elapsed = clock.restart();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::Escape)) {
					lastScreen = getScreen();
					setScreen(9);
				}
				/*if (Keyboard::isKeyPressed(Keyboard::LControl)) {
					if (Keyboard::isKeyPressed(Keyboard::Num3)) {
						emoji = Animation(Vector2f(player.getPos().x, player.getPos().y - 50), Animator(2000, Vector2f(0, 0), Vector2f(64, 64), texManager.get("Blue1"), Vector2i(6, 1)));
					}
					if (Keyboard::isKeyPressed(Keyboard::Num6)) {
						emoji = Animation(Vector2f(player.getPos().x, player.getPos().y - 50), Animator(2000, Vector2f(0, 0), Vector2f(64, 64), texManager.get("Pink1"), Vector2i(6, 1)));
					}
				}*/
				if (Keyboard::isKeyPressed(Keyboard::LControl)) {
					if (Keyboard::isKeyPressed(Keyboard::G)) {
						godMode = true;
					}
					if (Keyboard::isKeyPressed(Keyboard::B)) {
						godMode = false;
					}
				}
			}
		}
		//emoji.update(elapsed);

		soundDead.setVolume(10 * soundVolumn);
		soundAWM.setVolume(10 * soundVolumn);
		soundEasyMode.setVolume(10 * audioVolumn);
		soundHardMode.setVolume(10 * audioVolumn);
		switch (getScreen()) {
		case -1:
			window.draw(c);
			endLife.setString("INTERN'");
			endLife.setFillColor(Color::White);
			endLife.setCharacterSize(150);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(view.getCenter().x - 280, view.getCenter().y - 100);
			window.draw(endLife);
			endLife.setString("S S");
			endLife.setFillColor(Color::Blue);
			endLife.setCharacterSize(150);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(view.getCenter().x + 43, view.getCenter().y - 100);
			window.draw(endLife);
			endLife.setString("TORY");
			endLife.setFillColor(Color::White);
			endLife.setCharacterSize(150);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(view.getCenter().x + 310, view.getCenter().y - 100);
			window.draw(endLife);
			endLife.setString("Press [Enter] to Start Game");
			endLife.setFillColor(Color::White);
			endLife.setCharacterSize(50);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(view.getCenter().x, view.getCenter().y + 100);
			window.draw(endLife);
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				setScreen(0);
				setResetPos(false);
			}
			break;
		case 0:
			if (SoundSource::Status::Playing != soundEasyMode.getStatus()) soundEasyMode.play();
			soundHardMode.stop();
			soundCook.stop();
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 250));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("wood")->setRepeated(true);
			floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT));
			floor.setTexture(*texManager.get("wood"));
			floor.setPosition(Vector2f(500, 500));

			buildStart.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f));
			buildStart.update(elapsed);
			buildSkin.setPos(Vector2f(buildStart.getPos().x + RADIUS * cos(30 * ut::TO_RADIAN), buildStart.getPos().y + RADIUS * sin(30 * ut::TO_RADIAN) - buildSkin.getSize().y / 2.f + buildSkin.getSize().x / 2.f));
			buildSkin.update(elapsed);
			buildWeapon.setPos(Vector2f(buildStart.getPos().x - RADIUS * cos(30 * ut::TO_RADIAN), buildStart.getPos().y + RADIUS * sin(30 * ut::TO_RADIAN) - buildWeapon.getSize().y / 2.f + buildWeapon.getSize().x / 2.f));
			buildWeapon.update(elapsed);
			buildOption.setPos(Vector2f(buildStart.getPos().x, buildStart.getPos().y - RADIUS - buildOption.getSize().y / 2.f + buildOption.getSize().x / 2.f));
			buildOption.update(elapsed);
			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);

			// Config trigger
			if (buildOption.isCollided(player, buildOption.getSize().x, buildOption.getSize().x, false)) {
				setScreen(1);
				setResetPos(false);
			}

			if (buildWeapon.isCollided(player, buildWeapon.getSize().x, buildWeapon.getSize().x, false)) {
				setScreen(2);
				setResetPos(false);
			}

			if (buildSkin.isCollided(player, buildSkin.getSize().x, buildSkin.getSize().x, false)) {
				setScreen(3);
				setResetPos(false);
			}

			if (buildStart.isCollided(player, buildStart.getSize().x / 2.f, buildStart.getSize().y / 2.f, true)) {
				if (isIn[0]) {
					wait.add(elapsed.asMilliseconds());
					//cout << wait.get() << endl;
				}
				else {
					wait.set(0);
					buildStart.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(40, Vector2f(0, 0), Vector2f(600, 600), texManager.get("startLight"), Vector2i(16, 1)));
					isIn[0] = true;
				}
				if (wait.get() >= 5000) {
					setScreen(4);
					setResetPos(false);
				}
			}
			else {
				isIn[0] = false;
				buildStart.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(600, 600), texManager.get("summonStart"), Vector2i(1, 1)));
			}

			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[1]) {
					wait.add(elapsed.asMilliseconds());
					//cout << wait.get() << endl;
				}
				else {
					wait.set(0);
					isIn[1] = true;
				}
				if (wait.get() >= 2000) {
					lastScreen = 0;
					setScreen(9);
					setResetPos(false);
				}
			}
			else isIn[1] = false;
			movePlayer(elapsed,500,500,MENU_X_LIMIT, MENU_Y_LIMIT);
			// Draw
			window.draw(c);
			window.draw(floor);
			buildStart.draw(window);
			doormat.draw(window);
			player.draw(window);
			buildSkin.draw(window);
			buildWeapon.draw(window);
			buildOption.draw(window);
			break;
		case 1: // Choosing weapon
			if (SoundSource::Status::Playing != soundEasyMode.getStatus()) soundEasyMode.play();
			soundHardMode.stop();
			soundCook.stop();
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 250));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("wood")->setRepeated(true);
			floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT));
			floor.setTexture(*texManager.get("wood"));
			floor.setPosition(Vector2f(500, 500));
			movePlayer(elapsed,500,500,MENU_X_LIMIT, MENU_Y_LIMIT);

			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);
			targetWeapon[0].setPos(Vector2f(LVL_X_LIMIT / 2.f - 200, LVL_Y_LIMIT / 2.f - 100));
			targetWeapon[0].update(elapsed);
			targetWeapon[1].setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f - 100));
			targetWeapon[1].update(elapsed);
			targetWeapon[2].setPos(Vector2f(LVL_X_LIMIT / 2.f + 200, LVL_Y_LIMIT / 2.f - 100));
			targetWeapon[2].update(elapsed);
			wpPic1.setTextureRect(IntRect(0,0,WEAPON_SIZE,WEAPON_SIZE));
			wpPic1.setOrigin(WEAPON_SIZE / 2.f,WEAPON_SIZE / 2.f);
			wpPic1.setPosition(LVL_X_LIMIT / 2.f - 200, LVL_Y_LIMIT / 2.f - 210);
			wpPic1.setTexture(*texManager.get("shortGun"));
			wpPic2.setTextureRect(IntRect(0,0,WEAPON_SIZE,WEAPON_SIZE));
			wpPic2.setOrigin(WEAPON_SIZE / 2.f,WEAPON_SIZE / 2.f);
			wpPic2.setPosition(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f - 210);
			wpPic2.setTexture(*texManager.get("AWM"));
			wpPic3.setTextureRect(IntRect(0,0,WEAPON_SIZE,WEAPON_SIZE));
			wpPic3.setOrigin(WEAPON_SIZE / 2.f,WEAPON_SIZE / 2.f);
			wpPic3.setPosition(LVL_X_LIMIT / 2.f + 200, LVL_Y_LIMIT / 2.f - 210);
			wpPic3.setTexture(*texManager.get("bazoka"));
			frame.setTextureRect(IntRect(0,0,144,144));
			frame.setOrigin(72,72);
			frame.setTexture(*texManager.get("frame"));

			// Config Trigger
			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[0]) {
					wait.add(elapsed.asMilliseconds());
					//cout << wait.get() << endl;
				}
				else {
					wait.set(0);
					isIn[0] = true;
				}
				if (wait.get() >= 2000) {
					setScreen(0);
					setResetPos(false);
				}
			}
			else isIn[0] = false;

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (player.useDmg())
				{
					soundAWM.play();
					p.init(player.getPos(), player.getAngle() - 90, 1.0f, 2000, texManager.get("bullet"),0);
					shootEffect.init(player.getPos(), Vector2f(32, 32), player.getAngle() - 90, 0.5, 100, texManager.get("shootEffect"));
					player.jetForce();
					vp.push_back(p);
					vef.push_back(shootEffect);
				}
			}
			for (Projectile& p : vp)
			{
				p.update(elapsed);
				for (int i = 0; i < 3; i++) {
					if (targetWeapon[i].isAttacked(p)) {
						p.destroy();
						choosed = i;
					}
				}
			}
			if (choosed == 0)  frame.setPosition(LVL_X_LIMIT / 2.f - 200, LVL_Y_LIMIT / 2.f - 210);
			else if (choosed == 1) frame.setPosition(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f - 210);
			else if (choosed == 2) frame.setPosition(LVL_X_LIMIT / 2.f + 200, LVL_Y_LIMIT / 2.f - 210);
			vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return p.isDestroyed(); }), vp.end());
			if (choosed == 0) {
				player.chooseWeapon(shortGun);
			}
			else if (choosed == 1) {
				player.chooseWeapon(AWM);
			}
			else if (choosed == 2) {
				player.chooseWeapon(bazoka);
			}

			// Draw
			window.draw(floor);
			window.draw(frame);
			window.draw(wpPic1);
			window.draw(wpPic2);
			window.draw(wpPic3);
			doormat.draw(window);
			for (int i = 0; i < 3; i++)
			{
				targetWeapon[i].draw(window);
			}
			for (Projectile& p : vp)
			{
				p.draw(window);
			}
			player.draw(window);
			//player.weapon.draw(window);
			break;
		case 2: // Choosing Skin
			if (SoundSource::Status::Playing != soundEasyMode.getStatus()) soundEasyMode.play();
			soundHardMode.stop();
			soundCook.stop();
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("wood")->setRepeated(true);
			floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT));
			floor.setTexture(*texManager.get("wood"));
			floor.setPosition(Vector2f(500, 500));
			movePlayer(elapsed,500,500,MENU_X_LIMIT,MENU_Y_LIMIT);
			endLife.setString("CHOOSING SKIN");
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(80);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y - 420));
			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);
			chooseSkin[0].setPos(Vector2f(LVL_X_LIMIT / 2.f - S_RADIUS, LVL_Y_LIMIT / 2.f - S_RADIUS));
			chooseSkin[0].update(elapsed);
			chooseSkin[1].setPos(Vector2f(LVL_X_LIMIT / 2.f + S_RADIUS, LVL_Y_LIMIT / 2.f + S_RADIUS));
			chooseSkin[1].update(elapsed);
			chooseSkin[2].setPos(Vector2f(LVL_X_LIMIT / 2.f - S_RADIUS, LVL_Y_LIMIT / 2.f + S_RADIUS));
			chooseSkin[2].update(elapsed);
			chooseSkin[3].setPos(Vector2f(LVL_X_LIMIT / 2.f + S_RADIUS, LVL_Y_LIMIT / 2.f - S_RADIUS));
			chooseSkin[3].update(elapsed);

			// Config trigger
			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[4]) {
					wait.add(elapsed.asMilliseconds());
					//cout << wait.get() << endl;
				}
				else {
					wait.set(0);
					isIn[4] = true;
				}
				if (wait.get() >= 2000) {
					setScreen(0);
					setResetPos(false);
				}
			}
			else isIn[4] = false;

			for (int i = 0; i < 4; i++) {
				//cout << skin << endl;
				if (i == skin) continue;
				if (chooseSkin[i].isCollided(player, chooseSkin[i].getSize().x, chooseSkin[i].getSize().y, false)) {
					if (isIn[i]) {
						wait.add(elapsed.asMilliseconds());
						//cout << wait.get() << endl;
					}
					else {
						wait.set(0);
						chooseSkin[i].init(Vector2f(chooseSkin[i].getPos().x, chooseSkin[i].getPos().y), Animator(50, Vector2f(0, 0), Vector2f(135, 135), texManager.get(circles[i][1]), Vector2i(8, 1)));
						isIn[i] = true;
					}
					if (wait.get() >= 2000) {
						chooseSkin[i].init(Vector2f(chooseSkin[i].getPos().x, chooseSkin[i].getPos().y), Animator(100, Vector2f(0, 0), Vector2f(135, 135), texManager.get(circles[i][2]), Vector2i(1, 1)));
						if (skin != -1) chooseSkin[skin].init(Vector2f(chooseSkin[skin].getPos().x, chooseSkin[skin].getPos().y), Animator(100, Vector2f(0, 0), Vector2f(135, 135), texManager.get(circles[skin][0]), Vector2i(1, 1)));
						skin = i;
						skinBoss = skin;
						player.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6, 1)));
						BOSS.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(176, 176), texManager.get(AVATAR[skinBoss] + "BOSS" + "1"), Vector2i(6,1)));
					}
				}
				else {
					isIn[i] = false;
					chooseSkin[i].init(Vector2f(chooseSkin[i].getPos().x, chooseSkin[i].getPos().y), Animator(100, Vector2f(0, 0), Vector2f(135, 135), texManager.get(circles[i][0]), Vector2i(1, 1)));
				}
			}

			// Draw
			window.draw(floor);
			doormat.draw(window);
			for (int i = 0; i < 4; i++)
			{
				chooseSkin[i].draw(window);
			}
			window.draw(endLife);
			player.draw(window);
			break;
		case 3: // Setting Audio
			if (SoundSource::Status::Playing != soundEasyMode.getStatus()) soundEasyMode.play();
			soundHardMode.stop();
			soundCook.stop();
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("wood")->setRepeated(true);
			floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT));
			floor.setTexture(*texManager.get("wood"));
			floor.setPosition(Vector2f(500, 500));
			movePlayer(elapsed,500,500,MENU_X_LIMIT,MENU_Y_LIMIT);
			endLife.setString("AUDIO");
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(50);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(LVL_X_LIMIT / 2.f - 300, LVL_Y_LIMIT / 2.f - 420));
			window.draw(endLife);
			endLife.setString("EFFECT");
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(50);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(LVL_X_LIMIT / 2.f + 300, LVL_Y_LIMIT / 2.f - 420));
			window.draw(endLife);
			endLife.setString("SETTING SOUND");
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(80);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y - 420));
			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);
			for (int i = 0; i <= 10; i++) {
				audio[i].setPos(Vector2f(LVL_X_LIMIT / 2.f - 350, LVL_Y_LIMIT / 2.f + 300 - 60 * i));
				audio[i].update(elapsed);
				sound[i].setPos(Vector2f(LVL_X_LIMIT / 2.f + 350, LVL_Y_LIMIT / 2.f + 300 - 60 * i));
				sound[i].update(elapsed);
				mute[i * 2].setPos(Vector2f(LVL_X_LIMIT / 2.f - 350, LVL_Y_LIMIT / 2.f + 300 - 60 * i));
				mute[i * 2].update(elapsed);
				mute[i * 2 + 1].setPos(Vector2f(LVL_X_LIMIT / 2.f + 350, LVL_Y_LIMIT / 2.f + 300 - 60 * i));
				mute[i * 2 + 1].update(elapsed);
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (player.useDmg())
				{
					soundAWM.play();
					p.init(player.getPos(), player.getAngle() - 90, 1.0f, 2000, texManager.get("bullet"),0);
					shootEffect.init(player.getPos(), Vector2f(32, 32), player.getAngle() - 90, 0.5, 100, texManager.get("shootEffect"));
					player.jetForce();
					vp.push_back(p);
					vef.push_back(shootEffect);
				}
			}

			for (Projectile& p : vp)
			{
				p.update(elapsed);
				for (int i = 0; i <= 10; i++) {
					if (audio[i].isAttacked(p)) {
						p.destroy();
						audioVolumn = i;
					}
					if (sound[i].isAttacked(p)) {
						p.destroy();
						soundVolumn = i;
					}
				}
			}

			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[0]) {
					wait.add(elapsed.asMilliseconds());
					//cout << wait.get() << endl;
				}
				else {
					wait.set(0);
					isIn[0] = true;
				}
				if (wait.get() >= 2000) {
					setScreen(0);
					setResetPos(false);
				}
			}
			else isIn[0] = false;
			vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return p.isDestroyed(); }), vp.end());
			// Draw
			window.draw(floor);
			for (int i = 0; i <= audioVolumn; i++) {
				audio[i].draw(window);
			}
			for (int i = 0; i <= soundVolumn; i++) {
				sound[i].draw(window);
			}
			for (int i = audioVolumn + 1; i < 11; i++) {
				mute[i * 2].draw(window);
			}
			for (int i = soundVolumn + 1; i < 11; i++) {
				mute[i * 2 + 1].draw(window);
			}
			for (Projectile& p : vp)
			{
				p.draw(window);
			}
			doormat.draw(window);
			window.draw(endLife);
			player.draw(window);
			break;
		case 4: // Choosing Mode
			if (SoundSource::Status::Playing != soundEasyMode.getStatus()) soundEasyMode.play();
			soundHardMode.stop();
			soundCook.stop();
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 250));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("wood")->setRepeated(true);
			floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT+500));
			floor.setTexture(*texManager.get("wood"));
			floor.setPosition(Vector2f(500, 0));

			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);
			DN.setPosition(LVL_X_LIMIT / 2.f + 200, LVL_Y_LIMIT / 2.f + 200);
			HN.setPosition(LVL_X_LIMIT / 2.f + 200, 300);
			
			movePlayer(elapsed,500,0,MENU_X_LIMIT,MENU_Y_LIMIT + 500);
			nextSpawn.setTot(100);
			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[0]) {
					wait.add(elapsed.asMilliseconds());
					//cout << wait.get() << endl;
				}
				else {
					wait.set(0);
					isIn[0] = true;
				}
				if (wait.get() >= 2000) {
					setScreen(0);
					setResetPos(false);
				}
			}
			else isIn[0] = false;
			if (player.getPos().y < LVL_Y_LIMIT / 2.f) {
				nextSpawn.add(elapsed.asMilliseconds());
				if (vz.size() < 5 && nextSpawn.isFull()) {
					FlyingEye.setPos(Vector2f(SS.getPos().x, SS.getPos().y));
					FlyingEye.randomAnimation();
					vz.push_back(FlyingEye);
					nextSpawn.loop();
				}
			}

			if (DT.isCollided(player, DT.getSize().x, DT.getSize().y, false)) {
				lifes = MAX_LIFES;
				setScreen(5);
				vz.erase(remove_if(vz.begin(), vz.end(), [](Character& p) {return true; }), vz.end());
				nextSpawn.setTot(SPAWN_SPEED);
				setResetPos(false);
			}

			if (SS.isCollided(player, SS.getSize().x, SS.getSize().y, false)) {
				setScreen(6);
				vz.erase(remove_if(vz.begin(), vz.end(), [](Character& p) {return true; }), vz.end());
				nextSpawn.setTot(SPAWN_SPEED);
				tryed = false;
				tryAgain = false;
				BOSS.init(BOSS.getPos(), Animator(200, Vector2f(0, 0), Vector2f(176, 176), texManager.get(AVATAR[skinBoss] + "BOSS"+ "1"), Vector2i(6,1)));
				chaos = 0;
				setResetPos(false);
			}
			for(Character& z:vz) {
				if (z.intersects(&player) && z.useDmg())
				{
					player.setPos(Vector2f(LVL_X_LIMIT / 2.f + 200, LVL_Y_LIMIT / 2.f + 250));
					soundDead.play();
				}
				z.look(player.getPos());
				z.moveFwd();
				z.update(elapsed);
			}

			// Draw
			window.draw(floor);
			window.draw(HN);
			window.draw(DN);
			SS.draw(window);
			DT.draw(window);
			doormat.draw(window);
			player.draw(window);
			for(Character& z:vz) {
				z.draw(window);
			}
			break;
		case 5: // Play Easy Mode
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f - 50, LVL_Y_LIMIT / 2.f - 50));
				lastSeason = -1;
				setResetPos(true);
			}
			soundHardMode.stop();
			if (SoundSource::Status::Playing != soundEasyMode.getStatus()) {
				soundEasyMode.play();
			}
			soundCook.stop();
			texManager.get("floor")->setRepeated(true);
			floor.setTexture(*texManager.get("floor"));

			nextSpawn.add(elapsed.asMilliseconds());

			if (nextSpawn.isFull())
			{
				nextSpawn.loop();
				if (vz.size() < max_mons)
				{
					kind = rand() % 5;
					edge = rand() % 4;
					switch (edge)
					{
					case 0:
						x = view.getCenter().x - view.getSize().x;
						y = rand() % 500 - 1000 + view.getCenter().y;
						break;
					case 1:
						x = rand() % 750 - 1500 + view.getCenter().x;
						y = view.getCenter().y - view.getSize().y;
						break;
					case 2:
						x = view.getCenter().x + view.getSize().x;
						y = rand() % 500 - 1000 + view.getCenter().y;
						break;
					case 3:
						x = rand() % 750 - 1500 + view.getCenter().x;
						y = view.getCenter().y + view.getSize().y;
						break;
					default:
						break;
					}

					switch (kind)
					{
					case 0: 
						BigMonster.setPos(Vector2f((float)x, (float)y));
						BigMonster.randomAnimation();
						vz.push_back(BigMonster);
						break;
					case 1:
						FlyingEye.setPos(Vector2f((float)x, (float)y));
						FlyingEye.randomAnimation();
						vz.push_back(FlyingEye);
						break;
					case 2: 
						Goblin.setPos(Vector2f((float)x, (float)y));
						Goblin.randomAnimation();
						vz.push_back(Goblin);
						break;
					case 3: 
						Skeleton.setPos(Vector2f((float)x, (float)y)); //FIX
						Skeleton.randomAnimation();
						vz.push_back(Skeleton);
						break;
					case 4:
						if (buff_count >= BUFF_ENTITY) {
							break;
						}
						edge = rand() % 4;
						switch (edge)
						{
						case 0:
							x = rand() % 300 - player.getPos().x;
							y = rand() % 300 - player.getPos().y;
							break;
						case 1:
							x = rand() % 300 + player.getPos().x;
							y = rand() % 300 - player.getPos().y;
							break;
						case 2:
							x = rand() % 300 - player.getPos().x;
							y = rand() % 300 + player.getPos().y;
							break;
						case 3:
							x = rand() % 300 + player.getPos().x;
							y = rand() % 300 + player.getPos().y;
							break;
						default:
							break;
						}
						buff_count++;
						kind = rand() % 3;

						switch (kind)
						{
						case 0:
							heal.setPos(Vector2f((float)x, (float)y));
							//std::cout<<"Heal"<<endl;
							vz.push_back(heal);
							break;
						case 1:
							dmg.setPos(Vector2f((float)x, (float)y));
							vz.push_back(dmg);
							//std::cout<<"Dmg"<<endl;

							break;
						case 2:
							speed.setPos(Vector2f((float)x, (float)y));
							vz.push_back(speed);
							//std::cout<<"Speed"<<endl;

							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
				}
			}

			movePlayerObstacle(elapsed, 0, 0, LVL_X_LIMIT, LVL_Y_LIMIT, obstacles);
			if (player.getPos().x < LVL_X_LIMIT / 2.f && player.getPos().y < LVL_Y_LIMIT / 2.f && lastSeason != 0) {
				player.setCoolDown(player.getCoolDown() - SEASON_COOLDOWN);
				if (lastSeason == 1) {
					player.setMaxSpeed(player.getMaxSpeed() - SEASON_SPEED);
				}
				else if (lastSeason == 2) {
					player.increaseHp(-SEASON_HP);
				}
				else if (lastSeason == 3) {
					player.setCoolDown(player.getCoolDown() - SEASON_COOLDOWN);
					player.setMaxSpeed(player.getMaxSpeed() + SEASON_SPEED);
				}
				lastSeason = 0;
			}
			if (player.getPos().x > LVL_X_LIMIT / 2.f && player.getPos().y < LVL_Y_LIMIT / 2.f && lastSeason != 1) {
				player.setMaxSpeed(player.getMaxSpeed() + SEASON_SPEED);
				if (lastSeason == 0) {
					player.setCoolDown(player.getCoolDown() + SEASON_COOLDOWN);
				}
				else if (lastSeason == 2) {
					player.increaseHp(-SEASON_HP);
				}
				else if (lastSeason == 3) {
					player.setCoolDown(player.getCoolDown() - SEASON_COOLDOWN);
					player.setMaxSpeed(player.getMaxSpeed() + SEASON_SPEED);
				}
				lastSeason = 1;
			}
			if (player.getPos().x < LVL_X_LIMIT / 2.f && player.getPos().y > LVL_Y_LIMIT / 2.f && lastSeason != 2) {
				player.increaseHp(SEASON_HP);
				if (lastSeason == 1) {
					player.setMaxSpeed(player.getMaxSpeed() - SEASON_SPEED);
				}
				else if (lastSeason == 0) {
					player.setCoolDown(player.getCoolDown() + SEASON_COOLDOWN);
				}
				else if (lastSeason == 3) {
					player.setCoolDown(player.getCoolDown() - SEASON_COOLDOWN);
					player.setMaxSpeed(player.getMaxSpeed() + SEASON_SPEED);
				}
				lastSeason = 2;
			}
			if (player.getPos().x > LVL_X_LIMIT / 2.f && player.getPos().y > LVL_Y_LIMIT / 2.f && lastSeason != 3) {
				player.setCoolDown(player.getCoolDown() + SEASON_COOLDOWN);
				player.setMaxSpeed(player.getMaxSpeed() - SEASON_SPEED);
				if (lastSeason == 0) {
					player.setCoolDown(player.getCoolDown() + SEASON_COOLDOWN);
				}
				else if (lastSeason == 2) {
					player.increaseHp(-SEASON_HP);
				}
				else if (lastSeason == 1) {
					player.setMaxSpeed(player.getMaxSpeed() - SEASON_SPEED);
				}
				lastSeason = 3;
			}

			for (Projectile& p : vp)
			{
				for (Character& z : vz)
				{
					if (z.getType() >= 4)
						continue;
					if (p.intersects(&z))
					{
						int miss = rand() % 100;
						if (miss > missRate * 100) {
							int crit = rand() % 100;
							vHitEffect.push_back(Animation(z.getPos(), Animator(50, Vector2f(0, 0), Vector2f(128, 128), texManager.get("hitEffect"), Vector2i(5, 1))));
							if (crit <= critRate * 100) {
								z.damage(player.getCriticalDmg());
								//p.destroy();
								if (z.isDead())
								{
									vDeadEffect.push_back(Animation(z.getPos(), Animator(100, Vector2f(0, 0), Vector2f(64, 64), texManager.get("deadEffect"), Vector2i(8, 1))));
									t.init("CRITICAL DEATH", z.getPos(), 50);
									vt.push_back(t);
									t.setSize(20);
								}
								else
								{
									t.init("CRIT", z.getPos());
									vt.push_back(t);
								}
							}
							else {
								z.damage(player.getWeaponDmg());
								p.destroy();
								if (z.isDead())
								{
									vDeadEffect.push_back(Animation(z.getPos(), Animator(70, Vector2f(0, 0), Vector2f(64, 64), texManager.get("deadEffect"), Vector2i(8, 1))));
									/*t.init("DEAD", z.getPos(),50);
									vt.push_back(t);*/
								}
								else
								{
									t.init("HIT", z.getPos(), 20);
									vt.push_back(t);
								}
							}
						}
						else {
							p.destroy();
							t.init("MISS", z.getPos());
							vt.push_back(t);
						}

					}
				}
			}

			vz.erase(remove_if(vz.begin(), vz.end(), [&points, &lvlUp, &buff_count](Character& p) {
				if (p.isDead())
				{
					if (p.getType() >= 4) {
						buff_count--;
						return p.isDead();
					}
					points++;
					//lvlUp = true;
					if (points % 5 == 0)
					{
						lvlUp = true;
					}
				} return p.isDead();
			}), vz.end());

			if (lvlUp)
			{
				if (player.getCoolDown() > 150) player.setCoolDown(player.getCoolDown() - player.getCoolDown() * COOLDOWN_CHANGE);
				if (player.getTotHp() < 150) player.increaseHp(5); //FIX
				if (player.getHp() < player.getTotHp()) player.heal(player.getTotHp() * 0.1f);
				if (max_mons < 25) max_mons += max_mons * 0.2;
				if (critRate < 0.7) critRate += CRIT_CHANGE * (1 - critRate); //FIX
				if (missRate > 0.1) missRate -= MISS_CHANGE * missRate;
				if (lvl > 5) {
					BigMonster.setFull(BigMonster.getTotHp() * POWER_MULTIPLY);
					BigMonster.setDmg(BigMonster.getDmg() * POWER_MULTIPLY);
					FlyingEye.setFull(FlyingEye.getTotHp() * POWER_MULTIPLY);
					FlyingEye.setDmg(FlyingEye.getDmg() * POWER_MULTIPLY);
					Goblin.setFull(Goblin.getTotHp() * POWER_MULTIPLY);
					Goblin.setDmg(Goblin.getDmg() * POWER_MULTIPLY);
					Skeleton.setFull(Skeleton.getTotHp() * POWER_MULTIPLY);
					Skeleton.setDmg(Skeleton.getDmg() * POWER_MULTIPLY);
				}
				lvl++;
				t.init("LEVEL UP", player.getPos());
				vt.push_back(t);
				lvlUp = false;
			}
			for (int k = 0; k < vz.size(); k++)
			{
				lastDir = vz[k].getDir();
				vz[k].look(player.getPos());
				bool fwd = true;
				for (Obstacle& tree : obstacles) {
					if (!tree.isCollided(vz[k], tree.getSize().x, tree.getSize().x, false)) continue;
					else
					{
						fwd = false;
					}
				}
				if (fwd) vz[k].moveFwd();
				else vz[k].moveBwd();
				vz[k].update(elapsed);
				if (vz[k].getAngle() <= 180) {
					vz[k].setDir(0);
				}
				else {
					vz[k].setDir(1);
				}
				if (vz[k].getDir() == 0 && lastDir == 1) {
					vz[k].init(vz[k].getPos(), Animator(200, Vector2f(0, 0), Vector2f(MONS_SIZE[vz[k].type][0], MONS_SIZE[vz[k].type][1]), texManager.get(MONS_NAME[vz[k].type][0]), Vector2i(4, 1)));
				}
				else if (vz[k].getDir() == 1 && lastDir == 0) {
					vz[k].init(vz[k].getPos(), Animator(200, Vector2f(0, 0), Vector2f(MONS_SIZE[vz[k].type][0], MONS_SIZE[vz[k].type][1]), texManager.get(MONS_NAME[vz[k].type][1]), Vector2i(4, 1)));
				}
			}

			for (Character& z : vz)
			{
				if (z.intersects(&player) && z.useDmg())
				{
					if (z.getType() == 4) {
						z.damage(10000);
						//buff_duration.init(5000);
						t.init("HEAL", player.getPos(), 50);
						player.damage(z.getDmg());

						vt.push_back(t);
						continue;
					}
					else if (z.getType() == 5) {
						z.damage(10000);
						buff_duration.setFull();
						player.weapon.setDmg(player.weapon.getDmg() * 2);
						buff_duration_bar.setFillColor(Color::Red);
						t.init("BUFF DMG", player.getPos(), 50);
						vt.push_back(t);
						continue;
					}
					else if (z.getType() == 6) {
						z.damage(10000);
						buff_duration.setFull();
						player.setMaxSpeed(1);
						buff_duration_bar.setFillColor(Color::Yellow);
						t.init("SPEED UP", player.getPos(), 50);
						vt.push_back(t);
						continue;
					}
					if (!godMode) {
						player.damage(z.getDmg());
					}
					soundDead.play();
					t.init("OUCH", player.getPos());
					vt.push_back(t);
				}
			}

			life.setString("HP: " + to_string(player.getHp()) + "\nKILLS: " + to_string(points) + "\nLEVEL: " + to_string(lvl) + "\nTOTAL ZOMBIES: " + to_string(vz.size()) +
				"\nFPS: " + to_string((int)(1.f / elapsed.asSeconds())));

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (player.useDmg())
				{
					soundAWM.play();

					p.init(player.getPos(), player.getAngle() - 90, 2.0f, 1200, texManager.get("bullet"),0);
					shootEffect.init(player.getPos(), Vector2f(32, 32), player.getAngle() - 90, 0.5, 100, texManager.get("shootEffect"));
					player.jetForce();
					vp.push_back(p);
					vef.push_back(shootEffect);
				}
			}

			for (Animation& p : vDeadEffect)
			{
				p.update(elapsed);
			}
			for (Animation& p : vHitEffect)
			{
				p.update(elapsed);
			}
			for (Projectile& p : vp)
			{
				p.update(elapsed);

			}
			for (Projectile& ef : vef)
			{
				ef.update(elapsed);
			}
			vHitEffect.erase(remove_if(vHitEffect.begin(), vHitEffect.end(), [](Animation& p) {return p.isEnd(); }), vHitEffect.end());
			vDeadEffect.erase(remove_if(vDeadEffect.begin(), vDeadEffect.end(), [](Animation& p) {return p.isEnd(); }), vDeadEffect.end());
			vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return p.isDestroyed(); }), vp.end());
			vef.erase(remove_if(vef.begin(), vef.end(), [](Projectile& p) {return p.isDestroyed(); }), vef.end());
			cursor.update();
			cursor.setColor(Color::Red);

			life.setPosition(view.getCenter() - view.getSize() / 2.f);

			//player.look((Vector2f)Mouse::getPosition(window) + view.getCenter() - view.getSize() / 2.f);

			for (FloatingText& f : vt)
			{
				f.update(elapsed);
			}

			vt.erase(remove_if(vt.begin(), vt.end(), [](FloatingText& f) {return f.isDestroyed(); }), vt.end());

			window.draw(floorSpring);
			window.draw(floorSummer);
			window.draw(floorAutumn);
			window.draw(floorWinter);

			for (Projectile& p : vp)
				p.draw(window);

			for (Projectile& ef : vef)
				ef.draw(window);

			for (Animation& p : vDeadEffect)
			{
				p.draw(window);
			}
			for (Animation& p : vHitEffect)
			{
				p.draw(window);
			}
			player.draw(window, player.getHpRect(), player.getOriginHpRect());
			player.weapon.draw(window);

			for (Character& z : vz)
				z.draw(window, z.getHpRect(), z.getOriginHpRect());
			for (FloatingText& f : vt)
				window.draw(f);
			for (Obstacle& tree : obstacles){
				if((tree.getPos().x > player.getPos().x - view.getSize().x / 2.f && tree.getPos().x < player.getPos().x + view.getSize().x / 2.f) && (tree.getPos().y > player.getPos().y - view.getSize().y / 2.f && tree.getPos().y < player.getPos().y + view.getSize().y / 2.f)) {
					tree.draw(window);
				}
			}
			if (buff_duration.isEmpty() == 0 ){
				//std::cout <<  buff_duration.get() << endl;
				buff_duration.add(- elapsed.asMilliseconds());
				buff_duration_bar.setSize(Vector2f(buff_duration.getPerc()*4,50));
				buff_duration_bar.setPosition(Vector2f(view.getCenter().x - view.getSize().x / 2.0f + 20 , view.getCenter().y + view.getSize().y / 2.0f - 70 ));
				window.draw(buff_duration_bar);
			}else{
				player.weapon.setDmg(WEAPON_DMG[player.weapon.type]);
				player.setMaxSpeed(0.4);
			}
			window.draw(life);
			for(int i=0; i<lifes; i++) {
				hearts[i].setPosition(view.getCenter().x + view.getSize().x / 2.f - 40 * (i+1), view.getCenter().y - view.getSize().y / 2.f + 30);
				window.draw(hearts[i]);
			}

			if (player.isDead())
			{
				lifes --;
				player.setFull(player.getTotHp());
				if (lifes <= 0) {
					setScreen(7);
					setResetPos(false);
				}
			}
			break;
		case 6: // Play Hard Mode
			soundEasyMode.stop();
			if (SoundSource::Status::Playing != soundHardMode.getStatus() && !tryed) {
				soundHardMode.play();
				soundCook.stop();
			}
			if (defaultTime == -1) {
				std::time_t t = std::time(0);
				std::tm* now = std::localtime(&t);
				if (now->tm_hour < 12) {
					defaultTime = 0;
				}
				else if (now->tm_hour < 19) {
					defaultTime = 1;
				}
				else if (now->tm_hour <= 24) {
					defaultTime = 2;
				}
			}
			texManager.get(ITEM_HARD_NAME[defaultTime][0])->setRepeated(true);
			floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT));
			floor.setTexture(*texManager.get(ITEM_HARD_NAME[defaultTime][0]));
			floor.setPosition(500, 500);
			treeDay[0].init(Vector2f(LVL_X_LIMIT / 2.f - 300, LVL_Y_LIMIT / 2.f - 300), Animator(1, Vector2f(0,0), Vector2f(80,96), texManager.get(ITEM_HARD_NAME[defaultTime][1]), Vector2i(1,1)));
			treeDay[1].init(Vector2f(LVL_X_LIMIT / 2.f + 300, LVL_Y_LIMIT / 2.f + 300), Animator(1, Vector2f(0,0), Vector2f(80,96), texManager.get(ITEM_HARD_NAME[defaultTime][1]), Vector2i(1,1)));
			treeDay[2].init(Vector2f(LVL_X_LIMIT / 2.f - 300, LVL_Y_LIMIT / 2.f + 300), Animator(1, Vector2f(0,0), Vector2f(80,96), texManager.get(ITEM_HARD_NAME[defaultTime][1]), Vector2i(1,1)));
			treeDay[3].init(Vector2f(LVL_X_LIMIT / 2.f + 300, LVL_Y_LIMIT / 2.f - 300), Animator(1, Vector2f(0,0), Vector2f(80,96), texManager.get(ITEM_HARD_NAME[defaultTime][1]), Vector2i(1,1)));
			item1.setTexture(*texManager.get(ITEM_HARD_NAME[defaultTime][2]));
			item1.setPosition(LVL_X_LIMIT / 2.f + 100, LVL_Y_LIMIT / 2.f - 200);
			item2.setTexture(*texManager.get(ITEM_HARD_NAME[defaultTime][3]));
			item2.setPosition(LVL_X_LIMIT / 2.f - 150, LVL_Y_LIMIT / 2.f + 150);
			
			movePlayerObstacle(elapsed, 500, 500, MENU_X_LIMIT, MENU_Y_LIMIT, treeDay);
			nextSpawn.add(elapsed.asMilliseconds());

			if (nextSpawn.isFull())
			{
				nextSpawn.loop();
				if (vz.size() < max_mons)
				{
					kind = rand() % 4;
					switch (kind)
					{
					case 0: 
						BigMonster.setPos(BOSS.getPos());
						BigMonster.randomAnimation();
						vz.push_back(BigMonster);
						break;
					case 1:
						FlyingEye.setPos(BOSS.getPos());
						FlyingEye.randomAnimation();
						vz.push_back(FlyingEye);
						break;
					case 2: 
						Goblin.setPos(BOSS.getPos());
						Goblin.randomAnimation();
						vz.push_back(Goblin);
						break;
					case 3: 
						Skeleton.setPos(BOSS.getPos()); //FIX
						Skeleton.randomAnimation();
						vz.push_back(Skeleton);
						break;
					}
				}
			}
			for (Projectile& p : vp)
			{
				for (Character& z : vz)
				{
					if (p.getType() == 1)
						continue;
					if (z.getType() >= 4)
						continue;
					if (p.intersects(&z))
					{
						int miss = rand() % 100;
						if (miss > missRate * 100) {
							int crit = rand() % 100;
							vHitEffect.push_back(Animation(z.getPos(), Animator(50, Vector2f(0, 0), Vector2f(128, 128), texManager.get("hitEffect"), Vector2i(5, 1))));
							if (crit <= critRate * 100) {
								z.damage(player.getCriticalDmg());
								//p.destroy();
								if (z.isDead())
								{
									vDeadEffect.push_back(Animation(z.getPos(), Animator(100, Vector2f(0, 0), Vector2f(64, 64), texManager.get("deadEffect"), Vector2i(8, 1))));
									t.init("CRITICAL DEATH", z.getPos(), 50);
									vt.push_back(t);
									t.setSize(20);
								}
								else
								{
									t.init("CRIT", z.getPos());
									vt.push_back(t);
								}
							}
							else {
								z.damage(player.getWeaponDmg());
								p.destroy();
								if (z.isDead())
								{
									vDeadEffect.push_back(Animation(z.getPos(), Animator(70, Vector2f(0, 0), Vector2f(64, 64), texManager.get("deadEffect"), Vector2i(8, 1))));
									/*t.init("DEAD", z.getPos(),50);
									vt.push_back(t);*/
								}
								else
								{
									t.init("HIT", z.getPos(), 20);
									vt.push_back(t);
								}
							}
						}
						else {
							p.destroy();
							t.init("MISS", z.getPos());
							vt.push_back(t);
						}
					}
				}
			}

			for (Projectile& p : vp)
			{
				if (p.getType() == 0 && p.intersects(&BOSS)){
					BOSS.damage(player.getWeaponDmg());
					p.destroy();
				}else if (p.getType() == 1 && p.intersects(&player)){
					if (!godMode) player.damage(player.getCriticalDmg());
					p.destroy();
				}
			}

			vz.erase(remove_if(vz.begin(), vz.end(), [&points, &lvlUp, &buff_count](Character& p) {
				if (p.isDead())
				{
					if (p.getType() >= 4) {
						buff_count--;
						return p.isDead();
					}
					points++;
					//lvlUp = true;
					if (points % 5 == 0)
					{
						lvlUp = true;
					}
				} return p.isDead();
			}), vz.end());

			if (lvlUp)
			{
				player.setCoolDown(player.getCoolDown() - player.getCoolDown() * COOLDOWN_CHANGE);
				player.increaseHp(5); //FIX
				player.heal(player.getTotHp() * 0.1f);
				max_mons += max_mons * 0.2;
				if (max_mons > 10) max_mons = 10;
				if (critRate < 1) critRate += CRIT_CHANGE * (1 - critRate); //FIX
				if (missRate > 0) missRate -= MISS_CHANGE * missRate;
				lvl++;
				t.init("LEVEL UP", player.getPos());
				vt.push_back(t);
				lvlUp = false;
			}
			int lastDir;
			for (int k = 0; k < vz.size(); k++)
			{
				lastDir = vz[k].getDir();
				vz[k].look(player.getPos());
				bool fwd = true;
				for (Obstacle& tree : treeDay) {
					if (!tree.isCollided(vz[k], tree.getSize().x, tree.getSize().x, false)) continue;
					else
					{
						fwd = false;
					}
				}
				if (fwd) vz[k].moveFwd();
				else vz[k].moveBwd();
				vz[k].update(elapsed);
				if (vz[k].getAngle() <= 180) {
					vz[k].setDir(0);
				}
				else {
					vz[k].setDir(1);
				}
				if (vz[k].getDir() == 0 && lastDir == 1) {
					vz[k].init(vz[k].getPos(), Animator(200, Vector2f(0, 0), Vector2f(MONS_SIZE[vz[k].type][0], MONS_SIZE[vz[k].type][1]), texManager.get(MONS_NAME[vz[k].type][0]), Vector2i(4, 1)));
				}
				else if (vz[k].getDir() == 1 && lastDir == 0) {
					vz[k].init(vz[k].getPos(), Animator(200, Vector2f(0, 0), Vector2f(MONS_SIZE[vz[k].type][0], MONS_SIZE[vz[k].type][1]), texManager.get(MONS_NAME[vz[k].type][1]), Vector2i(4, 1)));
				}
			}

			BOSS.look(player.getPos());
			BOSS.moveFwd();
			BOSS.update(elapsed);

			for (Character& z : vz)
			{
				if (z.intersects(&player) && z.useDmg())
				{

					if (!godMode) {
						player.damage(z.getDmg());
						if (z.getType() == 4) {
							z.damage(10000);
							//buff_duration.init(5000);
							t.init("HEAL", player.getPos(), 50);
							vt.push_back(t);
							continue;
						}
						else if (z.getType() == 5) {
							z.damage(10000);
							buff_duration.setFull();
							player.weapon.setDmg(player.weapon.getDmg() * 2);
							buff_duration_bar.setFillColor(Color::Red);
							t.init("BUFF DMG", player.getPos(), 50);
							vt.push_back(t);
							continue;
						}
						else if (z.getType() == 6) {
							z.damage(10000);
							buff_duration.setFull();
							player.setMaxSpeed(1);
							buff_duration_bar.setFillColor(Color::Yellow);
							t.init("SPEED UP", player.getPos(), 50);
							vt.push_back(t);
							continue;
						}
					}
					soundDead.play();
					t.init("OUCH", player.getPos());
					vt.push_back(t);
				}
			}

			life.setString("HP: " + to_string(player.getHp()) + "\nKILLS: " + to_string(points) + "\nLEVEL: " + to_string(lvl) + "\nTOTAL ZOMBIES: " + to_string(vz.size()) +
				"\nFPS: " + to_string((int)(1.f / elapsed.asSeconds())));

			if (BOSS.useDmg() && deadMode == 0){
				p.init(BOSS.getPos(), BOSS.getAngle() - 90, 1.3f, 1000, texManager.get("boss_bullet"), 1);
				vp.push_back(p);
				p.init(BOSS.getPos(), rand() % 360, 0.15f, 10000, texManager.get("boss_bullet"), 1);
				vp.push_back(p);
				p.init(BOSS.getPos(), rand() % 360, 0.15f, 10000, texManager.get("boss_bullet"), 1);
				vp.push_back(p);
				p.init(BOSS.getPos(), rand() % 360, 0.15f, 10000, texManager.get("boss_bullet"), 1);
				vp.push_back(p);
				p.init(BOSS.getPos(), rand() % 360, 0.15f, 10000, texManager.get("boss_bullet"), 1);
				vp.push_back(p);
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (player.useDmg())
				{
					soundAWM.play();

					p.init(player.getPos(), player.getAngle() - 90, 1.0f, 500, texManager.get("bullet"), 0);
					shootEffect.init(player.getPos(), Vector2f(32, 32), player.getAngle() - 90, 0.5, 100, texManager.get("shootEffect"));
					player.jetForce();
					vp.push_back(p);
					vef.push_back(shootEffect);
				}
			}
			for (Animation& p : vDeadEffect)
			{
				p.update(elapsed);
			}
			for (Animation& p : vHitEffect)
			{
				p.update(elapsed);
			}
			for (Projectile& p : vp)
			{
				p.update(elapsed);

			}
			for (Projectile& ef : vef)
			{
				ef.update(elapsed);
			}
			vHitEffect.erase(remove_if(vHitEffect.begin(), vHitEffect.end(), [](Animation& p) {return p.isEnd(); }), vHitEffect.end());
			vDeadEffect.erase(remove_if(vDeadEffect.begin(), vDeadEffect.end(), [](Animation& p) {return p.isEnd(); }), vDeadEffect.end());
			vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return p.isDestroyed(); }), vp.end());
			vef.erase(remove_if(vef.begin(), vef.end(), [](Projectile& p) {return p.isDestroyed(); }), vef.end());
			cursor.update();
			cursor.setColor(Color::Red);

			life.setPosition(view.getCenter() - view.getSize() / 2.f);

			//player.look((Vector2f)Mouse::getPosition(window) + view.getCenter() - view.getSize() / 2.f);

			for (FloatingText& f : vt)
			{
				f.update(elapsed);
			}

			vt.erase(remove_if(vt.begin(), vt.end(), [](FloatingText& f) {return f.isDestroyed(); }), vt.end());

			window.draw(floor);
			window.draw(item1);
			window.draw(item2);
			for (Projectile& p : vp)
				if (p.getPos().x > 500 + MENU_X_LIMIT || p.getPos().x < 500 || p.getPos().y > 500 + MENU_Y_LIMIT || p.getPos().y < 500) p.destroy();
				else p.draw(window);

			for (Projectile& ef : vef)
				if (p.getPos().x > 500 + MENU_X_LIMIT || p.getPos().x < 500 || p.getPos().y > 500 + MENU_Y_LIMIT || p.getPos().y < 500) p.destroy();
				else ef.draw(window);

			for (Animation& p : vDeadEffect)
			{
				if (p.getPos().x > 500 + MENU_X_LIMIT || p.getPos().x < 500 || p.getPos().y > 500 + MENU_Y_LIMIT || p.getPos().y < 500) continue;
				p.draw(window);
			}
			for (Animation& p : vHitEffect)
			{
				if (p.getPos().x > 500 + MENU_X_LIMIT || p.getPos().x < 500 || p.getPos().y > 500 + MENU_Y_LIMIT || p.getPos().y < 500) continue;
				p.draw(window);
			}
			player.draw(window, player.getHpRect(), player.getOriginHpRect());
			player.weapon.draw(window);
			//std::cout << BOSS.getPos().x << " - " << BOSS.getPos().y << endl;
			BOSS.draw(window, BOSS.getHpRect(), BOSS.getOriginHpRect());
			for (Character& p : vz) {
				if (p.getPos().x > 500 + MENU_X_LIMIT || p.getPos().x < 500 || p.getPos().y > 500 + MENU_Y_LIMIT || p.getPos().y < 500) continue;
				p.draw(window, p.getHpRect(), p.getOriginHpRect());
			}
			for (FloatingText& f : vt)
				window.draw(f);
			for (Obstacle& tree : treeDay) {
				tree.draw(window);
			}
			if (buff_duration.isEmpty() == 0) {
				//std::cout <<  buff_duration.get() << endl;
				buff_duration.add(-elapsed.asMilliseconds());
				buff_duration_bar.setSize(Vector2f(buff_duration.getPerc() * 4, 50));
				buff_duration_bar.setPosition(Vector2f(view.getCenter().x - view.getSize().x / 2.0f + 20, view.getCenter().y + view.getSize().y / 2.0f - 70));
				window.draw(buff_duration_bar);
			}
			else {
				player.weapon.setDmg(WEAPON_DMG[player.weapon.type]);
				player.setMaxSpeed(0.4);
			}
			window.draw(life);
			if (BOSS.isDead() && chaos == 1)
			{
				BOSS.init(BOSS.getPos(), Animator(200, Vector2f(0, 0), Vector2f(176, 176), texManager.get(AVATAR[skinBoss] + "BOSS"+ "1"), Vector2i(6,1)));
				chaos = 0;
				setScreen(10);
				break;
			}
			if (BOSS.isDead())
			{
				BOSS.init(BOSS.getPos(), Animator(200, Vector2f(0, 0), Vector2f(176, 176), texManager.get(AVATAR[skinBoss + 4 ] + "BOSS"+ "1"), Vector2i(6,1)));
				BOSS.setFull(BOSS_HP * 2);
				BOSS.setCoolDown(BOSS_COOLDOWN / 4.f);
				BOSS.setMaxSpeed(BOSS_SPEED * 3);
				chaos = 1;
				BOSS.setFull(BOSS.getTotHp());
			}

			if (player.isDead())
			{
				setScreen(8);
				letHimCook.set(0);
				setResetPos(false);
			}
			break;
		case 7: // Death Normal
			window.draw(c);
			endLife.setString("YOU ARE DEAD");
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(200);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(view.getCenter().x, view.getCenter().y - 100);
			window.draw(endLife);
			endLife.setString("Your points is: " + to_string(points));
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(30);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 100));
			window.draw(endLife);
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				soundEasyMode.stop();
				soundHardMode.stop();
				missRate = MISS_RATE;
				critRate = CRIT_RATE;
				max_mons = MAX_MONS;
				BOSS.setFull(BOSS_HP);
				BOSS.setCoolDown(BOSS_COOLDOWN);
				BOSS.setMaxSpeed(BOSS_SPEED);
				vz.clear();
				vt.clear();
				vHitEffect.clear();
				vHitEffect.clear();
				vp.clear();
				vef.clear();
				vt.erase(remove_if(vt.begin(), vt.end(), [](FloatingText& f) {return true; }), vt.end());
				vz.erase(remove_if(vz.begin(), vz.end(), [](Character& p) {return true; }), vz.end());
				vHitEffect.erase(remove_if(vHitEffect.begin(), vHitEffect.end(), [](Animation& p) {return true; }), vHitEffect.end());
				vDeadEffect.erase(remove_if(vDeadEffect.begin(), vDeadEffect.end(), [](Animation& p) {return true; }), vDeadEffect.end());
				vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return true; }), vp.end());
				vef.erase(remove_if(vef.begin(), vef.end(), [](Projectile& p) {return true; }), vef.end());
				BigMonster.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[0][0], MONS_SIZE[0][1]), texManager.get(MONS_NAME[BigMonster.type][0]), Vector2i(1, 1)));
				BigMonster.setDmg(10);
				BigMonster.setMaxSpeed(0.3);
				BigMonster.setFull(50);
				BigMonster.setCoolDown(1000);

				FlyingEye.init(Vector2f(0, 0), Animator(100, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[1][0], MONS_SIZE[1][1]), texManager.get(MONS_NAME[FlyingEye.type][0]), Vector2i(1, 1)));
				FlyingEye.setDmg(10);
				FlyingEye.setMaxSpeed(0.8);
				FlyingEye.setFull(20);
				FlyingEye.setCoolDown(1200);

				Goblin.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[2][0], MONS_SIZE[2][1]), texManager.get(MONS_NAME[Goblin.type][0]), Vector2i(1, 1)));
				Goblin.setDmg(20);
				Goblin.setMaxSpeed(0.3);
				Goblin.setFull(30);
				Goblin.setCoolDown(500);

				Skeleton.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[3][0], MONS_SIZE[3][1]), texManager.get(MONS_NAME[Skeleton.type][0]), Vector2i(1, 1)));
				Skeleton.setDmg(100);
				Skeleton.setMaxSpeed(0.15);
				Skeleton.setFull(150);
				Skeleton.setCoolDown(500);

				heal.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[heal.type][0]), Vector2i(1, 1)));
				heal.setDmg(-20);
				heal.setMaxSpeed(0.01);
				heal.setFull(5000);
				heal.setCoolDown(10);

				dmg.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[dmg.type][0]), Vector2i(1, 1)));
				dmg.setDmg(0);
				dmg.setMaxSpeed(0.01);
				dmg.setFull(5000);
				dmg.setCoolDown(10);

				speed.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[speed.type][0]), Vector2i(1, 1)));
				speed.setDmg(0);
				speed.setMaxSpeed(0.01);
				speed.setFull(5000);
				speed.setCoolDown(10);
				player.setMaxSpeed(PLAYER_SPEED);
				player.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6,1))); // FIX
				player.setCoolDown(INIT_COOLDOWN);
				player.setFull(INIT_HP);
				bazoka = Weapon(2);
				bazoka.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("bazoka"), Vector2i(1, 1)));
				bazoka.setCoolDown(INIT_COOLDOWN);
				AWM = Weapon(1);
				AWM.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("AWM"), Vector2i(4, 1)));
				AWM.setCoolDown(INIT_COOLDOWN);
				shortGun = Weapon(0);
				shortGun.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("shortGun"), Vector2i(4, 1)));
				shortGun.setCoolDown(INIT_COOLDOWN);
				lvl = 1;
				setScreen(0);
				setResetPos(false);
			}
			break;
		case 8: // Death Hard
			window.draw(c);
			endLife.setString("MORE EFFORT!!!");
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(200);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(view.getCenter().x, view.getCenter().y - 100);
			window.draw(endLife);
			endLife.setString("Your points is: " + to_string(points));
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(30);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 100));
			window.draw(endLife);
			if (!tryed) {
				endLife.setString("Press [R] to Retry or [Enter] to Return to Menu");
				endLife.setFillColor(Color::White);
				endLife.setCharacterSize(40);
				textRect = endLife.getLocalBounds();
				endLife.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 200));
				window.draw(endLife);
				if (Keyboard::isKeyPressed(Keyboard::R)) {
					if (SoundSource::Status::Playing != soundCook.getStatus()) {
						soundCook.play();
						soundCook.setLoop(1);
						soundHardMode.stop();
						soundEasyMode.stop();
					}
					tryAgain = true;
				}
				if (tryAgain) {
					window.draw(c);
					letHimCook.add(elapsed.asMilliseconds());
				}
				for (Projectile& p : vp) {
					p.destroy();
				}
				if (letHimCook.get() > 8000) {
					window.draw(c);
					endLife.setString("LET");
					endLife.setFillColor(Color::White);
					endLife.setCharacterSize(150);
					textRect = endLife.getLocalBounds();
					endLife.setOrigin(textRect.left + textRect.width / 2.0f,
						textRect.top + textRect.height / 2.0f);
					endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y));
					window.draw(endLife);
				}
				if (letHimCook.get() > 8650) {
					window.draw(c);
					endLife.setString("HIM");
					endLife.setFillColor(Color::White);
					endLife.setCharacterSize(300);
					textRect = endLife.getLocalBounds();
					endLife.setOrigin(textRect.left + textRect.width / 2.0f,
						textRect.top + textRect.height / 2.0f);
					endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y));
					window.draw(endLife);
				}
				if (letHimCook.get() > 9320) {
					window.draw(c);
					endLife.setString("COOK");
					endLife.setFillColor(Color::Red);
					endLife.setCharacterSize(550);
					textRect = endLife.getLocalBounds();
					endLife.setOrigin(textRect.left + textRect.width / 2.0f,
						textRect.top + textRect.height / 2.0f);
					endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y));
					window.draw(endLife);
				}
				if (letHimCook.isFull()) {
					setScreen(6);
					skin = skin + 4;
					player.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6,1))); // FIX
					//BOSS.init(Vector2f(600,600), Animator(200, Vector2f(0, 0), Vector2f(176, 176), texManager.get(AVATAR[skin + 4 ] + "BOSS"+ "1"), Vector2i(6,1))); // FIX
					if (!chaos) BOSS.setFull(BOSS.getTotHp() / 2.f);
					player.setFull(player.getTotHp());
					player.setFull(INIT_HP * 5);
					player.setCoolDown(INIT_COOLDOWN / 2.f);
					player.setMaxSpeed(PLAYER_SPEED * 3);
					tryed = true;
				}
			}
			else {
				if (tryAgain) {
					skin = skin - 4;
					tryAgain = false;
				}
				endLife.setString("Press [Enter] to Return to Menu");
				endLife.setFillColor(Color::White);
				endLife.setCharacterSize(40);
				textRect = endLife.getLocalBounds();
				endLife.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 200));
				window.draw(endLife);
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				soundCook.stop();
				soundHardMode.stop();
				missRate = MISS_RATE;
				critRate = CRIT_RATE;
				max_mons = MAX_MONS;
				BOSS.setFull(BOSS_HP);
				BOSS.setCoolDown(BOSS_COOLDOWN);
				BOSS.setMaxSpeed(BOSS_SPEED);
				vz.clear();
				vt.clear();
				vHitEffect.clear();
				vHitEffect.clear();
				vp.clear();
				vef.clear();
				vt.erase(remove_if(vt.begin(), vt.end(), [](FloatingText& f) {return true; }), vt.end());
				vz.erase(remove_if(vz.begin(), vz.end(), [](Character& p) {return true; }), vz.end());
				vHitEffect.erase(remove_if(vHitEffect.begin(), vHitEffect.end(), [](Animation& p) {return true; }), vHitEffect.end());
				vDeadEffect.erase(remove_if(vDeadEffect.begin(), vDeadEffect.end(), [](Animation& p) {return true; }), vDeadEffect.end());
				vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return true; }), vp.end());
				vef.erase(remove_if(vef.begin(), vef.end(), [](Projectile& p) {return true; }), vef.end());
				BigMonster.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[0][0], MONS_SIZE[0][1]), texManager.get(MONS_NAME[BigMonster.type][0]), Vector2i(1, 1)));
				BigMonster.setDmg(10);
				BigMonster.setMaxSpeed(0.3);
				BigMonster.setFull(50);
				BigMonster.setCoolDown(1000);

				FlyingEye.init(Vector2f(0, 0), Animator(100, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[1][0], MONS_SIZE[1][1]), texManager.get(MONS_NAME[FlyingEye.type][0]), Vector2i(1, 1)));
				FlyingEye.setDmg(10);
				FlyingEye.setMaxSpeed(0.8);
				FlyingEye.setFull(20);
				FlyingEye.setCoolDown(1200);

				Goblin.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[2][0], MONS_SIZE[2][1]), texManager.get(MONS_NAME[Goblin.type][0]), Vector2i(1, 1)));
				Goblin.setDmg(20);
				Goblin.setMaxSpeed(0.3);
				Goblin.setFull(30);
				Goblin.setCoolDown(500);

				Skeleton.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[3][0], MONS_SIZE[3][1]), texManager.get(MONS_NAME[Skeleton.type][0]), Vector2i(1, 1)));
				Skeleton.setDmg(100);
				Skeleton.setMaxSpeed(0.15);
				Skeleton.setFull(150);
				Skeleton.setCoolDown(500);

				heal.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[heal.type][0]), Vector2i(1, 1)));
				heal.setDmg(-20);
				heal.setMaxSpeed(0.01);
				heal.setFull(5000);
				heal.setCoolDown(10);

				dmg.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[dmg.type][0]), Vector2i(1, 1)));
				dmg.setDmg(0);
				dmg.setMaxSpeed(0.01);
				dmg.setFull(5000);
				dmg.setCoolDown(10);

				speed.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[speed.type][0]), Vector2i(1, 1)));
				speed.setDmg(0);
				speed.setMaxSpeed(0.01);
				speed.setFull(5000);
				speed.setCoolDown(10);
				player.setMaxSpeed(PLAYER_SPEED);
				player.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6,1))); // FIX
				player.setCoolDown(INIT_COOLDOWN);
				player.setFull(INIT_HP);
				bazoka = Weapon(2);
				bazoka.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("bazoka"), Vector2i(1, 1)));
				bazoka.setCoolDown(INIT_COOLDOWN);
				AWM = Weapon(1);
				AWM.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("AWM"), Vector2i(4, 1)));
				AWM.setCoolDown(INIT_COOLDOWN);
				shortGun = Weapon(0);
				shortGun.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("shortGun"), Vector2i(4, 1)));
				shortGun.setCoolDown(INIT_COOLDOWN);
				lvl = 1;
				setScreen(0);
				setResetPos(false);
			}
			break;
		case 9: // Option
			window.draw(c);
			endLife.setString("GIVE UP?");
			endLife.setFillColor(Color::Red);
			endLife.setCharacterSize(200);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y - 200));
			window.draw(endLife);
			endLife.setOrigin(textRect.left + textRect.width / 2.0f - 140,
				textRect.top + textRect.height / 2.0f);
			endLife.setString("[Enter] \tResume");
			endLife.setFillColor(Color::White);
			endLife.setCharacterSize(50);
			textRect = endLife.getLocalBounds();
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 100));
			window.draw(endLife);
			endLife.setString("[M] \t\t Return to Menu");
			endLife.setFillColor(Color::White);
			endLife.setCharacterSize(50);
			textRect = endLife.getLocalBounds();
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 180));
			window.draw(endLife);
			endLife.setString("[Q] \t\t Quit Game");
			endLife.setFillColor(Color::White);
			endLife.setCharacterSize(50);
			textRect = endLife.getLocalBounds();
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 260));
			window.draw(endLife);
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				setScreen(lastScreen);
				setResetPos(false);
			}
			else if (Keyboard::isKeyPressed(Keyboard::M)) {
				setScreen(0);
				setResetPos(false);
				soundCook.stop();
				soundHardMode.stop();
				soundEasyMode.stop();
				missRate = MISS_RATE;
				critRate = CRIT_RATE;
				max_mons = MAX_MONS;
				BOSS.setFull(BOSS_HP);
				BOSS.setCoolDown(BOSS_COOLDOWN);
				BOSS.setMaxSpeed(BOSS_SPEED);
				vz.clear();
				vt.clear();
				vHitEffect.clear();
				vHitEffect.clear();
				vp.clear();
				vef.clear();
				vt.erase(remove_if(vt.begin(), vt.end(), [](FloatingText& f) {return true; }), vt.end());
				vz.erase(remove_if(vz.begin(), vz.end(), [](Character& p) {return true; }), vz.end());
				vHitEffect.erase(remove_if(vHitEffect.begin(), vHitEffect.end(), [](Animation& p) {return true; }), vHitEffect.end());
				vDeadEffect.erase(remove_if(vDeadEffect.begin(), vDeadEffect.end(), [](Animation& p) {return true; }), vDeadEffect.end());
				vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return true; }), vp.end());
				vef.erase(remove_if(vef.begin(), vef.end(), [](Projectile& p) {return true; }), vef.end());
				BigMonster.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[0][0], MONS_SIZE[0][1]), texManager.get(MONS_NAME[BigMonster.type][0]), Vector2i(1, 1)));
				BigMonster.setDmg(10);
				BigMonster.setMaxSpeed(0.3);
				BigMonster.setFull(50);
				BigMonster.setCoolDown(1000);

				FlyingEye.init(Vector2f(0, 0), Animator(100, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[1][0], MONS_SIZE[1][1]), texManager.get(MONS_NAME[FlyingEye.type][0]), Vector2i(1, 1)));
				FlyingEye.setDmg(10);
				FlyingEye.setMaxSpeed(0.8);
				FlyingEye.setFull(20);
				FlyingEye.setCoolDown(1200);

				Goblin.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[2][0], MONS_SIZE[2][1]), texManager.get(MONS_NAME[Goblin.type][0]), Vector2i(1, 1)));
				Goblin.setDmg(20);
				Goblin.setMaxSpeed(0.3);
				Goblin.setFull(30);
				Goblin.setCoolDown(500);

				Skeleton.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[3][0], MONS_SIZE[3][1]), texManager.get(MONS_NAME[Skeleton.type][0]), Vector2i(1, 1)));
				Skeleton.setDmg(100);
				Skeleton.setMaxSpeed(0.15);
				Skeleton.setFull(150);
				Skeleton.setCoolDown(500);

				heal.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[heal.type][0]), Vector2i(1, 1)));
				heal.setDmg(-20);
				heal.setMaxSpeed(0.01);
				heal.setFull(5000);
				heal.setCoolDown(10);

				dmg.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[dmg.type][0]), Vector2i(1, 1)));
				dmg.setDmg(0);
				dmg.setMaxSpeed(0.01);
				dmg.setFull(5000);
				dmg.setCoolDown(10);

				speed.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[4][0], MONS_SIZE[4][1]), texManager.get(MONS_NAME[speed.type][0]), Vector2i(1, 1)));
				speed.setDmg(0);
				speed.setMaxSpeed(0.01);
				speed.setFull(5000);
				speed.setCoolDown(10);
				player.setMaxSpeed(PLAYER_SPEED);
				player.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get(AVATAR[skin] + "1"), Vector2i(6,1))); // FIX
				player.setCoolDown(INIT_COOLDOWN);
				player.setFull(INIT_HP);
				bazoka = Weapon(2);
				bazoka.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("bazoka"), Vector2i(1, 1)));
				bazoka.setCoolDown(INIT_COOLDOWN);
				AWM = Weapon(1);
				AWM.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("AWM"), Vector2i(4, 1)));
				AWM.setCoolDown(INIT_COOLDOWN);
				shortGun = Weapon(0);
				shortGun.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("shortGun"), Vector2i(4, 1)));
				shortGun.setCoolDown(INIT_COOLDOWN);
				lvl = 1;
			}
			else if (Keyboard::isKeyPressed(Keyboard::Q)) {
				window.close();
			}
			break;
		case 10:
			window.draw(c);
			endLife.setString("WELL DONE");
			endLife.setFillColor(Color::Blue);
			endLife.setCharacterSize(200);
			textRect = endLife.getLocalBounds();
			endLife.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			endLife.setPosition(Vector2f(view.getCenter().x, view.getCenter().y - 200));
			window.draw(endLife);
			winScreen.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 200));
			winScreen.update(elapsed);
			winScreen.draw(window);
			window.draw(endLife);
			break;
		}
		cursor.update();
		cursor.setColor(Color::Red);
		window.draw(cursor.getCursor());
		window.display();
		window.clear();
	}
}