#include"main.h"
int custom_printf(const char *format, va_list args)
{
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;	/* Current index in the buffer*/
	int count = 0;		/* Counter for characters printed*/
	int num_str[12];	/* Move num_str declaration here*/
	int num_index, c, int_part, i, frac_part, int_index, frac_index;
	char frac_str[6];

	while (*format)
	{
		if (*format != '%')
		{
		append_to_buffer(buffer, &buffer_index, *format);
		count++;
		}
		else
		{
		format++; /* Move past '%' */

		/* Handle format specifiers (e.g., %d, %s, etc.) */
		if (*format == 's')
		{
			const char *str = va_arg(args, const char *);
			while (*str)
			{
			append_to_buffer(buffer, &buffer_index, *str);
			count++;
			str++;
			}
		}
		else if (*format == 'd' || *format == 'i')
		{
			int num = va_arg(args, int);
			num_index = 0;
			if (num == 0)
			{
				append_to_buffer(buffer, &buffer_index, '0');
				count++;
			}
			else
			{
			if (num < 0)
			{
				append_to_buffer(buffer, &buffer_index, '-');
				count++;
				num = -num;
			}
			/* Convert the integer to a string in reverse order */
			while (num > 0)
			{
				num_str[num_index++] = num % 10 + '0';
				num /= 10;
			}
			/* Append the digits in the correct order */
			for (i = num_index - 1; i >= 0; i--)
			{
				append_to_buffer(buffer, &buffer_index, num_str[i]);
				count++;
			}
			}
		}
		else if (*format == 'c')
		{
			c = va_arg(args, int); /* Use int for character */
			append_to_buffer(buffer, &buffer_index, c);
			count++;
		}
		else if (*format == 'f')
		{
			double dbl = va_arg(args, double);
			/* Assuming a fixed precision of 6 for simplicity */
			int_part = (int)dbl;
			frac_part = (int)((dbl - int_part) * 1000000); /* 6 decimal places */
			int_index = 0;
			if (int_part == 0)
			{
				append_to_buffer(buffer, &buffer_index, '0');
				count++;
			}
			else
			{
				if (int_part < 0)
				{
					append_to_buffer(buffer, &buffer_index, '-');
					count++;
					int_part = -int_part;
				}
			/* Convert the integer to a string in reverse order */
				while (int_part > 0)
				{
					num_str[int_index++] = int_part % 10 + '0';
					int_part /= 10;
				}
				/* Append the digits in the correct order */
				for (i = int_index - 1; i >= 0; i--)
				{
					append_to_buffer(buffer, &buffer_index, num_str[i]);
					count++;
				}
			}
			/* Print decimal point */
			append_to_buffer(buffer, &buffer_index, '.');
			count++;
			/* Print fractional part */
			frac_index = 0;
			while (frac_part > 0)
			{
				frac_str[frac_index++] = frac_part % 10 + '0';
				frac_part /= 10;
			}
			while (frac_index < 6)
			{
				frac_str[frac_index++] = '0'; /* Pad with zeros if necessary */
			}
			for (i = frac_index - 1; i >= 0; i--)
			{
				append_to_buffer(buffer, &buffer_index, frac_str[i]);
				count++;
			}
		}
		else if	(*format == 'R')
		{
			const char *str = va_arg(args, const char *);
			while (*str)
			{
				if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm'))
				{
					append_to_buffer(buffer, &buffer_index, *str + 13);
				}
				else if ((*str >= 'N' && *str <= 'Z') || (*str >= 'n' && *str <= 'z'))
				{
					append_to_buffer(buffer, &buffer_index, *str - 13);
				}
				else
				{
					append_to_buffer(buffer, &buffer_index, *str);
				}
				count++;
				str++;
			}
		}
		format++; /* Move past the format specifier */
		}
		format++;
	}
	flush_buffer(buffer, &buffer_index);
	return (count);

}

