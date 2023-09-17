#include "main.h"

int _printf(const char *format, ...)
{
	int char_print = 0;

	va_list list_of_args;
	if (format == NULL)
		return -1;
	va_start(list_of_args, format);
	while (*format)/** loop that iterates through format of strings**/
	{
		if (*format != '%')/** format is not the % sign**/
		{
			write(1, format, 1);/** write thw char to the standard output**/
			char_print++;
		}
		else/** format is the % sign**/
		{
			format++;/**skip '%' - check the next character**/ 
			if (*format == '\0')
				break;
			if (*format == '%')/** this solves %%**/
			{
				/**Handle '%%' (double %)**/
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')/**Handles %c character**/
			{	char c = va_arg(list_of_args, int);/** use of va_arg(list of arguments**/
				write(1, &c, 1);
			}
			else if (*format == 's')/**Handles %s character**/
			{
				char *str = va_arg(list_of_args, char*);
				int str_len = 0;
				
				/**calculate the length of string**/
				while (str[str_len] != '\0')
					str_len++;
				/**write the string to the standard output**/
				write(1, str, str_len);
				char_print += str_len;
			}
		}
		format++;
	}
	va_end(list_of_args);
	return char_print;
}
int main()
{
	int len;
    int len2;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
	return 0;
}
