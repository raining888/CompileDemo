#ifndef BASE
#define BASE

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_STUDENT_NUM 10 /*<**定义学生数*/

  /*<** 学生成绩的结构体 */
  typedef struct grade
  {
    char name[8]; // 名字
    float Chinese; // 语文成绩
  }student_grade,*pstudent_grade;

#ifdef __cplusplus
}
#endif

#endif
