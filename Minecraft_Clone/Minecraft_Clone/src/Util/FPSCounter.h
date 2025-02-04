#pragma once

#include <../../SFML-2.5.0/include/SFML/Graphics.hpp>

class RenderMaster;

class FPSCounter {
  public:
    FPSCounter();

    void update();

    void draw(RenderMaster &renderer);

  private:
    sf::Text m_text;
    sf::Font m_font;

    sf::Clock m_delayTimer;
    sf::Clock m_fpsTimer;

    float m_fps = 0;

    int m_frameCount = 0;
};