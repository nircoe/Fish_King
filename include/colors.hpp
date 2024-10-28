#pragma once

#include "raylib-cpp.hpp"
#include <vector>

namespace Colors
{

    #define VERY_LIGHT_OCEAN    CLITERAL(Color){ 222, 243, 246, 255 }     // Very Light Ocean
    #define LIGHT_OCEAN         CLITERAL(Color){ 29, 162, 216, 255 }      // Light Ocean
    #define OCEAN               CLITERAL(Color){ 127, 205, 255, 255 }     // Ocean
    #define DARK_OCEAN          CLITERAL(Color){ 118, 182, 196, 255 }     // Dark Ocean
    #define VERY_DARK_OCEAN     CLITERAL(Color){ 6, 66, 115, 255 }        // Very Dark Ocean

    const std::vector<Color> OCEAN_PALETTE = { VERY_LIGHT_OCEAN, LIGHT_OCEAN, OCEAN, DARK_OCEAN, VERY_DARK_OCEAN }; // Ocean Color Palette


    Color TransitionColorPalette(const std::vector<Color>& colorPalette, const float transitionDuration, float& timeElapsed, int& index, bool& goingForward)
    {
        timeElapsed += GetFrameTime();

        int nextIndex = goingForward ? index + 1 : index - 1;
        nextIndex = std::clamp(nextIndex, 0, static_cast<int>(colorPalette.size() - 1));

        float t = timeElapsed / (transitionDuration / (colorPalette.size() - 1));
        if(t > 1.0f)
            t = 1.0f;
        
        Color currentColor = {  static_cast<unsigned char>(colorPalette[index].r + t * (colorPalette[nextIndex].r - colorPalette[index].r)),
                                static_cast<unsigned char>(colorPalette[index].g + t * (colorPalette[nextIndex].g - colorPalette[index].g)),
                                static_cast<unsigned char>(colorPalette[index].b + t * (colorPalette[nextIndex].b - colorPalette[index].b)),
                                255};
        
        if(timeElapsed >= transitionDuration)
        {
            timeElapsed = 0.0f;
            index = nextIndex;
            if(index == colorPalette.size() - 1 || index == 0)
                goingForward = !goingForward;
        }

        return currentColor;
    }

    // make TransitionColorPalette based on x or y axis position (go deeper in the ocean will become darker)
}