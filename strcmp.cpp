#include <iostream>

int MyStrcmp(const char *s1, const char *s2)
{
    const char *c1 = s1;
    const char *c2 = s2;
    
    while (*c1 != '\0' && *c2 != '\0') {
        int d = *c1 - *c2;
        if (d)
            return d;
        c1++;
        c2++;
    }
    if (*c1 != '\0')
        return *c1;
    if (*c2 != '\0')
        return -(*c2);
    return 0;
}

int main(int argc, char *argv[])
{
    std::cout << MyStrcmp(argv[1], argv[2]) << std::endl;
}

