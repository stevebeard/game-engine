#ifndef ui_h
#define ui_h

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include "game_time.h"

class sf::Font;
class sf::Texture;

// Base UI element
class UIElement
{
public:
	UIElement(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h) {};
	virtual ~UIElement(void) = default;

	//virtual void draw(void) = 0;

	int get_width(void) const;
	int get_height(void) const;
	bool is_in_bounds(int x, int y) const;

protected:
	int _x, _y, _w, _h;
};


// Game world view
class Viewport : public UIElement, public sf::RenderWindow
{
public:
	Viewport(int x, int y, int w, int h);

	void update(void);
	//void draw(void) override;
	std::pair<int, int> world_to_screen(int x, int y) const;
	std::pair<int, int> screen_to_world(int x, int y) const;

private:
	int _world_x, _world_y;

	std::pair<int, int> get_screen_origin(void) const;
};


// Displays player attributes
class StatusDisplay : public UIElement
{
public:
	StatusDisplay(int x, int y, int w, int h, const Timer& turn_timer, const int& turns, const sf::Font& font) :
		UIElement(x, y, w, h), _turn_timer(turn_timer), _turns(turns), _font(font) {};

	//void draw(void) override;

private:
	const Timer& _turn_timer;
	const int& _turns;
	const sf::Font& _font;
};

// Inventory panel
class InventoryDisplay : public UIElement
{
public:
	InventoryDisplay(int x, int y, int w, int h, const sf::Font& font) : UIElement(x, y, w, h), _font(font) {}
	//void draw(void) override;

private:
	const sf::Font& _font;
};

#endif
