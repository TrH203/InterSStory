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
	window.create(VideoMode(700, 700), "ZOMBIEEE!! AAGAHRG!!1!!!!!1!", Style::Fullscreen);
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
	
	setScreen(5);
	bool resetPos = false;
	// Player
	texManager.add("player1", "image/witch.png"); // Need to be writen on a txt file
	texManager.add("player2", "image/witch.png");

	// Paterns
	texManager.add("wood", "image/wood.png");
	texManager.add("grass", "image/grass.png");
	texManager.add("bullet", "image/bullet1.png");
	texManager.add("weed", "image/weed.png");
	texManager.add("tree", "image/tree.png");
	texManager.add("shortGun", "image/gun.png");
	texManager.add("AWM", "image/gun1.png");
	texManager.add("punch", "image/punch.png");
	
	texManager.add("heal", "image/heal.png");
	texManager.add("dmg", "image/dmg.png");
	texManager.add("speed", "image/speed.png");


	texManager.add("mode", "image/mode.png");
	texManager.add("target", "image/target.png");
	texManager.add("doormat", "image/doormat.png");

	//  Scenes
	texManager.add("DT", "image/DT.png");
	texManager.add("SS", "image/SS.png");
	texManager.add("lake", "image/lake.png");
	texManager.add("river", "image/sea1.png");
	texManager.add("summon", "image/summon.png");
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

void Game::movePlayer(Time& elapsed) {
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

	if (player.getPos().x + player.getSize().x / 2.f > 500 + MENU_X_LIMIT)
	{
		player.setPos(Vector2f(500 + MENU_X_LIMIT - player.getSize().x / 2.f - 1, player.getPos().y));
	}
	else if (player.getPos().x - player.getSize().x / 2.f < 500)
	{
		player.setPos(Vector2f(500 + player.getSize().x / 2.f + 1, player.getPos().y));
	}
	if (player.getPos().y + player.getSize().y / 2.f > 500 + MENU_Y_LIMIT)
	{
		player.setPos(Vector2f(player.getPos().x, 500 + MENU_Y_LIMIT - player.getSize().y / 2.f - 1));
	}
	else if (player.getPos().y - player.getSize().y / 2.f < 500)
	{
		player.setPos(Vector2f(player.getPos().x, 500 + player.getSize().y / 2.f + 1));
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
		player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get("player1"), Vector2i(1, 5)));
	}
	else if (player.getDir() == 1 && lastDir == 0) {
		player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get("player2"), Vector2i(1, 5)));
	}
}

