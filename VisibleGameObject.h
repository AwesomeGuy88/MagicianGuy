#pragma once

//VisibleGameObject - A conceptual class that contains all basic members that
//				any visible game object needs. Created for the sake of 
//				reusable code for any specific game objects to inherit

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);
	virtual void Update(float elapsedTime, float x_o, float y_o);

	virtual void SetPosition(float x, float y, float x_o, float y_o);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded() const;
	virtual void SetObjectID(std::string ID);

	virtual std::string GetObjectID();
	virtual float GetWidth() const;
	virtual float GetHeight() const;
	virtual sf::Texture GetTexture() const;

	virtual sf::Rect<float> GetBoundingRect() const;

protected:
	sf::Sprite& GetSprite();
	float x, y;

private:
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;
	std::string _objectID;
};