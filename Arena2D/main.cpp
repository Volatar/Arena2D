#include <SFML/Graphics.hpp>


int main(int argc, char **argv)
{
    sf::RenderWindow window( sf::VideoMode(800, 600), "Arena2D" );

	//TODO: change sceneID to an enum for readability
	int sceneID = 0;
	/* sceneID
	0 = main menu
	1 = battle
	2 = shop
	3 = magic tower
	4 = loot screen?
	5 = game over?
	*/

	
	sf::Texture mainBackgroundTexture;
	mainBackgroundTexture.loadFromFile("images/mainbackgroundsigns.png");
	sf::Sprite mainBackground;
	mainBackground.setTexture(mainBackgroundTexture);
	mainBackground.setPosition(0.f, 0.f);

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


		//main area
		if (sceneID == 0)
		{
			//get player position
			playerSpritePos = playerSprite.getPosition();

			//change scene if needed
			if (playerSpritePos.y <= 0)
				sceneID = 1;
			if (playerSpritePos.x >= 800)
				sceneID = 2;
			if (playerSpritePos.x <= 0)
				sceneID = 3;
			if (playerSpritePos.y >= 600)
				window.close();

			//movement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				playerSprite.move(0,-2);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				playerSprite.move(0,2);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				playerSprite.move(2,0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				playerSprite.move(-2,0);
		}

		//battle
		if (sceneID == 1)
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

			// other imputs here
			}

			window.draw(mainBackground); //placeholder until battle background
			window.draw(playerSprite);
		}

		//shop
		if (sceneID == 2)
		{
			
		}

		// magic tower
		if (sceneID == 3)
		{
			
		}


		//display stuff
		window.clear();

		if (sceneID == 0)
		{
			window.draw(mainBackground);
			window.draw(playerSprite);
		}


        window.display();
    }

    return 0;
}