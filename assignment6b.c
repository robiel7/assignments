#include <stdio.h>
#include <math.h>

float getAverageForStudent(float[20][10], int, int);
float getAverageForAssignment(float[20][10], int, int);
float getStandardDeviationForAssignment(float[20][10], int, int);
float getStandardDeviationForAverage(float[20], int);
void printScores(char[20][50],float[20][10], int, int);
FILE *file;

int main(){
  int student,assignment,i,j;
  char students[20][50];
  float score[20][10];
  do{
    printf("How many students are there (between 1 and 20)? ");
    scanf("%d",&student);
  }while((student < 1)|| (student > 20));
  do{
    printf("How many assignments are there (between 1 and 10)? ");
    scanf("%d", &assignment);
  }while((assignment < 1)|| (assignment > 10));
   printf("\n");

  for ( i = 0; i < student; i++) {
    printf("Student name: ");
    scanf("%s",students[i]);
    for ( j = 0; j < assignment; j++){
      printf("Assignment %d : ",j+1);
      scanf("%f",&score[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  file = fopen("resultat.txt","a");
  printScores(students,score, student, assignment);
  
  return 0;
}

float getAverageForStudent(float score[20][10], int student, int assignment){
  int i;
  float total = 0,avg;
  for (i = 0; i < assignment; i++){
    total += score[student][i];
  }
    avg = total/assignment; 
  return avg ;
}

float getAverageForAssignment(float score[20][10], int student, int assignment){
  int i;
  float total = 0,avg;
  for (i = 0; i < student; i++){
    total += score[i][assignment];
  }
    avg = total/student; 
  return avg ;
}

float getStandardDeviationForAssignment(float score[20][10],int student,int assignment){ 
  int i;
  float avg,variance = 0,stdvn,total = 0,x;
  for (i = 0; i < student; i++){
    total += score[i][assignment];
  }
    avg = total/student; 

  for (i = 0; i < student; i++){
      x = pow((score[i][assignment] - avg),2);
      variance += x ;  
  }

  stdvn = variance / (student-1);
  stdvn = sqrt(stdvn);
  return stdvn ;
}

float getStandardDeviationForAverage(float average_student[20], int student){

  int i;
  float avg,variance = 0,stdvn,total = 0,x;
  for (i = 0; i < student; i++){
    total += average_student[i];
  }
    avg = total/student; 

  for (i = 0; i < student; i++){
      x = pow((average_student[i]- avg),2);
      variance += x ;  
  }

  stdvn = variance / (student-1);
  stdvn = sqrt(stdvn);
  return stdvn ;

}

void printScores(char students[20][50],float score[20][10],int student,int assignment){
  int i,j;
  float totalAssignment = 0, avgAssignment,stdD;
  float average_student[20];

  fprintf(file,"Name\t");
  for ( i = 0; i < assignment; i++){
    fprintf(file,"Assn%d\t",i+1);
  }
  fprintf(file,"Average\n");

  for (i = 0; i < student; i++){
    fprintf(file,"%s",students[i]);
    for (j = 0; j < assignment; j++){
      fprintf(file,"\t%.0f\t",score[i][j]);
    }
    average_student[i] = getAverageForStudent(score, i, assignment);
    fprintf(file,"\t%.2f",getAverageForStudent(score, i, assignment));
    fprintf(file,"\n");
  }
  fprintf(file,"\n");
  fprintf(file,"Avg ");
  for ( i = 0; i < assignment; i++){
    totalAssignment += getAverageForAssignment(score, student, i);
    fprintf(file,"\t%.2f",getAverageForAssignment(score, student, i));
  }
  avgAssignment = totalAssignment / assignment;
  fprintf(file,"\t%.2f",avgAssignment);
  fprintf(file,"\n");

  fprintf(file,"stdD");
  for ( i = 0; i < assignment; i++){
    fprintf(file,"\t%.2f",getStandardDeviationForAssignment(score, student, i));
  }
  stdD = getStandardDeviationForAverage(average_student, student);
  fprintf(file,"\t%.2f\n\n\n",stdD);
  
}