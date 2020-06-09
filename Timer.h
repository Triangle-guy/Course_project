/****************************************************************************
 *  Имя файла: Timer.h
 *  Описание:
 *      - Интерфейс для таймера и регулировщика кадров в секунду
 *  Автор: Рощин Константин
*****************************************************************************/

namespace Timer
{

  unsigned __int32 GetCurrentTime();

  namespace FPS
  {
    void ForseFrameRate();
    unsigned __int32 GetTimeSinceFrameStart();
    unsigned __int32 GetTimeAtFrameStart();
  }

}




