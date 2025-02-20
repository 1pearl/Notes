#include <stdio.h>
#include <stdlib.h>
#define SUBJECT 3

typedef struct{
char name[20];
int English;
int Math;
int Major;
double Average;
int Total;
}Student;

void InputInfor(Student *students,int n) {
	int i;
	for(i=0;i<n;i++) {
		printf("请录入第%d个学生的成绩\n",i+1);
		printf("请输入学生的姓名\n");
		scanf("%s",&students[i].name);
		printf("请输入学生的英语成绩：\n");
		scanf("%d",&students[i].English);
		printf("请输入学生的数学成绩：\n");
		scanf("%d",&students[i].Math);
		printf("请输入学生的专业课成绩：\n");
		scanf("%d",&students[i].Major);
		students[i].Total=students[i].English+students[i].Math+students[i].Major;
		students[i].Average = students[i].Total/(double)SUBJECT;
	}
}

void display(Student *students,int n){
	printf("\n学生成绩统计:\n");
    printf("姓名\t数学\t英语\t专业课\t总成绩\t平均成绩\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.2f\n",
               students[i].name, students[i].Math, students[i].English, students[i].Major,
               students[i].Total, students[i].Average);
    }

    // 统计分数段人数
    printf("\n成绩分布统计:\n");
    GradeDistribution(students,n);
} 

void GradeDistribution(Student *student, int n) {
	int i;
	int grade[5] = {0};
	for(i=0;i<n;i++){
		if(student[i].Average<60){
			grade[0]++;
		} else if(student[i].Average>=60&&student[i].Average<=70){
			grade[1]++;
		} else if(student[i].Average>=70&&student[i].Average<=80){
			grade[2]++;
		} else if(student[i].Average>=80&&student[i].Average<=90){
			grade[3]++;
		} else {
			grade[4]++;
		}
	}
	printf("平均成绩小于60的人数有：%d\n",grade[0]);
	printf("平均成绩大于等于60小于等于70的人数有：%d\n",grade[1]);
	printf("平均成绩大于等于70小于等于80的人数有：%d\n",grade[2]);
	printf("平均成绩大于等于80小于等于90的人数有：%d\n",grade[3]);
	printf("平均成绩大于90的人数有：%d\n",grade[4]);
}

int main(){
	printf("要录入学生成绩的人数为:");
	int n,i;
	Student *students;
	scanf("%d",&n);
	students = (Student*)malloc(sizeof(Student)*n);
	InputInfor(students,n);
	display(students,n);
	free(students);
	students = NULL;
	return 0;
} 
