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
}Point;

Point stack[MAX_COL*MAX_ROW];

int top=-1;

void push(int r,int c){
	top++;
	stack[top].row=r;
	stack[top].col=c;
}

void pop(){
	if(top>=0)top--;
}

int main(void)
{
	int start_r=0,start_c=0;
	int end_r=4,end_c=4;
	push(start_r,start_c);
	maze[start_r][start_c]=2;
	while(top>=0){
		int r=stack[top].row;
		int c=stack[top].col;
		if(r==end_r&&c==end_c){
			for(int i=top;i>=0;i--){
				printf("(%d, %d)\n",stack[i].row,stack[i].col);
			}
			return 0;
		}
        if (r - 1 >= 0 && maze[r - 1][c] == 0) {
            maze[r - 1][c] = 2;
            push(r - 1, c);
        }
        // 2. 其次 向左 (c - 1)
        else if (c - 1 >= 0 && maze[r][c - 1] == 0) {
            maze[r][c - 1] = 2;
            push(r, c - 1);
        }
        // 3. 再次 向下 (r + 1)
        else if (r + 1 < MAX_ROW && maze[r + 1][c] == 0) {
            maze[r + 1][c] = 2;
            push(r + 1, c);
        }
        // 4. 最后 向右 (c + 1)
        else if (c + 1 < MAX_COL && maze[r][c + 1] == 0) {
            maze[r][c + 1] = 2;
            push(r, c + 1);
        }
        else {
            pop();
        }
	}
	printf("No path!\n");
	return 0;
}