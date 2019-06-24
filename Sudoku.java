import java.io.*;
import java.util.*;

public class Solution 
{
  static int[][] sudoku = new int[9][9] ;              //global declaration //
  static int R,C;

    static void master(int r, int c)
    {
        int temp;
        if( r > 8 )              // starts from cell location(0,0) to end // 
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
    static void display()
    {
        for(int i=0; i<9 ; ++i)
        {
            for(int j=0 ; j<9 ;++j)
              System.out.print(sudoku[i][j]);
            System.out.println();
        }
    }

    static void move(int r, int c)
    {
        if(c<8)
            master(r,c+1);              //important logic // important // careful not " c!<=8 " //
        else
            master(r+1,0) ;
    }

    static int checkrow(int r,int num)         //row function//
    {
        for(int c=0 ; c<9 ;c++)
        if( sudoku[r][c]== num )
            return 0;           //if found//
        return 1;               //if not found//
    }

    static int checkcolumn(int c,int num)          //column function //
    {
        for(int r=0 ; r<9 ;r++)
        if( sudoku[r][c]== num )
            return 0;           //if found//
        return 1;               //if not found//
    }

    static int checkgrid(int r, int c,int num )
    {
        r = (r/3)*3 ;
        c = (c/3)*3 ;
        for(R=0 ; R<3 ;++R)
            for(C=0 ; C<3 ;C++)
            if( sudoku[r+R][c+C] == num)
            return 0;            //if found//
        return 1;               //if not found//
    }

    public static void main(String[] args) 
    {
      Scanner sc = new Scanner(System.in);
        int i,j;
        for(i=0;i<9;i++)
        {
            String s = sc.next();
            for(j=0;j<9;j++)
            {
                sudoku[i][j] = Character.getNumericValue(s.charAt(j));
            }
            
        }       
        
        master(0,0);            //sudoku starts from cell 0,0 ...//       
    }
}