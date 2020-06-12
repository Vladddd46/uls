#include "uls.h"

/*
Функция принимает айди пользователя
и возвращает 

логин
*/

char *mx_getuser(uid_t uid) {
    struct passwd *pws;

    pws = getpwuid(uid);
    return pws->pw_name;
}
