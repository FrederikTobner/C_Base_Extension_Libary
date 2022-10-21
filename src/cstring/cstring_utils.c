#include "cstring_utils.h"

#include <string.h>
#include <stdint.h>

static void cstring_utils_behead(char *);

// Checks if a string contains the specified character restricted the specified length
bool cstring_utils_contains_character_restricted(char const * text, char character, size_t length)
{
    for (size_t i = 0u; i < length; i++)
    {
        if (!*(text + i))
            return false;
        if (*(text + i) == character)
            return true;
    }
    return false;
}

void cstring_reverse(char * str)
{
	size_t counter;
	char tmp = 0;
    size_t string_length = strlen(str);
    size_t loopUpperBound =  string_length / 2;
	for (counter = 0; counter < loopUpperBound; counter++)
	{
		tmp = str[counter];
		str[counter] = str[string_length - 1 - counter];
		str[string_length - 1 - counter] = tmp;
	}
}


void cstring_trim(char * str)
{
	while (str[0] == ' ')
		cstring_utils_behead(str);
	for (size_t i = strlen(str); i > 0; i--)
	{
		if (str[i] != ' ')
			break;
		str[i] = '\0';
	}
}

// Resolves all the escape sequences inside a string literal
int cstring_utils_resolve_escape_sequence(char * text)
{
    cstring_utils_behead(text);
    switch (*text)
    {
    // escape sequence using a number in octal format
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
        {
            uint32_t octalValue = 0u;
            uint8_t octalLoopCounter = 1u;
            do
            {
                octalValue *= 8u;
                octalValue += *text -'0';
                if(!(*(text + 1) >= '0' && *(text + 1) <= '7'))
                    break; // No octal number ahead
                cstring_utils_behead(text);
            } while (octalLoopCounter++ < 3);
            if(octalValue > 255)
                return -1;
            if(octalLoopCounter == 4)
                return -1;
            *text = (char)octalValue;
            break;
        }
    // escape sequence using a number in hexadezimal format
    case 'x':
        {
            uint32_t hexValue = 0u;
            uint8_t hexLoopCounter = 1u;
            cstring_utils_behead(text);
            if(!(*text >= '0' && *text <= '9') && !(*(text + 1) >= 'a' && *(text + 1) <= 'f'))
                return -1;
            do
            {
                hexValue *= 16u;            
                hexValue += *text > '9' ? *text - 'a' + 10 : *text -'0';
                if(!(*(text + 1) >= '0' && *(text + 1) <= '9') && !(*(text + 1)>= 'a' && *(text + 1) <= 'f'))
                    break; // No hexadezimal number ahead
                cstring_utils_behead(text);
            } while (hexLoopCounter++ < 2);
            if(hexLoopCounter == 3)
                return -1;
            *text = (char)hexValue;
            break;
        }
    // Alarm or beep
    case 'a':
        *text = '\a';
        break;
    // Backspace
    case 'b':
        *text = '\b';
        break;
    // formfeed page break
    case 'f':
        *text = '\f';
        break;
    // New Line
    case 'n':
        *text = '\n';
        break;
    // Carriage Return
    case 'r':
        *text = '\r';
        break;
    // Tab Horizontal
    case 't':
        *text = '\t';
        break;
    // Tab vertical
    case 'v':
        *text = '\v';
        break;
    // Backslash, single and double quote
    case '\"':
        break;
    case '\'':
        break;
    case '\\':
        break;
    case '?':
        *text = '\?';
        break;
    default:
        return -1;
    }
    return 0;    
}

// Removes the first character in a sequence of characters
static void cstring_utils_behead(char * text)
{
    size_t stringLength = strlen(text);
    for (size_t j = 0u; j < stringLength; j++)
        *(text + j) = *(text + j + 1);
    *(text + stringLength) = '\0';
}