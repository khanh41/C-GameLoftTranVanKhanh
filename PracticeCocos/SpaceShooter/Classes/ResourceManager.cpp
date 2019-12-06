#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	//s_instance = new ResourceManager[10];
	/*m_sprites = new std::map<char, Sprite*>[10];
	m_buttons = new std::map<char, ui::Button*>;
	m_labels = new std::map<char, Label*>;*/
}

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::GetInstance()
{
	return this->s_instance;
}

void ResourceManager::Init(const std::string path)
{
	m_dataFolderPath = FileUtils::getInstance()->getStringFromFile(path);
	Load(m_dataFolderPath);
}

void ResourceManager::Load(std::string fileName)
{
	int count = 0;
	while (!m_dataFolderPath.empty()) {
		std::string line = m_dataFolderPath.substr(0, m_dataFolderPath.find("\n"));
		std::istringstream is(line);
		int num;
		std::string text, text2;
		is >> num >> text >> text2;
		m_dataFolderPath.erase(0, m_dataFolderPath.find("\n") + 1);
		if (num == 0) {
			count++;
			continue;
		}

		if (count == 1) {
			auto sprite = Sprite::create(text);
			m_sprites.insert({ num,sprite });
			continue;
		}
		if (count == 2) {
			auto button = ui::Button::create(text, text2);
			m_buttons.insert({ num,button });
			continue;
		}
		if (count == 3) {
			auto label = Label::createWithTTF("temp", text, 20);
			m_labels.insert({ num,label });
		}
	}
}

Sprite* ResourceManager::GetSpriteById(int id)
{
	auto sprite = m_sprites.find(id)->second;
	return sprite;
}

ui::Button* ResourceManager::GetButtonById(int id)
{
	auto button = m_buttons.find(id)->second;
	return button;
}

Label* ResourceManager::GetLabelById(int id)
{
	auto label = m_labels.find(id)->second;
	return label;
}
