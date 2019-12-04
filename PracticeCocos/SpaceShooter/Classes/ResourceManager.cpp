#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	int count = 0;
	std::string path = FileUtils::getInstance()->getStringFromFile("Data.bin");
	while (!path.empty()) {
		std::string line = path.substr(0, path.find("\n"));
		std::istringstream is(line);
		int num;
		std::string text,text2;
		is >> num >> text>> text2;
		path.erase(0, path.find("\n") + 1);
		if (num == 0) {
			count++;
			continue;
		}

		if (count == 1) {
			auto sprite = Sprite::create(text);
			m_sprites.insert({ (char)num,sprite });
			continue;
		}
		if (count == 2) {
			auto button = ui::Button::create(text, text2);
			m_buttons.insert({ (char)num,button });
			continue;
		}
		if (count == 3) {
			auto label = Label::createWithTTF("temp", text, 20);
			m_labels.insert({ (char)num,label });
		}
	}
}

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::GetInstance()
{
	return this->s_instance;
}

Sprite* ResourceManager::GetSpriteById(char id)
{
	auto sprite = m_sprites.find(id)->second;
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
