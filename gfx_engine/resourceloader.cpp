#include "resourceloader.h"
#include "resourcecontainer.h"
#include <iostream>

ResourceLoader::ResourceLoader(SDL_Renderer *renderer)
	: _renderer(renderer) {

}

void ResourceLoader::loadImage(std::string path, std::string id) const {
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "Cannot find the image: " << path.c_str() << std::endl;
		return;
	}

	SDL_Texture *_texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);

	SDL_FreeSurface(loadedSurface);
	if (_texture == nullptr) {
		std::cout << "Cannot create texture";
		return;
	}

	ResourceContainer::imageContainer[id] = _texture;
}

void ResourceLoader::loadFont(std::string path, std::string id) const
{
	TTF_Font *font = TTF_OpenFont(path.c_str(), 20);
	if (font == NULL) {
		std::cout << "Cannot find the font: " << path.c_str() << std::endl;
		return;
	}
	ResourceContainer::fontContainer[id] = font;
}
