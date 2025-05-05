#include "../utils/assert.h"

// string.h : https://zh.cppreference.com/w/c/header/string

// TODO: implement following func in string.h

char* strcpy(char* dest, const char* src) {

}

char* strncpy(char* dest, const char* src, size_t len) {

}

char* strcat(char* dest, const char* src) {

}

char* strncat(char* dest, const char* src, size_t count) {

}

size_t strlen(const char* str) {

}

int strcmp(const char* lhs, const char* rhs) {

}

int strncmp(const char* lhs, const char* rhs, size_t count) {

}

char* strchr(const char* str, int ch) {

}

char* strrchr(const char* str, int ch) {

}

size_t strspn(const char* dest, const char* src) {

}

size_t strcspn(const char* dest, const char* src) {

}

char* strpbrk(const char* dest, const char* breakset) {

}

char* strstr(const char* str, const char* substr) {

}

char* strtok(char* str, const char* delim) {

}

int main(int argc, char* *argv) {
    {
        const char src[20] = "hello";
        char dst[20] = {};
        char* ret = strcpy(dst, src);
        ASSERT(!strcmp(src, dst) && !strcmp(ret, src));
    }

    {
        const char src[20] = "hello world";
        char dst[20] = {};
        char* ret = strncpy(dst, src, 5);
        ASSERT(!strncmp(src, dst, 5) && !strcmp(ret, src, 5));
    }

    {
        const char src[20] = "hello ";
        char dst[20] = "world";
        char* ret = strcat(dst, src);
        ASSERT(!strncmp(src, "hello world"));
    }

    {
        const char src[20] = "hello ";
        char dst[20] = "world";
        char* ret = strncat(dst, src, 3);
        ASSERT(!strncmp(src, "hello wor"));
    }

    {
        ASSERT(strlen(NULL) == 0);
        ASSERT(strlen("hello") == 5);
    }

    {
        const char src[20] = "hello world";
        ASSERT(*strchr(src, ' ') == ' ');
        ASSERT(*strchr(src, 'h') == 'h');
        ASSERT(*strchr(src, 'd') == 'd');
    }

    {
        const char src[20] = "hello world";
        ASSERT(*strrchr(src, ' ') == ' ');
        ASSERT(*strrchr(src, 'h') == 'h');
        ASSERT(*strrchr(src, 'd') == 'd');
    }

    {
        const char src[20] = "hello world";
        ASSERT(strspn(src, "") == 0,);
        ASSERT(strspn(src, "he") == 2);
        ASSERT(strspn(src, 'h') == 1);
        ASSERT(strspn(src, 'ho') == 1);
    }

    {
        const char src[20] = "hello world";
        ASSERT(strcspn(src, "") == 11,);
        ASSERT(strcspn(src, "wo") == 6);
        ASSERT(strcspn(src, "rl") == 4);
        ASSERT(strcspn(src, " ") == 5);
    }

    {
        const char src[20] = "hello world";
        ASSERT(strpbrk(src, "") == 11,);
    }

    {
        const char src[20] = "hello world";
        ASSERT(strstr(src, "") == 11,);
    }

    {
        const char src[20] = "hello world";
        ASSERT(strtok(src, "") == 11,);
    }

    return 0;
}