void Game::run()
{

	SoundBuffer bufferDead;
	SoundBuffer bufferEasyMode;
	SoundBuffer bufferHardMode;
	SoundBuffer bufferAWM;

	Sound soundDead;
	Sound soundEasyMode;
	Sound soundHardMode;
	Sound soundAWM;

	int GameMode = 1; // => HIEN FIX

	/*bufferDead.loadFromFile("sound/Dead.wav");
	bufferEasyMode.loadFromFile("sound/easyMode.wav");
	bufferHardMode.loadFromFile("sound/hardMode.wav");
	bufferAWM.loadFromFile("sound/AWM.wav");*/

	soundDead.setBuffer(bufferDead);
	soundEasyMode.setBuffer(bufferEasyMode);
	soundHardMode.setBuffer(bufferHardMode);
	soundAWM.setBuffer(bufferAWM);

	vector<Character> vz;
	Projectile p, shootEffect;
	vector<Projectile> vp, vef;
	vector<Animation> vHitEffect;
	vector<Animation> vDeadEffect;
	vector<Obstacle> trees;
	int x_rand, y_rand;

	Sprite floor, grass, lake, river, weed[NUM_WEED];
	grass.setTextureRect(IntRect(0, 0, LVL_X_LIMIT, LVL_Y_LIMIT));
	floor.setTextureRect(IntRect(0, 0, MENU_X_LIMIT, MENU_Y_LIMIT));

	/*for (int i = 0; i < NUM_WEED; i++)
	{
		x_rand = rand() % LVL_X_LIMIT;
		y_rand = rand() % LVL_Y_LIMIT;
		weed[i].setTextureRect(IntRect(0, 0, WEED_W, WEED_H));
		weed[i].setTexture(*texManager.get("weed"));
		weed[i].setPosition(x_rand, y_rand);
	}*/
	river.setTextureRect(IntRect(0, 0, 570, 570));
	river.setTexture(*texManager.get("river"));
	river.setPosition(1000, 1000);

	lake.setTextureRect(IntRect(0, 0, 570, 570));
	lake.setTexture(*texManager.get("lake"));
	lake.setPosition(1000, 1100);
	for (int i = 0; i < NUM_TREE; i++)
	{
		x_rand = rand() % LVL_X_LIMIT;
		y_rand = rand() % LVL_Y_LIMIT;
		Obstacle temp = Obstacle(Vector2f(x_rand, y_rand), Animator(100, Vector2f(0, 0), Vector2f(TREE_W, TREE_H), texManager.get("tree"), Vector2i(4, 1)));
		trees.push_back(temp);
	}

	Font f;
	f.loadFromFile("BAUHS93.TTF");

	Text life;
	life.setFont(f);
	life.setFillColor(Color::Red);
	life.setPosition(view.getCenter() - view.getSize() / 2.f + Vector2f(10, 10));
	life.setCharacterSize(30);

	vector<FloatingText> vt;

	FloatingText t;

	t.init("DEAD", 1000, 0.05);
	t.setFont(f);
	t.setSize(20);
	t.setFillColor(Color::Red);


	player.setMaxSpeed(0.4);
	player.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get("player1"), Vector2i(1, 5))); // FIX
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
	FlyingEye.setMaxSpeed(0.6);
	FlyingEye.setFull(20);
	FlyingEye.setCoolDown(1200);

	Goblin.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[2][0], MONS_SIZE[2][1]), texManager.get(MONS_NAME[Goblin.type][0]), Vector2i(1, 1)));
	Goblin.setDmg(20);
	Goblin.setMaxSpeed(0.4);
	Goblin.setFull(30);
	Goblin.setCoolDown(500);

	Skeleton.init(Vector2f(0, 0), Animator(200, Vector2f(0, 0 * 64), Vector2f(MONS_SIZE[3][0], MONS_SIZE[3][1]), texManager.get(MONS_NAME[Skeleton.type][0]), Vector2i(1, 1)));
	Skeleton.setDmg(100);
	Skeleton.setMaxSpeed(0.2);
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


	int choosed = -1;
	Weapon punch = Weapon(2);
	punch.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("punch"), Vector2i(1, 1)));
	punch.setCoolDown(INIT_COOLDOWN);

	Weapon AWM = Weapon(1);
	AWM.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("AWM"), Vector2i(4, 1)));
	AWM.setCoolDown(INIT_COOLDOWN);

	Weapon shortGun = Weapon(0);
	shortGun.init(Vector2f(LVL_X_LIMIT / 2, LVL_Y_LIMIT / 2), Animator(200, Vector2f(0, 0), Vector2f(WEAPON_SIZE, WEAPON_SIZE), texManager.get("shortGun"), Vector2i(4, 1)));
	shortGun.setCoolDown(INIT_COOLDOWN);

	player.chooseWeapon(AWM);

	Counter nextSpawn(SPAWN_SPEED);
	
	Counter buff_duration(15000);
	
	buff_duration.setEmpty();
	RectangleShape buff_duration_bar;
	//buff_duration_bar.setPosition(view.getCenter()
	
	
	Clock clock;
	Time elapsed;

	int edge;
	int x, y, kind, dir=0;

	int buff_count=0;
	Obstacle buildMode, buildSkin, buildWeapon, buildOption, buildStart, doormat;
	Obstacle targetWeapon[3], chooseSkin[4];
	buildMode.init(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get("player1"), Vector2i(1, 5)));

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
	soundEasyMode.play();
	int skin = -1;
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
				if (Keyboard::isKeyPressed(Keyboard::Escape))
					window.close();
			}
		}

		RectangleShape c;
		c.setFillColor(Color::Black);
		c.setSize(Vector2f(LVL_X_LIMIT, LVL_Y_LIMIT));
		c.setPosition(Vector2f(0, 0));
		float RADIUS = 350, S_RADIUS = 250;
		char circles[4][3][30] = { {"circle1", "circles1", "circle1Light"}, {"circle2", "circles2", "circle2Light"}, {"circle3", "circles3", "circle3Light"}, {"circle4", "circles4", "circle4Light"} };
		switch (getScreen()) {
		case 0:
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 250));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("wood")->setRepeated(true);
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
					cout << wait.get() << endl;
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
					cout << wait.get() << endl;
				}
				else {
					wait.set(0);
					isIn[1] = true;
				}
				if (wait.get() >= 2000) {
					setScreen(5);
					setResetPos(false);
				}
			}
			else isIn[1] = false;
			movePlayer(elapsed);
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
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 250));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("wood")->setRepeated(true);
			floor.setTexture(*texManager.get("wood"));
			floor.setPosition(Vector2f(500, 500));
			movePlayer(elapsed);

			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);
			targetWeapon[0].setPos(Vector2f(LVL_X_LIMIT / 2.f - 200, LVL_Y_LIMIT / 2.f - 200));
			targetWeapon[0].update(elapsed);
			targetWeapon[1].setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f - 200));
			targetWeapon[1].update(elapsed);
			targetWeapon[2].setPos(Vector2f(LVL_X_LIMIT / 2.f + 200, LVL_Y_LIMIT / 2.f - 200));
			targetWeapon[2].update(elapsed);

			// Config Trigger
			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[0]) {
					wait.add(elapsed.asMilliseconds());
					cout << wait.get() << endl;
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
					p.init(player.getPos(), player.getAngle() - 90, 1.0f, 2000, texManager.get("bullet"));
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
						cout << i << endl;
						choosed = i;
					}
				}
			}
			vp.erase(remove_if(vp.begin(), vp.end(), [](Projectile& p) {return p.isDestroyed(); }), vp.end());
			if (choosed == 0) {
				player.chooseWeapon(shortGun);
			}
			else if (choosed == 1) {
				player.chooseWeapon(AWM);
			}
			else if (choosed == 2) {
				player.chooseWeapon(punch);
			}
			


			// Draw
			window.draw(floor);
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
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("grass")->setRepeated(true);
			floor.setTexture(*texManager.get("grass"));
			floor.setPosition(Vector2f(500, 500));
			movePlayer(elapsed);

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
				cout << skin << endl;
				if (i == skin) continue;
				if (chooseSkin[i].isCollided(player, chooseSkin[i].getSize().x, chooseSkin[i].getSize().y, false)) {
					if (isIn[i]) {
						wait.add(elapsed.asMilliseconds());
						cout << wait.get() << endl;
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
						cout << skin << endl;
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
			player.draw(window);
			break;
		case 3: // Setting Audio
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 250));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("grass")->setRepeated(true);
			floor.setTexture(*texManager.get("grass"));
			floor.setPosition(Vector2f(500, 500));
			movePlayer(elapsed);

			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);

			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[0]) {
					wait.add(elapsed.asMilliseconds());
					cout << wait.get() << endl;
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

			// Draw
			window.draw(floor);
			doormat.draw(window);
			player.draw(window);
			break;
		case 4: // Choosing Mode
			if (!resetPos) {
				player.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 250));
				setResetPos(true);
			}

			// Setup screen
			texManager.get("grass")->setRepeated(true);
			floor.setTexture(*texManager.get("grass"));
			floor.setPosition(Vector2f(500, 500));
			movePlayer(elapsed);

			doormat.setPos(Vector2f(LVL_X_LIMIT / 2.f, LVL_Y_LIMIT / 2.f + 440));
			doormat.update(elapsed);

			if (doormat.isCollided(player, doormat.getSize().x, doormat.getSize().y, false)) {
				if (isIn[0]) {
					wait.add(elapsed.asMilliseconds());
					cout << wait.get() << endl;
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

			// Draw
			window.draw(floor);
			doormat.draw(window);
			player.draw(window);
			break;
		case 5: // Play
			if (GameMode == 0) {
				soundHardMode.stop();
				if (SoundSource::Status::Playing != soundEasyMode.getStatus()) {
					soundEasyMode.play();
				}
			}
			else if (GameMode == 1) {
				soundEasyMode.stop();
				if (SoundSource::Status::Playing != soundHardMode.getStatus()) {
					soundHardMode.play();
				}
			}

			//texManager.get("wood")->setRepeated(true);
			grass.setTexture(*texManager.get("wood"));

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
						//std::cout <<"BUFF" << endl;
						
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
			//FIX gop Obstacle vao vector global
			if (Keyboard::isKeyPressed(Keyboard::W))
				player.addForce(0, -PLAYER_SPEED);
			if (Keyboard::isKeyPressed(Keyboard::A))
				player.addForce(-PLAYER_SPEED, 0);
			if (Keyboard::isKeyPressed(Keyboard::S))
				player.addForce(0, PLAYER_SPEED);
			if (Keyboard::isKeyPressed(Keyboard::D))
				player.addForce(PLAYER_SPEED, 0);
			if (Keyboard::isKeyPressed(Keyboard::D))
				player.addForce(PLAYER_SPEED, 0);
			
			/*if (Keyboard::isKeyPressed(Keyboard::Up))
				player.addForce(0, -PLAYER_SPEED);
			if (Keyboard::isKeyPressed(Keyboard::Left))
				player.addForce(-PLAYER_SPEED, 0);
			if (Keyboard::isKeyPressed(Keyboard::Down))
				player.addForce(0, PLAYER_SPEED);
			if (Keyboard::isKeyPressed(Keyboard::Right))
				player.addForce(PLAYER_SPEED, 0);*/

			/*for (Obstacle& tree : trees) {
				if (!tree.isCollided(player, tree.getSize().x, tree.getSize().x, false)) continue;
				else
				{
					if (player.getPos().x < tree.getPos().x - tree.getSize().x / 2.f) {
						player.setForce(Vector2f(-PLAYER_SPEED / 2, 0));
					}
					if (player.getPos().y < tree.getPos().y - tree.getSize().y / 2.f) {
						player.setForce(Vector2f(0, -PLAYER_SPEED / 2));
					}
					if (player.getPos().x > tree.getPos().x + tree.getSize().x / 2.f) {
						player.setForce(Vector2f(PLAYER_SPEED / 2, 0));
					}
					if (player.getPos().y > tree.getPos().y + tree.getSize().y / 2.f) {
						player.setForce(Vector2f(0, PLAYER_SPEED / 2));
					}
				}
			}*/

			if (player.getPos().x + player.getSize().x / 2.f > LVL_X_LIMIT)
			{
				player.setPos(Vector2f(LVL_X_LIMIT - player.getSize().x / 2.f - 1, player.getPos().y));
			}
			else if (player.getPos().x - player.getSize().x / 2.f < 0)
			{
				player.setPos(Vector2f(player.getSize().x / 2.f + 1, player.getPos().y));
			}
			if (player.getPos().y + player.getSize().y / 2.f > LVL_Y_LIMIT)
			{
				player.setPos(Vector2f(player.getPos().x, LVL_Y_LIMIT - player.getSize().y / 2.f - 1));
			}
			else if (player.getPos().y - player.getSize().y / 2.f < 0)
			{
				player.setPos(Vector2f(player.getPos().x, player.getSize().y / 2.f + 1));
			}
			int lastDir = player.getDir();

			player.look(cursor.getCursor().getPosition(), elapsed);
			player.update(elapsed);

			/*if (player.getAngle() <= 180) {
				player.setDir(0);
			}
			else {
				player.setDir(1);
			}
			if (player.getDir() == 0 && lastDir == 1) {
				player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get("player1"), Vector2i(1, 5)));
			}
			else if (player.getDir() == 1 && lastDir == 0) {
				player.init(player.getPos(), Animator(200, Vector2f(0, 0), Vector2f(PLAYER_W, PLAYER_H), texManager.get("player2"), Vector2i(1, 5)));
			}*/
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
									t.init("CRIT DEAD", z.getPos(), 50);
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
							//p.destroy();
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
						buff_count --;
						return p.isDead();
					}
					points++;
					//lvlUp = true;
					if (points % 1 == 0)
					{
						lvlUp = true;
					}
				} return p.isDead();
				}), vz.end());

			if (lvlUp)
			{
				if (player.getCoolDown() > 100)
					player.setCoolDown(player.getCoolDown() - player.getCoolDown() * COOLDOWN_CHANGE);

				player.increaseHp(5); //FIX
				player.heal(player.getTotHp() * 0.1f);
				max_mons += max_mons * 0.2;
				if (max_mons > 55) max_mons = 35;
				if (critRate < 1) critRate += CRIT_CHANGE * (1 - critRate); //FIX
				if (missRate > 0) missRate -= MISS_CHANGE * missRate;
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
				for (Obstacle& tree : trees) {
					if (!tree.isCollided(vz[k], tree.getSize().x, tree.getSize().x, false)) continue;
					else
					{
						fwd = false;
					}
				}
				if (fwd) vz[k].moveFwd();
				else vz[k].moveBwd();
				vz[k].update(elapsed);
				/*if (vz[k].getAngle() <= 180) {
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
				}*/
			}

			for (Character& z : vz)
			{
				if (z.intersects(&player) && z.useDmg())
				{

					if (!GOD_MODE) {
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


			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (player.useDmg())
				{
					soundAWM.play();

					p.init(player.getPos(), player.getAngle() - 90, 2.0f, 1200, texManager.get("bullet"));
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
			for (int i = 0; i < NUM_WEED; i++)
			{
				window.draw(weed[i]);
			}

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
			window.draw(river);
			window.draw(lake);
			player.draw(window, player.getHpRect(), player.getOriginHpRect());
			player.weapon.draw(window);
			//gun.draw(window);

			for (Character& z : vz)
				z.draw(window, z.getHpRect(), z.getOriginHpRect());
			for (FloatingText& f : vt)
				window.draw(f);
			for (Obstacle& tree : trees)
				tree.draw(window);
			
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
			window.draw(cursor.getCursor());
			window.draw(life);
			
			//std::cout << player_speed << endl;
			
			
			//buff_duration_bar.setOrigin();

			if (player.isDead())
			{
				RectangleShape c;
				c.setFillColor(Color::Black);
				c.setSize(Vector2f(LVL_X_LIMIT, LVL_Y_LIMIT));
				c.setPosition(Vector2f(0, 0));
				window.draw(c);
				life.setString("YOU ARE DEAD!");
				life.setFillColor(Color::Red);
				life.setCharacterSize(60);
				sf::FloatRect textRect = life.getLocalBounds();
				life.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				life.setPosition(view.getCenter());
				window.draw(life);
				life.setString("Your points is: " + to_string(points));
				life.setFillColor(Color::Red);
				life.setCharacterSize(30);
				textRect = life.getLocalBounds();
				life.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				life.setPosition(Vector2f(view.getCenter().x, view.getCenter().y + 100));
				window.draw(life);

			}
			break;
		}
		cursor.update();
		cursor.setColor(Color::Red);
		window.draw(cursor.getCursor());
		window.display();
		window.clear();
	}
}