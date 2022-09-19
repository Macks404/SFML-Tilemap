class Tilemap
{
public:
	std::vector<float> tilesX;
	std::vector<float> tilesY;
	float tileSizeX;
	float tileSizeY;

	Tilemap(sf::Vector2f size, sf::Vector2f screenSize)
	{
		tilesX.resize(size.x);
		tilesY.resize(size.y);

		tileSizeX = screenSize.x / size.x;
		tileSizeY = screenSize.y / size.y;

		for (int i = 0; i < size.x; i++)
		{
			tilesX[i] = tileSizeX * i;
		}
		for (int i = 0; i < size.y; i++)
		{
			tilesY[i] = tileSizeY * i;
		}
	}

	sf::Vector2i getCurrentTile(sf::Vector2i mousePos)
	{
		sf::Vector2i currentTile;

		for (int i = 0; i < tilesX.size(); i++)
		{
			if (i == tilesX.size() - 1)
			{
				if (mousePos.x >= tilesX[i])
				{
					currentTile.x = i;
				}
			}
			else
			{
				if (mousePos.x >= tilesX[i] && mousePos.x <= tilesX[i + 1])
				{
					currentTile.x = i;
				}
			}
		}
		for (int i = 0; i < tilesY.size(); i++)
		{
			if (i == tilesY.size() - 1)
			{
				if (mousePos.y >= tilesY[i])
				{
					currentTile.y = i;
				}
			}
			else
			{
				if (mousePos.y >= tilesY[i] && mousePos.y <= tilesY[i + 1])
				{
					currentTile.y = i;
				}
			}
		}

		return currentTile;
	}

	sf::Sprite createObjAtTile(sf::Vector2i pos, sf::Sprite obj, bool useMouse = false)
	{
		if (useMouse == true)
		{
			pos = getCurrentTile(pos);
		}
		obj.setScale(tileSizeX / (*obj.getTexture()).getSize().x, tileSizeY / (*obj.getTexture()).getSize().y);
		obj.setPosition(tilesX[pos.x], tilesY[pos.y]);

		return obj;
	}
};