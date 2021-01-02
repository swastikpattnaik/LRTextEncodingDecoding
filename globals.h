#ifndef _GLOBALS_H
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

/*---Header for Base64---*/
#include "mic_socket.h"

//--------------------------------------------------------------------
// Global Variables

/*---Base64 Variables---*/

char *decodedMessage;
char *sourceMessage;
char *encodedMessage;

/*---Conversion Hex to String---*/
void convert_hexparam(const char* paramName)
{
    char* src=0;
    char* psrc=0;
    char* dst = 0;
    char* pdst = 0;

    size_t srclen = 0;

    char c;
    char buf[5];

    char enclosedParamName[256];

    sprintf(enclosedParamName, "{%s}", paramName);
    src=lr_eval_string(enclosedParamName);

    srclen = strlen(src);

    dst = (char*)malloc(srclen);
    memset(dst, 0, srclen);

    for(psrc=src, pdst = dst; *psrc != '\0'; pdst++)
    {
        if(*psrc== '\\' && *(psrc + 1) == 'x')
        {
            memset(buf, 0, 5);
            buf[0] = '0';
            buf[1] = 'x';
            buf[2] = *(psrc + 2);
            buf[3] = *(psrc + 3);
            c = (char)strtol(buf, 0, 0 );

            *pdst  = c;
            psrc += 4;
        }
        else
        {
            *pdst = *psrc;
            ++psrc;
        }    
    }
    *(pdst) = '\0';

    lr_save_string(dst, paramName);

    free(dst);
}

#endif // _GLOBALS_H
