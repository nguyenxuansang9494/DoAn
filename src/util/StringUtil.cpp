#include <StringUtil.h>


int std::splitstr(const char* src, char delim, char **&result) {
    int count = 1;
    int length = 0;
    for (; src[length] != 0; length++) {
        count += src[length] == delim ? 1 : 0;
    }
    result = new char*[count];
    for (int i = 0, j = 0, start_point = 0; i <= length; i++) {
        if (src[i] == delim || src[i] == 0) {
            result[j] = new char[i+1 - start_point];
            start_point = i+1;
            j++;
        }
    }
    for (int i = 0, j = 0, ji = 0; i <= length; i++) {
        if (src[i] == delim || src[i] == 0){
            result[j][ji] = 0;
            j++;
            ji=0;
            continue;
        }
        result[j][ji] = src[i];
        ji++;
    }
    return count;
}