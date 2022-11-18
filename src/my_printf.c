#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <stdint.h>
#include "../includes/my_printf.h" // ma lib
#include "../includes/my_putchar.h" // ma lib

int my_printf(char* format, ...) {
    int print_count = 0;
    va_list vl;
    va_start(vl,format);
    for (int i = 0; format[i] != 0; i++) { 
        if (format[i] == '%') {
            i++;
            if (format[i] == '%') { 
                my_putchar(format[i]);
                print_count++;
            }
            else if (format[i] == 'd'|| format[i] == 'o' || format[i] == 'u' || format[i] == 'x') {
                int val;
                val=va_arg(vl,int);
                int negative = 0;

                if (val == 0) {
                    my_putchar(48);
                    print_count++;
                    continue;
                }
                else if (val < 0) {
                    val *= -1;
                    negative = 1;
                }
                int temp = 0;
                if (format[i] == 'd' || format[i] == 'u') {
                    while (val != 0) {
                        temp *= 10;
                        temp += val % 10;
                        val /= 10;
                    }
                    if (negative == 1 && format[i] != 'u') {
                        my_putchar('-');
                        print_count++;
                    }
                    while (temp != 0) {
                        my_putchar(48+(temp % 10));
                        print_count++;
                        temp /= 10;
                    }
                }
                else if (format[i] == 'x') {
                    char hexdecnum[100];
                    int j = 0;
                    while (val != 0) { 
                        temp = val % 16; 
                        if (temp < 10) { 
                            temp += 48; 
                        } 
                        else { 
                            temp += 87; 
                        } 
                        hexdecnum[j] = temp; 
                        j++;
                        val = val / 16; 
                    }
                    for ( ; j >= 0; j--) {
                        my_putchar(hexdecnum[j]);
                        print_count++;
                    }
                }
                else if (format[i] == 'o') {
                    char octdecnum[100];
                    int j = 0;
                    while (val != 0) { 
                        temp = val % 8; 
                        if (temp < 10) { 
                            temp += 48; 
                        } 
                        else { 
                            temp += 87; 
                        } 
                        octdecnum[j] = temp; 
                        j++;
                        val = val / 8; 
                    }
                    for ( ; j >= 0; j--) {
                        my_putchar(octdecnum[j]);
                        print_count++;
                    }
                }
            }
            else if (format[i] == 'c') {
                char val;
                val=va_arg(vl,int);
                my_putchar(val);
                print_count++;
            }
            else if (format[i] == 's') {
                char* val;
                val=va_arg(vl,char*);
                for (int j = 0; val[j] != 0; j++) {
                    my_putchar(val[j]);
                    print_count++;
                }
            }
            else if (format[i] == 'p') {
                void* val;
                val=va_arg(vl,void*);

                uintptr_t x = (uintptr_t)val;

                int temp = 0;
                char hexdecnum[100];
                int j = 0;
                while (x != 0) { 
                    temp = x % 16; 
                    if (temp < 10) { 
                        temp += 48; 
                    } 
                    else { 
                        temp += 87; 
                    } 
                    hexdecnum[j] = temp; 
                    j++;
                    x = x / 16; 
                }
                my_putchar('0');
                print_count++;
                my_putchar('x');
                print_count++;
                for (j-- ; j >= 0; j--) {
                    my_putchar(hexdecnum[j]);
                    print_count++;
                }
            }
        }
        else {
            my_putchar(format[i]);
            print_count++;
        }
    }
    va_end(vl);
    return print_count;
}