#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

typedef struct{
	int row;
	int col;
	int pre;
}Point;

Point queue[MAX_COL*MAX_ROW];

int front=0;
int rear=0;

void enqueue(int r,int c,int pre){
	queue[rear].row=r;
	queue[rear].col=c;
	queue[rear].pre=pre;
	rear++;
}

int main(void)
{
	int start_r=0,start_c=0;
	int end_r=4,end_c=4;
	maze[start_r][start_c]=2;
	enqueue(start_r,start_c,-1);
	rear++;
	while(front<rear){
		int r=queue[front].row;
		int c=queue[front].col;
		int pre=queue[front].pre;
		if(r==4&&c==4){
			for(int i=front;i!=-1;i=queue[i].pre){
				printf("(%d, %d)\n",queue[i].row,queue[i].col);
			}
			return 0;
		}
		if(r-1>=0&&maze[r-1][c]==0){
			maze[r-1][c]=2;
			enqueue(r-1,c,front);
		}
		if(c-1>=0&&maze[r][c-1]==0){
			maze[r][c-1]=2;
			enqueue(r,c-1,front);
		}
		if(r+1<MAX_ROW&&maze[r+1][c]==0){
			maze[r+1][c]=2;
			enqueue(r+1,c,front);
		}
		if(c+1<MAX_COL&&maze[r][c+1]==0){
			maze[r][c+1]=2;
			enqueue(r,c+1,front);
		}
		front++;
	}
	return 0;
}