/*2351495 大数据 闫业豪*/

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    const char* p = str;
    while (*p != '\0')
        p++;
    return p - str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL || s2 == NULL)
        return s1;
    char* p1 = s1;
    const char* p2 = s2;
    while (*p1 != '\0')
        p1++;
    while (*p2 != '\0') 
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL || s2 == NULL || len <= 0)
        return s1;
    char* p1 = s1;
    const char* p2 = s2;
    int count = 0;
    while (*p1 != '\0')
        p1++;
    while (*p2 != '\0' && count < len) 
    {
        *p1 = *p2;
        p1++;
        p2++;
        count++;
    }
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL) 
    {
        *s1 = '\0';
        return s1;
    }
    char* p1 = s1;
    const char* p2 = s2;
    while (*p2 != '\0') 
    {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL || len <= 0)
        return s1;
    char* p1 = s1;
    const char* p2 = s2;
    int count = 0;
    while (*p2 != '\0' && count < len) 
    {
        *p1 = *p2;
        p1++;
        p2++;
        count++;
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) 
    {
        p1++;
        p2++;
    }
    return *p1 - *p2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    while (*p1 != '\0' && *p2 != '\0') 
    {
        char c1 = *p1;
        char c2 = *p2;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 = c1 - 'A' + 'a';
        if (c2 >= 'A' && c2 <= 'Z')
            c2 = c2 - 'A' + 'a';
        if (c1 != c2)
            return c1 - c2;
        p1++;
        p2++;
    }
    char c1 = *p1;
    char c2 = *p2;
    if (c1 >= 'A' && c1 <= 'Z')
        c1 = c1 - 'A' + 'a';
    if (c2 >= 'A' && c2 <= 'Z')
        c2 = c2 - 'A' + 'a';
    return c1 - c2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (len <= 0)
        return 0;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    int count = 0;
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2 && count < len)
    {
        p1++;
        p2++;
        count++;
    }
    if (count >= len)
        return 0;
    return *p1 - *p2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (len <= 0)
        return 0;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1;
    const char* p2 = s2;
    int count = 0;
    while (*p1 != '\0' && *p2 != '\0' && count < len)
    {
        char c1 = *p1;
        char c2 = *p2;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 = c1 - 'A' + 'a';
        if (c2 >= 'A' && c2 <= 'Z')
            c2 = c2 - 'A' + 'a';
        if (c1 != c2)
            return c1 - c2;
        p1++;
        p2++;
        count++;
    }
    if (count >= len)
        return 0;
    char c1 = *p1;
    char c2 = *p2;
    if (c1 >= 'A' && c1 <= 'Z')
        c1 = c1 - 'A' + 'a';
    if (c2 >= 'A' && c2 <= 'Z')
        c2 = c2 - 'A' + 'a';
    return c1 - c2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* p = str;
    while (*p != '\0') 
    {
        if (*p >= 'a' && *p <= 'z')
            *p = *p - 'a' + 'A';
        p++;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* p = str;
    while (*p != '\0') 
    {
        if (*p >= 'A' && *p <= 'Z')
            *p = *p - 'A' + 'a';
        p++;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    const char* p = str;
    int pos = 1; 
    while (*p != '\0') 
    {
        if (*p == ch)
            return pos;
        p++;
        pos++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return 0;
    const char* p1 = str;
    int pos = 1;
    while (*p1 != '\0') 
    {
        const char* start = p1;
        const char* p2 = substr;
        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) 
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
            return pos;
        p1 = start + 1;
        pos++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;

    const char* p = str;
    int last_pos = 0;
    int pos = 1;
    while (*p != '\0') 
    {
        if (*p == ch)
            last_pos = pos;
        p++;
        pos++;
    }
    return last_pos;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return 0;
    const char* p1 = str;
    int last_pos = 0;
    int pos = 1;
    while (*p1 != '\0') 
    {
        const char* start = p1;
        const char* p2 = substr;
        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) 
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
            last_pos = pos;
        p1 = start + 1;
        pos++;
    }
    return last_pos;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* start = str;
    char* end = str;
    while (*end != '\0')
        end++;
    end--;
    while (start < end) 
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}