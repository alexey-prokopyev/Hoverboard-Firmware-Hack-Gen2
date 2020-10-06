#ifndef LOG_H
#define LOG_H

#include "../Inc/commsMasterSlave.h"
#include "../Inc/defines.h"
#include "../Inc/comms.h"
#include "../Inc/it.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

char log_buffer[1024];

bool Log(const char* format_string, ...)
{
	int length0;
	int length;
	float ms;
	ms = millis() / 1000.0;
	length0 = sprintf(log_buffer, "%.3f| ", ms); 
	//length0 = 0;
	{
  va_list ap;
  va_start(ap, format_string);  
	length = vsnprintf(log_buffer + length0, sizeof(log_buffer) - length0, format_string, ap);
  va_end(ap);
	}
  
  SendBuffer(USART_STEER_COM, (uint8_t*)log_buffer, length + length0);
}


#endif
