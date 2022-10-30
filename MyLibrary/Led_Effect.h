#include "main.h"
typedef struct
{
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
}Led_t;
 void SetEffectNumber(uint16_t *EffectNumber);
void Effect_Handle(void);
void Led_Effect_Init(Led_t * Led, uint8_t LedNumber);
