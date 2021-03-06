#ifndef _GAME_INCLUDE
#define _GAME_INCLUDE


#include "Scene.h"
#include "Menu.h"
#include "Info.h"
#include "Credits.h"

#include"Framework.h"

#define	TEST_WAVE_FILE		  "Footsteps.wav"
#define	BACKGROUND_MUSIC_FILE "CelesteMusic.wav"


#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 480


// Game is a singleton (a class with a single instance) that represents our whole application


class Game
{

private:
	Game() {}
	
public:
	static Game &instance()
	{
		static Game G;
	
		return G;
	}
	
	void init();
	bool update(int deltaTime);
	void render();
	void cleanup();
	
	enum State {MENU, INFO, GAME, CREDITS};

	// Input callback methods
	void keyPressed(int key);
	void keyReleased(int key);
	void specialKeyPressed(int key);
	void specialKeyReleased(int key);
	void mouseMove(int x, int y);
	void mousePress(int button);
	void mouseRelease(int button);

	void win();
	
	bool getKey(int key) const;
	bool getKeyBuffer(int key);
	bool getSpecialKey(int key) const;

	Scene getScene();

private:
	ALuint      uiBuffer;
	ALuint      uiSource;
	ALint       iState;

	bool bPlay;                       // Continue to play game?
	Menu menu;                        // Main menu to render
	Info info;                        // Info screed to render
	Scene scene;                      // Scene to render
	Credits credits;                  // Credits screen to render
	bool keys[256], keysBuffer[256], specialKeys[256]; // Store key states so that 
	                                  // we can have access at any time
	State state;
	bool bS, bLastFrameWasUpdate; // Cheat: Half (S)peed
	int lastFrameDeltaTime;

};


#endif // _GAME_INCLUDE


