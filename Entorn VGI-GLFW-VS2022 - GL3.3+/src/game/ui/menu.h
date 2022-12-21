#pragma once
#include "UIElement.h"

enum class MenuType
{
	MENU,
	START,
	EXIT
};

class Menu : public UIElement
{
public:
	static Menu instance;

	Menu(Transform transform) : UIElement(transform) {}

	void change_menu(MenuType type);
	void remove_menu();

	Menu& set_menu_default(UIElement* indicator);
	Menu& set_menu_exit(UIElement* indicator);
	Menu& set_menu_start(UIElement* inditador);

private:
	UIElement* my_menu_default = nullptr;
	UIElement* my_menu_exit = nullptr;
	UIElement* my_menu_start = nullptr;
};