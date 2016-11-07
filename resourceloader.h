#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <string>
#include <SDL2/SDL.h>

class ResourceLoader
{
public:
	ResourceLoader(SDL_Renderer *renderer);
	void loadImage(std::string path, std::string id) const;
private:
	SDL_Renderer *_renderer;
};

#endif // RESOURCELOADER_H
