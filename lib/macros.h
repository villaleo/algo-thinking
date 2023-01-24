#ifndef INTERVIEW_PROBLEMS_MACROS_H
#define INTERVIEW_PROBLEMS_MACROS_H

#define func auto
#define let auto
#define unpack auto
#define in :
#define move &&
#define capture(...) [__VA_ARGS__]
#define lambda capture()
#define iter(a) a.begin(), a.end()

#endif //INTERVIEW_PROBLEMS_MACROS_H
