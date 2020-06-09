/****************************************************************************
 *  Имя файла: Timer.h
 *  Описание:
 *      - Имплементация для таймера и регулировщика кадров в секунду
 *  Автор: Рощин Константин
*****************************************************************************/

#include "Timer.h"
#include "main.h"

#define TARGET_FPS 30.0f

Uint32 timeSinceStart = 0;

namespace Timer
{
  unsigned __int32 GetCurrentTime()
  {
    return SDL_GetTicks();
  }

  namespace FPS
  {
    void ForseFrameRate()
    {
      Uint32 currTimer = GetTimeSinceFrameStart();
      Uint32 dt = currTimer - timeSinceStart;
      Uint32 target = (((1.0f / TARGET_FPS)) * 1000);
      Uint32 delayAmount = target - dt;
      if (dt > target)
      {
        return;
      }
      SDL_Delay(delayAmount);
    }

    unsigned __int32 GetTimeSinceFrameStart()
    {
      return SDL_GetTicks();
    }

    unsigned __int32 GetTimeAtFrameStart()
    {
      timeSinceStart = GetTimeSinceFrameStart();
      return timeSinceStart;
    }


  }

}


