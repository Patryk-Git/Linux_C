#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char* intToStr(int number, char buffor[])
{
    char const digit[] = "0123456789";
    char* p = buffor;
    if (number < 0)
    {
        *p++ = '-';
        number *= -1;
    }
    int shifter = number;
    do
    {
        ++p;
        shifter = shifter / 10;
    } while (shifter);
    *p = '\0';
    do
    {
        *--p = digit[number % 10];
        number /= 10;
    } while (number);
    return buffor;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        return 2;
    }

    int tab[10];
    read(fd, tab, sizeof(tab));

    close(fd);

    char buffor[5];
    for (int i = 0; i < 10; i++)
    {
        tab[i] *= 3;
        write(1, intToStr(tab[i], buffor), sizeof(buffor));
        write(1, "\n", 1);
    }

    return 0;
}