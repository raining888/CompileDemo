#include "max_score.h"

#ifdef __cplusplus
extern "C" {
#endif

  /*<** 求解最高分的函数定义*/ 
  student_grade max_score(student_grade p[],int lenth)
  {
    student_grade tmp = {"R",0.};
    for(int i = 0 ; i < lenth ; i++)
    {
      if(p[i].Chinese > tmp.Chinese)
        tmp.Chinese = p[i].Chinese;
    }
    return tmp;
  }

#ifdef __cplusplus
}
#endif
