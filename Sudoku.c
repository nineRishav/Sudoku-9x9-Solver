#include <stdio.h>
void master(int,int) ;                  // Master Function //

void move(int,int) ;                // path finder //
void display() ;                    // Display function //

int checkrow(int,int) ;                 // 3 Rules of SUDOKU //
int checkcolumn(int,int) ;
int checkgrid(int,int,int) ;

int sudoku[9][9] ;              //global declaration //
int c,r,R,C,i,j,temp;               // global //

int main()
{
    printf("\n Enter the Elements of Sudoku Row Wise and INPUT 0 for BLANK Spaces\n");
    for(j=0; j<9 ; ++j)
        for(i=0 ; i<9 ;++i)
            scanf("%d",&sudoku[j][i]);               //INPUT of element //

    master(0,0);            //sudoku starts from cell 0,0 ...//
    return 9;
}

void master(int r, int c)
 {
     int temp;
     if( r > 8 )              // starts from cell location(0,0) to end // restrict the range //
        display();
     else if( sudoku[r][c]!=0 )
        move(r,c);              //move for non zero NUMBER//
     else
     {
         for(temp=0 ; temp<=9 ; ++temp)
         {
             if((checkrow(r,temp) == 1) && (checkcolumn(c,temp) == 1 ) && (checkgrid(r,c,temp) ==1 ))
                 {
                     sudoku[r][c] = temp;           //assigning value to blank location //
                     move(r,c);         // important for continuation of cycle //
                 }
         }
         sudoku[r][c] = 0;              //if not able to solve // again put zero // --- //
     }
 }
void display()
{
    printf("\n\t\n\a Sudoku is Solved\n\n");              // DISPLAY Result //
        for(i=0; i<9 ; ++i)
        {
            for(j=0 ; j<9 ;++j)
             printf("%d ",sudoku[i][j]);
            printf("\n");
        }
}

 void move(int r, int c)
{
    if(c<8)
        master(r,c+1);              //important logic // important // careful not " c!<=8 " //
    else
        master(r+1,0) ;
}

int checkrow(int r,int num)         //row function//
{
    for(c=0 ; c<9 ;c++)
    if( sudoku[r][c]== num )
        return 0;           //if found//
    return 1;               //if not found//
}

int checkcolumn(int c,int num)          //column function //
{
    for(r=0 ; r<9 ;r++)
    if( sudoku[r][c]== num )
        return 0;           //if found//
    return 1;               //if not found//
}

int checkgrid(int r, int c,int num )
{
    r = (r/3)*3 ;
    c = (c/3)*3 ;
    for(R=0 ; R<3 ;++R)
        for(C=0 ; C<3 ;C++)
        if( sudoku[r+R][c+C] == num)
        return 0;            //if found//
    return 1;               //if not found//
}
