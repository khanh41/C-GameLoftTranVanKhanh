#include "cocos2d.h"
#include<string>
#include<map>
#include <ui\CocosGUI.h>
class ResourceManager
{
public:
	ResourceManager* s_instance;
	std::string m_dataFolderPath;
	std::map<char, Sprite*> m_sprites;
	std::map<char, ui::Button*> m_buttons;
	std::map<char, Label*> m_labels;
public:
	ResourceManager();
	~ResourceManager();
	ResourceManager* GetInstance();
	void Init(const std::string path);
	void Load(std::string fileName);
	Sprite* GetSpriteById(char id);
	ui::Button* GetButtonById(char id);
	Label* GetLabelById(char id);
};

