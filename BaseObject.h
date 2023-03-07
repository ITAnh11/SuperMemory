#ifndef BASE_OBJECT_H_
#define	BASE_OBJECT_H_

#include "Common.h"

class BaseObject
{
public:
    //Initializes variables
    BaseObject();

    //Deallocates memory
    ~BaseObject();

    //Loads image at specified path
    bool loadFromFile(std::string path);

    //Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    //Set blending
    void setBlendMode(SDL_BlendMode blending);

    //Set alpha modulation
    void setAlpha(Uint8 alpha);

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //Gets image dimensions
    int getWidth();
    int getHeight();

protected:
    //The actual hardware texture
    SDL_Texture* m_Texture;

    //Image dimensions
    int m_Width;
    int m_Height;

    std::string m_fileName;
};

#endif // !BASE_OBJECT_H_

