#include "projectincludes.h"
#include "fight.h"

int main(int argc, char **argv)
{
    sf::RenderWindow window( sf::VideoMode(800, 600), "Arena2D" );

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
	mainMenuBackground.setTexture(mainMenuBackgroundTexture);
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
	sf::Sprite enemySprite;
	enemySprite.setTexture(enemySpriteTexture);
	enemySprite.setPosition(500.f, 200.f);
	sf::Vector2f enemySpritePos;

	//player data creation
	Actor player;

	//enemy initialization
	Actor enemy;

	//text objects for battle display
	sf::Text playerHealth;
	playerHealth.setPosition(200, 400);
	sf::Text enemyHealth;
	enemyHealth.setPosition(500, 400);

	std::string tempString;
	std::stringstream tempStringStream;

	SCENE Scene = MAINMENU;

    while ( window.isOpen() )
    {
		window.clear();

        sf::Event event;


		// main menu
		if (Scene == MAINMENU)
		{
			//get player position
			playerSpritePos = playerSprite.getPosition();

			while ( window.pollEvent(event) )
			{
				// Window Closed
				if (event.type == sf::Event::Closed)
				    window.close();

				// Escape key pressed - closes game
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
					window.close();
			}

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
			playerSprite.setPosition(200.f, 200.f);

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
				{
					enemy.setLevel(1);
					Scene = BATTLE;
				}
				//choose enemy 2
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2) )
				{
					enemy.setLevel(2);
					Scene = BATTLE;
				}
				//choose enemy 3
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3) )
				{
					enemy.setLevel(3);
					Scene = BATTLE;
				}

			}

			window.draw(background); //placeholder until battle background
			window.draw(playerSprite);
		}

		// battle
		if (Scene == BATTLE)
		{
			
			//clear tempStringStream
			tempStringStream.str("");

			//each time player presses attack run a fight
			while ( window.pollEvent(event) )
			{
				// Window Closed
				if (event.type == sf::Event::Closed)
				    window.close();

				// Escape key pressed - closes game
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
					window.close();

				//attack key
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return) )
					fight(player, enemy);
				
				//debug code
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Z) )
					player.currentHealth--;
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::X) )
					enemy.currentHealth--;
			}

			//set health text
			tempStringStream.str("");
			tempStringStream << player.currentHealth;
			tempString = tempStringStream.str();
			playerHealth.setString(tempString);
			tempStringStream.str("");
			tempStringStream << enemy.currentHealth;
			tempString = tempStringStream.str();
			enemyHealth.setString(tempString);

			//render
			window.draw(background);
			window.draw(playerSprite);
			window.draw(enemySprite);
			window.draw(playerHealth);
			window.draw(enemyHealth);

		}

		// post-battle results
		if (Scene == BATTLERESULT)
		{

			while ( window.pollEvent(event) )
			{
				// Window Closed
				if (event.type == sf::Event::Closed)
				    window.close();

				// Escape key pressed - closes game
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
					window.close();
			}

			//xp gain
			//level up if applicable
			//loot
		}

		// shop
		if (Scene == SHOP)
		{
			while ( window.pollEvent(event) )
			{
				// Window Closed
				if (event.type == sf::Event::Closed)
				    window.close();

				// Escape key pressed - closes game
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
					window.close();
			}
		}

		// magic tower
		if (Scene == MAGICTOWER)
		{
			while ( window.pollEvent(event) )
			{
				// Window Closed
				if (event.type == sf::Event::Closed)
				    window.close();

				// Escape key pressed - closes game
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
					window.close();
			}
		}

		// game over
		if (Scene == GAMEOVER)
		{
			while ( window.pollEvent(event) )
			{
				// Window Closed
				if (event.type == sf::Event::Closed)
				    window.close();

				// Escape key pressed - closes game
				if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
					window.close();
			}
		}


		//display all the things
        window.display();
    }

    return 0;
}