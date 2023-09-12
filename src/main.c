#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "kmeans.h"


int main(int argc, char **argv)
{
	FILE *fptr, *ptr1, *ptr2, *ptr3, *ptr10;

	fptr = fopen(argv[2], "r");
	if (fptr == NULL) {
		printf("file can't be opened \n");
   		exit(1);
	}

	ptr1 = fopen(argv[5],"r");
	ptr2 = fopen(argv[6],"r");
	ptr3 = fopen("new_cordinates.txt","w");


	


	int line_count = 0;
	int i = 0;
	int j = 0;
	char *row = NULL;
	double Percentage;
	double min_mutation;
	double max_mutation;
	int non_mut_count;

	size_t len = 0;

	int num_of_gid = 0;
	char *row2= NULL;
	while (getline(&row2, &len, ptr1) != -1)
    {
		num_of_gid++;
	}

	free(row2);
	fclose(ptr1);

	ptr1 = fopen(argv[5],"r"); // closing and opening again
	
	//________________________________________
	
	// sorting gid	
    char g[1000][10];
    
    for(int i=0;i<num_of_gid;i++)
    {
        (getline(&row2, &len, ptr1) != -1);
		char * token2 = strtok(row2, " ");
        for(int j=0;j<7;j++)
        {
             g[i][j] = token2[j];
        }
        g[i][7] = '\0';
        
    }

    char temp[100];
    for(int i=0;i<num_of_gid-1;i++)
    {
      //  printf("%d\n",i);
        for(int j = 0;j < num_of_gid - i - 1; j++)
        {
            
            if(strcmp(g[j], g[j+1]) > 0)
            {
                
                strcpy(temp, g[j]);
                strcpy(g[j], g[j+1]);
                strcpy(g[j+1], temp);
            }
            
        }
    } 
    
    ptr10 = fopen("new_gid.txt","w");

       for(int i=0;i<num_of_gid;i++)
        {
        fprintf(ptr10,"%s\n",g[i]);
        } 
   
    
	fclose(ptr1);
	fclose(ptr10);
	
	
	
	//________________________________________
	
	ptr1 = fopen("new_gid.txt","r");
	
	

	int arr[num_of_gid+1];
	//printf("%d\n",num_of_gid);

 // Dealing with score matrix
	char *row3 = NULL;
	float arr3[6][6]={0};
	int t = 1;
	while (getline(&row3, &len, ptr2) != -1) 
	{
		char * token = strtok(row3, " ");
		arr3[t][1] = atof(token);
		
		token = strtok(NULL, " ");
		arr3[t][2] = atof(token);

		token = strtok(NULL, " ");
		arr3[t][3] = atof(token);

		token = strtok(NULL, " ");
		arr3[t][4] = atof(token);
		t++;

	}
/*
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%0.1f ",arr3[i][j]);
		}	
		printf("\n");
	}
	*/
	int time=1;

	while (getline(&row, &len, fptr) != -1) {
			



			int col[len];
			i = 0;
			j = 0;

			while (row[i] != '\n') {
				if (row[i] == '\t') {
					col[j] = i;
					j++;
				}
				i++;
			}
			
			

			int Ref_col = col[2] + 1;
			int Alt_col = col[3] + 1;
			int Qual = col[4] + 1;
			int Filter_col = col[5] + 1;
			//______________________________________________________________

			if(row[0] == '#' && row[1] =='C')
				{
					for(int k=1;k<=num_of_gid;k++)
					{
						(getline(&row2, &len, ptr1) != -1);
						char * token2 = strtok(row2, " ");

					/*	printf("%c",token2[0]);
						printf("%c",token2[1]);
						printf("%c",token2[2]);
						printf("%c",token2[3]);
						printf("%c",token2[4]);
						printf("%c",token2[5]);
						printf("%c",token2[6]);
						printf("\n");  */

						int i=0;
						while (i < j)
						{

							if(token2[0]==row[col[i] + 1])
							{
								if(token2[1]==row[col[i] + 2])
								{
									if(token2[2]==row[col[i] + 3])
									{
										if(token2[3]==row[col[i] + 4])
										{
											if(token2[4]==row[col[i] + 5])
											{
												if(token2[5]==row[col[i] + 6])
												{
													if(token2[6]==row[col[i] + 7])
													{
														
													/*	printf("%c",row[col[i] + 1]);
														printf("%c",row[col[i] + 2]);
														printf("%c",row[col[i] + 3]);
														printf("%c",row[col[i] + 4]);
														printf("%c",row[col[i] + 5]);
														printf("%c",row[col[i] + 6]);
														printf("%c",row[col[i] + 7]);
														printf("\n\n"); */
														arr[k] = i;
														//printf("\n%d\n", col[i]);
														break;
													}
												}
											}
										}
									}
								}
							}
							i++;
						}
						
					}


				/*	for(int k=1;k<=num_of_gid;k++)
					{
						printf("%c",row[arr[k]]);
						printf("%c",row[arr[k]+1]);
						printf("%c",row[arr[k]+2]);
						printf("%c",row[arr[k]+3]);
						printf("%c",row[arr[k]+4]);
						printf("%c",row[arr[k]+5]);
						printf("%c",row[arr[k]+6]);
						printf("\n");
					}  
					for(int k=1;k<=num_of_gid;k++)
					{
						printf("%d\n",arr[k]);

					}  */
				}





			//_______________________________________________________________
			
			
			
			if (row[0] == argv[1][0] && (row[1] == argv[1][1] || row[1] == '\t')) // change here
			{
				
				if (row[Filter_col] == 'P' && row[Filter_col+1] == 'A' && row[Filter_col+2] == 'S' && row[Filter_col+3] == 'S') 
				{
				
					if (row[Ref_col + 1] == '\t' && row[Ref_col - 1] == '\t') 
					{
						if (row[Ref_col] == 'A' || row[Ref_col] == 'T' || row[Ref_col] == 'G' || row[Ref_col] == 'C') 
						{
						
								
							if (Qual - Alt_col > 8) {
								continue;
							}

							int A=0, T=0, G=0, C=0;
							int flag = 1;
							
							for (int i = Alt_col; i < Qual; i++)
							{
								if ((row[i - 1] == ',' || row[i - 1] == '\t') && (row[i + 1] == ',' || row[i + 1] == '\t')) {
									if (row[i] == 'A') {
										A++;
									} 
									else if (row[i] == 'T') 
									{
										T++;
									} 
									else if (row[i] == 'G') 
									{
										G++;
									} 
									else if (row[i] == 'C') 
									{
										C++;
									}

									i++;
								} else {
									flag = 0;
									break;
								}
							}

							if (A > 1 || T > 1 || G > 1 || C > 1 || flag == 0) {
								continue;
							}
							
							non_mut_count = 0;
							
							for (int i = 8; i < j+1; i++) {
								char a = row[col[i] + 1];
								char b = row[col[i] + 3];
								
								if (a == '0' && b == '0') {
									non_mut_count++;
								}
							}
							
							Percentage = (double)(j - 8 - non_mut_count) / (j - 8);
							Percentage = Percentage * 100;

							min_mutation = atof(argv[3]);
							max_mutation = atof(argv[4]);

							if ((min_mutation <= Percentage) && (max_mutation >= Percentage)) {
								line_count++;
						//	}


							//___________________________________________________
							// storing ACGT array
							char arr2[5];
							for(int i=0;i<5;i++)
							{
								arr2[i]='\0';
							}
							arr2[0] = row[Ref_col];
							for(int k=0, j=1;k<=3;k++)
							{
								if(row[Alt_col + k] == '\t')
								{
									break;
								}
								if(row[Alt_col + k] != ',')
								{
									arr2[j]=row[Alt_col + k];
									j++;
								}
								
							}

						   //	printf("%s\n",arr2);

						 for(int i=1;i<=num_of_gid;i++)
						 {
							 char m = row[col[arr[i]] + 1];  //  have some problem
							 char n = row[col[arr[i]] + 3];

							// printf("%c",m);
							// printf("%c ",n);

							int a,b;
							if(m == '0')
							{
								a = 0;
							}
							if (m == '1')
							{
								a = 1;
							}
							if(n == '0')
							{
								b = 0;
							}
							if (n == '1')
							{
								b = 1;
							}
							
						//	printf("%d",a);
						//	printf("%d\t",b);

							char c,d;
							c = arr2[a];
							d = arr2[b];

							int p,q;
							if(c == 'A')
							{
								p = 1;
							}
							else if(c == 'C')
							{
								p = 2;
							}
							else if(c == 'G')
							{
								p = 3;
							}
							else if(c == 'T')
							{
								p = 4;
							}

							if(d == 'A')
							{
								q = 1;
							}
							else if(d == 'C')
							{
								q = 2;
							}
							else if(d == 'G')
							{
								q = 3;
							}
							else if(d == 'T')
							{
								q = 4;
							}

							 fprintf(ptr3,"%0.1f",arr3[p][q]);
            				 fprintf(ptr3,"%c",'\t');

						 }
						//	printf("\n");
						  fprintf(ptr3,"%c",'\n');





							//________________________________________________________

							}

						}
					}
				} 
				
			}
		
	}

	
//	printf("j = %d\n",j);
//	printf("%d\n", line_count);

	

	fclose(fptr);
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr3);


	//___________________________________________________________________________________________________

	FILE *ptr4;
	ptr4 = fopen("new_cordinates.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

	char *row4 = NULL;
	int k=0;
	char * token;
	double mat[line_count][num_of_gid];
	double trans[num_of_gid][line_count];

	while (getline(&row4, &len, ptr4) != -1) {
        for ( int i = 0; i < num_of_gid; i++)
        {
            if(i == 0){
        		token = strtok(row4, "\t");
                mat[k][i] = atof(token);
            } else{
        		token = strtok(NULL, "\t");
                mat[k][i] = atof(token);
            }
        }
        k++;
    
    }

	for ( int i = 0; i < line_count; i++)
    {
        for ( int k = 0; k < num_of_gid; k++)
        {
            trans[k][i] = mat[i][k];
        }
        
    }

 /*    for ( int i = 0; i < num_of_gid; i++)
    {
        for ( int k = 0; k < line_count; k++)
        {
            printf("%.2f ", trans[i][k]);
        }
        printf("\n\n");
        
    } */
	
	 
	 int  n_clus = atoi(argv[7]);
	 int max_iteration = atoi(argv[8]);

	 double centroid[num_of_gid][line_count];
	 int clus_color[num_of_gid] ;

	  for(int i=0;i<n_clus;i++)
 	 {
		for(int j=0;j<line_count;j++)
		{
			centroid[i][j] = trans[i][j]; // transpose
		}
	 }
	 
	  for(int i=0;i<n_clus;i++)
	 {
		clus_color[i] = i;
	 }
	 
	

	 Kmean(num_of_gid, line_count, trans , n_clus, centroid,clus_color,max_iteration);
/*
	 for(int i=0;i<n_clus;i++)
 	 {
		for(int j=0;j<line_count;j++)
		{
			printf("%0.2f ", centroid[i][j]);
		}
		printf("\n\n");
	 }    */
	 
	 
	//___________________________________________________________________________________________________

	fclose(ptr4); 
	
	FILE *ptr5 = fopen("new_gid.txt","r");
	char *row5 = NULL;

    for (int i=0;i<num_of_gid;i++)
	{
		(getline(&row5, &len, ptr5) != -1);
		char * token2 = strtok(row5, "\n");
		
		
		printf("%s ",token2);
		
		printf("%d ",clus_color[i]);

		for(int j=0;j<line_count;j++)
		{
			printf("%0.3f",centroid[clus_color[i]][j]);
			printf(",");
		}
		printf("\n");
	}
	

	free(row5);
	
	fclose(ptr5); 
	return 0;
}
