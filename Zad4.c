#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    DIR* dir;
    FILE* file;
    struct dirent* dir_ent;
    struct stat statbuf;

    if (opendir("results") == NULL)
    {
        if (mkdir("results", 0777) == -1)
        {
            perror("Błąd tworzenia katalogu");
            return 1;
        }
    }
    
    if ((dir = opendir("/etc")) == NULL)
    {
        perror("Błąd otwierania katalogu");
        return 2;
    }
    
    if ((file = fopen("results/etc_dir.out", "w")) == NULL)
    {
        perror("Błąd tworzenia/otwieranie pliku");
        return 3;
    }
    
    rewinddir(dir);
    while (dir_ent = readdir(dir))
    {
        if (dir_ent->d_type == DT_DIR)
        {
            fputs(dir_ent->d_name, file);
            fputc('\n', file);
        }
    }

    if (closedir(dir) != 0)
    {
        perror("Błąd zamykania katalogu");
        return 4;
    }
    if (fclose(file) != 0)
    {
        perror("Błąd zamykania pliku");
        return 5;
    }

    if ((dir = opendir("/etc/sysconfig")) == NULL)
    {
        perror("Błąd otwierania katalogu");
        return 6;
    }

    if ((file = fopen("results/sysconfig.out", "w")) == NULL)
    {
        perror("Błąd tworzenia/otwieranie pliku");
        return 7;
    }

    rewinddir(dir);
    while (dir_ent = readdir(dir))
    {
        if (dir_ent->d_type == DT_REG)
        {
            char path[] = "/etc/sysconfig/";
            stat(strcat(path, dir_ent->d_name), &statbuf);
            if (!(statbuf.st_mode & S_IRWXO))
            {
                fputs(dir_ent->d_name, file);
                fputc('\n', file);
            }
        }
    }

    if (closedir(dir) != 0)
    {
        perror("Błąd zamykania katalogu");
        return 8;
    }
    if (fclose(file) != 0)
    {
        perror("Błąd zamykania pliku");
        return 9;
    }

    return 0;
}