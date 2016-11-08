#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <map>

class ResourceContainer {
public:
	static std::map<std::string, SDL_Texture*> imageContainer;
	static std::map<std::string, TTF_Font*> fontContainer;
};

#endif // IMAGECONTAINER_H
