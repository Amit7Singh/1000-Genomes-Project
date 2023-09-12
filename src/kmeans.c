#include <math.h>
#include<stdio.h>
void Kmean(int number_of_points,int  dim,double points[number_of_points][dim],int n_clus, double centroid[number_of_points][dim],int clus_color[number_of_points], int max_iteration)
{
 // here dim means row
 //printf("number_of_points = %d\n",number_of_points);
 //printf("dim = %d\n",dim);
 //printf("n_clus = %d\n",n_clus);

 float dis_1=0; 
 
 int distance[n_clus];

/* for(int i=1;i<=number_of_points;i++)
 {
    for(int j=1;j<=dim;j++)
    {
      output_arr[i][j]=points[i][j];
    }
    
 }  */



  //__________________________________________________________
 
 

 
    


    

    
    
    int p =0, k=0;
   
    while (max_iteration--)
    {   
              
      for(int i=0;i<number_of_points;i++)
      {
        
        for(int j=0;j<n_clus;j++)
        {
          dis_1 = 0;
          for(int k=0;k<dim;k++)
          {
            dis_1 = dis_1 + fabs(points[i][k] - centroid[j][k]); // finding distance
          
          }
          
          distance[j] = dis_1;
       //  printf("%f\n",dis_1);
        }
        
        float min = distance[0];
        int index=0;
        for(int p=0; p<n_clus;p++)
        {
          if(distance[p]<min)
          {
            min = distance[p];
            index = p;
          }
        
        }

        clus_color[i] = index; 

      }

      int arr2[dim];
      float new_counter=1;

      for(int i=0;i<dim;i++)
      {
        arr2[i]=0;
      }


      for(int i=0;i<n_clus;i++)
      {
        new_counter = 1;
         for(int i=0;i<dim;i++)
        {
          arr2[i]=0;
        }

        for(int j=0;j<number_of_points;j++)
        {
          if(clus_color[j] == i)
          {
            
            for(int k=0;k<dim;k++)
            {
              arr2[k] = arr2[k] + points[j][k];
            
            }
          
            new_counter++;
          }
        
        }
        

        // has some problem
        for(int m=0;m<dim;m++)
        {
          centroid[i][m] = centroid[i][m] + arr2[m];
          centroid[i][m] = centroid[i][m]/new_counter;
        }

      }

    }

    
/*
      for (int i=0;i<n_clus;i++)
      {
        
        for (int j = 0; j < dim ; j++)
        {
          printf("%0.3f ",centroid[i][j]);
        }
        printf("\n\n");
        
      }  

      printf("\n\n");
      for (int i=0;i<number_of_points;i++)
      {
          printf("%d\n",clus_color[i]);
      }
      printf("\n\n");
    */
            return ;
   }

   
