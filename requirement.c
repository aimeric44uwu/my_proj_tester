/*
** EPITECH PROJECT, 2022
** my_proj_tester
** File description:
** requirement.c
*/

extern char **environ;

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/wait.h>

static char *my_open_dir(struct dirent *dir, DIR *d, char *path)
{
    char* resulttoexec;

    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, "ps") == 0) {
            resulttoexec = malloc(sizeof(char) *
                (strlen(path) + strlen(dir->d_name) + 2));
            strcat(resulttoexec, path);
            strcat(resulttoexec, "/");
            strcat(resulttoexec, dir->d_name);
            return resulttoexec;
        }
    }
    return NULL;
}

static char *findpathtoexec(char **path_components)
{
    DIR *d;
    char* resulttoexec;
    struct dirent *dir;

    for (int i = 0; &path_components[i] != NULL; i++) {
        d = opendir(path_components[i]);
        if (!d)
            continue;
        resulttoexec = my_open_dir(dir, d, path_components[i]);
        if (resulttoexec != NULL) {
            closedir(d);
            return resulttoexec;
        }
    }
    closedir(d);
    return "\0";
}

char **my_str_to_word_array(char const *str, char const *sep)
{
    char **tab = NULL;
    int j = 0;
    int k = 0;

    tab = malloc(sizeof(char *) * (strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (strncmp(&str[i], sep, strlen(sep)) == 0) {
            tab[j][k] = '\0';
            j++;
            k = 0;
        } else {
            tab[j] = realloc(tab[j], sizeof(char) * (strlen(str) + 1));
            tab[j][k] = str[i];
            k++;
        }
    }
    tab[j][k] = '\0';
    tab[j + 1] = NULL;
    return (tab);
}

char *get_path_var(void)
{
    char *pathvar = NULL;
    char *env_var;

    while ((env_var = *environ++) != NULL) {
        if (strncmp(env_var, "PATH=", 5) == 0) {
            pathvar = &env_var[5];
            break;
        }
    }
    return pathvar;
}

void my_ps_synthesis(void)
{
    char *pathvar = get_path_var();
    char **path_components = NULL;
    char *toexecute = NULL;
    int status;
    int childpid;

    path_components = my_str_to_word_array(pathvar, ":");
    toexecute = findpathtoexec(path_components);
    childpid = fork();
    if (childpid == -1) {
        printf("Error: fork failed\n");
        return;
    } else if (childpid == 0) {
        execve(toexecute, NULL, environ);
    } else {
        wait(&status);
        return;
    }
}
