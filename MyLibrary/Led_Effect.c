#include "Led_Effect.h"
 uint32_t time_tick_last = 0;
 uint8_t led_step =0;
 uint8_t NumberLed =0;
 Led_t *LedRun;
 uint8_t i;
 uint16_t *Count_Effect_Run;
 uint16_t NumberEffect =3;
 uint16_t CountRepeat =0;
 uint16_t valueOfCountEffectRun =0;
 void SetEffectNumber(uint16_t *EffectNumber)
 {
	  valueOfCountEffectRun = *EffectNumber;
	  valueOfCountEffectRun = *Count_Effect_Run;
	  Count_Effect_Run = EffectNumber;
	 	if(*Count_Effect_Run >= NumberEffect)
		{
			*Count_Effect_Run =0;
		}
 		CountRepeat  = 0;
		led_step =0;
		for(i =0;i<NumberLed;i++)//Reset all LED for change mode
		{
			HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i]. GPIO_Pin,GPIO_PIN_RESET);
		}
 }
 void checkForSwitchEffect()
 {
	 CountRepeat++;
	 if(CountRepeat >=5)
	 {
		(*Count_Effect_Run)++;
     SetEffectNumber(Count_Effect_Run);
	 }
 }
void sangDan(uint32_t timeDelay)
{
	if((HAL_GetTick() - time_tick_last)> timeDelay&& led_step < NumberLed)
	{
		for(i =0;i<NumberLed;i++)
		{
			if(i<= led_step)
			{
				HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i].GPIO_Pin,GPIO_PIN_SET);
			}
			else
			{
			 HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i].GPIO_Pin,GPIO_PIN_RESET);
			}
		}
		time_tick_last = HAL_GetTick();
		led_step++;
	}
	else if( (HAL_GetTick() - time_tick_last)> timeDelay &&led_step >=NumberLed)
	{
		for(i =0;i<NumberLed;i++)
		{
			HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i]. GPIO_Pin,GPIO_PIN_RESET);
		}
		time_tick_last = HAL_GetTick();
	  led_step =0;
		 checkForSwitchEffect();
	}

}
void ChopTat(uint32_t timeDelay)
{
	if((HAL_GetTick() - time_tick_last)> timeDelay&& led_step < 1)
	{
		for(i =0;i<NumberLed;i++)
		{
				HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i].GPIO_Pin,GPIO_PIN_SET);
		}
		time_tick_last = HAL_GetTick();
		led_step++;
	}
	else if( (HAL_GetTick() - time_tick_last)> timeDelay &&led_step >=1)
	{
		for(i =0;i<NumberLed;i++)
		{
			HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i]. GPIO_Pin,GPIO_PIN_RESET);
		}
		time_tick_last = HAL_GetTick();
	  led_step =0;
		checkForSwitchEffect();
	}

}
void tatDan(uint32_t timeDelay)
{
	if((HAL_GetTick() - time_tick_last)> timeDelay&& led_step < NumberLed)
	{
		for(i =0;i<NumberLed;i++)
		{
			if(i<= led_step)
			{
				HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i].GPIO_Pin,GPIO_PIN_RESET);
			}
			else
			{
			 HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i].GPIO_Pin,GPIO_PIN_SET);
			}
		}
		time_tick_last = HAL_GetTick();
		led_step++;
	}
	else if( (HAL_GetTick() - time_tick_last)> timeDelay &&led_step >=NumberLed)
	{
		for(i =0;i<NumberLed;i++)
		{
			HAL_GPIO_WritePin(LedRun[i].GPIOx,LedRun[i]. GPIO_Pin,GPIO_PIN_SET);
		}
		time_tick_last = HAL_GetTick();
	  led_step =0;
		 checkForSwitchEffect();
	}

}
void Led_Effect_Init(Led_t * Led, uint8_t LedNumber)
{
	NumberLed = LedNumber;
	LedRun = Led;
}
void Effect_Handle()
{
	valueOfCountEffectRun = *Count_Effect_Run;
	if(*Count_Effect_Run == 0)
	{
		sangDan(300);
	}
	else 	if(*Count_Effect_Run == 1)
	{
		ChopTat(300);
	}
	else if(*Count_Effect_Run == 2)
	{
	  tatDan(300);
	}
}
