#ifndef COMMONAPI_H
#define COMMONAPI_H

#include <iostream>
using namespace std;
#define LOG_COMMON(fmt,...) \
        if (LOG_ON == g_LogLevel)\
        {\
            printf("(%d)-<%s>: "##fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
            cout<<endl;\
        }\
        else {}
#define LOG_WITH_INFO(fmt,...) \
        if (LOG_ON == g_LogLevel)\
        {\
            printf("%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
        }\
        else {}
#define NULL_INT 0xffff
#define MAX(_a, _b) (_a > _b) ? _a : _b
#define AbsDiff(_a, _b) (_a > _b) ? (_a- - _b) : (_b - _a)
#define NULL_PTR_LOG(_ptr) if (NULL == _ptr)\
                            {\
                                LOG_COMMON("null ptr");\
                                return false;\
                            }
#define NULL_PTR_LOG_VOID(_ptr) if (NULL == _ptr)\
                                 {\
                                     LOG_COMMON("null ptr");\
                                     return;\
                                 }
#define NULL_PTR_LOG_NULL(_ptr) if (NULL == _ptr)\
                                 {\
                                     LOG_COMMON("null ptr");\
                                     return NULL;\
                                 }
#define NULL_PTR_LOG_INT(_ptr) if (NULL == _ptr)\
                                 {\
                                     LOG_COMMON("null ptr");\
                                     return 0;\
                                 }

enum enLogSwitch
{
    LOG_ON, // 0
    LOG_OFF // 1
};

extern enum enLogSwitch g_LogLevel;
#endif // !COMMONAPI_H