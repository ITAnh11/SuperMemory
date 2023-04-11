#include "../HeaderFile/TextObject.h"

bool TextObject::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(g_Font, textureText.c_str(), textColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        //Create texture from surface pixels
        m_Texture = SDL_CreateTextureFromSurface(g_Renderer, textSurface);
        if (m_Texture == NULL)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            //Get image dimensions
            m_Width = textSurface->w;
            m_Height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return m_Texture != NULL;
}

TextObject::Status_Button TextObject::handleInputAction(SDL_Event event)
{
    //If mouse event happened
    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if (x < m_Pos.x)
        {
            inside = false;
        }
        //Mouse is right of the button
        else if (x > m_Pos.x + m_Width)
        {
            inside = false;
        }
        //Mouse above the button
        else if (y < m_Pos.y)
        {
            inside = false;
        }
        //Mouse below the button
        else if (y > m_Pos.y + m_Height)
        {
            inside = false;
        }
        //Mouse is outside button
        if (!inside)
        {
            return B_NONE;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch (event.type)
            {
            case SDL_MOUSEMOTION:
                return B_INSIDES;

            case SDL_MOUSEBUTTONDOWN:
                return B_PRESS;
            }
        }
    }
    return B_NONE;
}

void TextObject::setPos(const int x, const int y)
{
    m_Pos.x = x;
    m_Pos.y = y;
}
