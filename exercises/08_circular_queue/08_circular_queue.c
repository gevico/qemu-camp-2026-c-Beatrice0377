#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 50

typedef struct {
    int id;
} People;

typedef struct {
    People data[MAX_PEOPLE];
    int head;
    int tail;
    int count;
} Queue;

int main() {
    Queue q;
    int total_people=50;
    int report_interval=5;
	for(int i=0;i<total_people;i++){
		q.data[i].id=i+1;
	}
    q.head=0;
	q.tail=49;
	q.count=50;
    int report_num=1;
    while(q.count>1){
        if(report_num==report_interval){
            printf("淘汰: %d\n", q.data[q.head].id);
			q.head=(q.head+1)%MAX_PEOPLE;
			q.count--;
			report_num=1;
        }
        else{
            People p=q.data[q.head];
            q.head=(q.head+1)%MAX_PEOPLE;
            q.tail=(q.tail+1)%MAX_PEOPLE;
            q.data[q.tail]=p;
			report_num++;
        }
    }
    
    printf("最后剩下的人是: %d\n", q.data[q.head].id);

    return 0;
}