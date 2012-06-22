#include <SFML/Graphics.hpp>


int main(int argc, char **argv)
{
    sf::RenderWindow window( sf::VideoMode(800, 600), "Arena2D" );

	enum SCENE {MAINMENU, BATTLESELECT, BATTLE, BATTLERESULT, SHOP, MAGICTOWER, GAMEOVER};
	SCENE Scene = MAINMENU;

	//general background texture
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("images/background.png");
	sf::Sprite background;
	background.setTexture(backgroundTexture);
	background.setPosition(0.f, 0.f);
	
	//main menu background texture
	sf::Texture mainMenuBackgroundTexture;
	mainMenuBackgroundTexture.loadFromFile("images/mainmenubackgroundsigns.png");
	sf::Sprite mainMenuBackground;
	mainMenuBackground.setTexture(mainBackgroundTexture);
	mainMenuBackground.setPosition(0.f, 0.f);

	//player sprite creation
	sf::Texture playerSpriteTexture;
	playerSpriteTexture.loadFromFile("images/testplayersprite.png");
	sf::Sprite playerSprite;
	playerSprite.setTexture(playerSpriteTexture);
	playerSprite.setPosition(200.f, 100.f);
	sf::Vector2f playerSpritePos;

	//enemy texture loading - sprite is created upon demand
	sf::Texture enemySpriteTexture;
	enemySpriteTexture.loadFromFile("images/testsprite.png");


    while ( window.isOpen() )
    {
		window.clear();

        sf::Event event;
        while ( window.pollEvent(event) )
        {
			// Window Closed
            if (event.type == sf::Event::Closed)
                window.close();

			// Escape key pressed - closes game
			if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
				window.close();
        }


		// main menu
		if (Scene == MAINMENU)
		{
			//get player position
			playerSpritePos = playerSprite.getPosition();

			//change scene if needed
			if (playerSpritePos.y <= 0)
				Scene = BATTLESELECT;
			if (playerSpritePos.x >= 800)
				Scene = SHOP;
			if (playerSpritePos.x <= 0)
				Scene = MAGICTOWER;
			if (playerSpritePos.y >= 600)
				window.close();

			//movement
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
				playerSprite.move(0,-2);
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
				playerSprite.move(0,2);
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
				playerSprite.move(2,0);
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
				playerSprite.move(-2,0);

			//display
			window.draw(mainMenuBackground);
			window.draw(playerSprite);
		}

		// battle setup
		if (Scene == BATTLESELECT)
		{
			playerSprite.setPosition(200.f, 100.f);

			while ( window.pollEvent(event) )
			{
				// Window Closed
				if (event.type == sf::Event::Closed)
				    window.close();

				// Escape key pressed - closes game
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
					window.close();

				// go back to main menu
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space) )
					Scene = MAINMENU;

				// enemy choice
				//choose enemy 1
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1) )
					
				//choose enemy 2
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2) )
					
				//choose enemy 3
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3) )
					

			}

			window.draw(background); //placeholder until battle background
			window.draw(playerSprite);
		}

		// battle
		if (Scene == BATTLE)
		{

		}

		// battle result
		if (Scene == BATTLERESULT)
		{

		}

		// shop
		if (Scene == SHOP)
		{
			
		}

		// magic tower
		if (Scene == MAGICTOWER)
		{
			
		}

		// game over
		if (Sene == GAMEOVER)
		{

		}


		//display all the things
        window.display();
    }

    return 0;
}