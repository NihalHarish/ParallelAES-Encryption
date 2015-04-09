#include <stdio.h>
#include <omp.h>

int state[4][4] = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
int state2[4][4] = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

void reinitialize(){
   int i=0, j=0;
   for(i=0;i<4;i++)
      for(j=0;j<4;j++)
         state[i][j] = state2[i][j];
}

void ShiftRows()
{
   unsigned char temp;
   // Rotate first row 1 columns to left  
      #pragma omp task private(temp)
     {
      temp=state[1][0];
      state[1][0]=state[1][1];
      state[1][1]=state[1][2];
      state[1][2]=state[1][3];
      state[1][3]=temp;
     }
   // Rotate second row 2 columns to left 

      #pragma omp task private(temp)
      {
      temp=state[2][0];
      state[2][0]=state[2][2];
      state[2][2]=temp;

      temp=state[2][1];
      state[2][1]=state[2][3];
      state[2][3]=temp;
      }
   // Rotate third row 3 columns to left

     #pragma omp task private(temp)
     {
      temp=state[3][0];
      state[3][0]=state[3][3];
      state[3][3]=state[3][2];
      state[3][2]=state[3][1];
      state[3][1]=temp;
     }
}

void ShiftRowsSerial()
{
   unsigned char temp;
   // Rotate first row 1 columns to left  
      temp=state[1][0];
      state[1][0]=state[1][1];
      state[1][1]=state[1][2];
      state[1][2]=state[1][3];
      state[1][3]=temp;
   // Rotate second row 2 columns to left 

      temp=state[2][0];
      state[2][0]=state[2][2];
      state[2][2]=temp;

      temp=state[2][1];
      state[2][1]=state[2][3];
      state[2][3]=temp;
   // Rotate third row 3 columns to left

      temp=state[3][0];
      state[3][0]=state[3][3];
      state[3][3]=state[3][2];
      state[3][2]=state[3][1];
      state[3][1]=temp;
}


void printRows(){
   int i=0, j=0;
   for(i=0;i<4;i++){
      for(j=0;j<4;j++){
        printf("%d ", state[i][j]);
      }
      printf("\n");
   }
}

int main(){
   printf("--Initial State Of Array--\n"); 
   printRows();
   printf("\n");
   printf("--Serial Shift Rows--\n");
   ShiftRowsSerial();
   printRows();
   printf("\n");
   reinitialize();
   printf("--Parallel Shift Rows--\n");
   ShiftRows();
   printRows();
   printf("\n");
}
