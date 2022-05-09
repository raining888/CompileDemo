#include <iostream>
#include <stdlib.h>
#include "max_score.h"
#include "mean.h"

using namespace std;

int main()
{
  /*<** 定义10个学生的成绩和名字 */
  student_grade stuA[MAX_STUDENT_NUM] = \ 
  {
    {"A",45.},{"B",57.},{"C",87.},{"D",35.},{"E",86.},
      {"F",28.},{"G",76.},{"H",90.},{"I",29.},{"J",47.}
  };

  student_grade stu= max_score(stuA,MAX_STUDENT_NUM);
  cout << stu.name << ":"<< stu.Chinese << endl;
  float mean_s = mean(stuA,MAX_STUDENT_NUM);
  cout << mean_s << endl;
  return 0;
}
