#ifndef IMAGECONTAINER_H
#define IMAGECONTAINER_H

#include <SDL2/SDL_image.h>
#include <map>

class ResourceContainer {
public:
	static std::map<std::string, SDL_Texture*> imageContainer;
};

#endif // IMAGECONTAINER_H
