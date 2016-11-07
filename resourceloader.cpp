#include "resourceloader.h"
#include "imagecontainer.h"
#include <iostream>

ResourceLoader::ResourceLoader(SDL_Renderer *renderer)
	: _renderer(renderer) {

}

void ResourceLoader::loadImage(std::string path, std::string id) const {
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "Cannot find the image\n";
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
