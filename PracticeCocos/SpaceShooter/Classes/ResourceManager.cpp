#include "ResourceManager.h"

ResourceManager* ResourceManager::GetInstance()
{
	return this->s_instance;
}

Sprite* ResourceManager::GetSpriteById(char id)
{
	Sprite* sprite = Sprite::create("");
	sprite->retain();
	return sprite;
}

ui::Button* ResourceManager::GetButtonById(char id)
{
	ui::Button* button = ui::Button::create("");
	button->retain();
	return button;
}

Label* ResourceManager::GetLabelById(char id)
{
	Label* label = Label::createWithTTF("Mytext", "Marker Felt.ttf", 24);
	label->retain();
	return label;
}
