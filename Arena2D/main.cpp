#include <SFML/Graphics.hpp>


int main(int argc, char **argv)
{
    sf::RenderWindow window( sf::VideoMode(800, 600), "Chess by Volatar" );

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

	sf::Texture texture;
	texture.loadFromFile("images/testsprite.png");

	sf::Sprite playerSprite;
	playerSprite.setTexture(texture);
	playerSprite.setPosition(200.f, 100.f);
	playerSprite.setOrigin(0, 0);
	sf::Vector2f playerSpritePos;

    while ( window.isOpen() )
    {

        sf::Event event;
        while ( window.pollEvent(event) )
        {

			// Window Closed
            if (event.type == sf::Event::Closed)
                window.close();

			// Escape key pressed
			if ( (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) )
				window.close();

        }

		if (sceneID = 0)
		{
			//get player position
			playerSpritePos = playerSprite.getPosition();

			//change scene if needed
			if (playerSpritePos.x <= 0)
				sceneID = 1;
			if (playerSpritePos.y >= 600)
				sceneID = 2;
			if (playerSpritePos.y <= 0


			//movement
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				playerSprite.move(0,-1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				playerSprite.move(0,1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				playerSprite.move(1,0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				playerSprite.move(-1,0);
		}

		window.clear();

		if (sceneID = 0)
		window.draw(playerSprite);



        window.display();
    }

    return 0;
}