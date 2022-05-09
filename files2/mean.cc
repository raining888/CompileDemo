#include "mean.h"

#ifdef __cplusplus
extern "C" {
#endif

  /*<** 求解平均分的函数的定义*/
  float mean(student_grade p[],int lenth)
  {
    float tmp;
    for(short i = 0 ; i < lenth ; i++)
      tmp += p[i].Chinese;
    return tmp / float(lenth);
  }

#ifdef __cplusplus
}
#endif
