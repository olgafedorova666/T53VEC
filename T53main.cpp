/* Fedorova Olga 11-4 05.04.2017 nB */
#include "Vec.H"

void main(void)
{ 
  fegl::anim & My = fegl::anim::Get();
  int n = 0, k, i, j;
  double x, y, z;
  fegl::vec Figure[100][4][4];
  FILE *F;
  F = fopen("X:\\TEACUP.TXT", "r");
  if(F == NULL)
    return;
  fscanf(F, "%i",&n); 
    for(k = 0 ; k < n; k++)
    {
      for(i = 0 ; i < 4; i++)
      {
        for(j = 0 ; j < 4; j++)
        {
          fscanf(F, "%lf %lf %lf", &x, &y, &z);
          Figure[k][i][j] = fegl::vec(x, y, z);
        }

      }
   }
  fclose(F);  
  for(int i = 0 ; i < n; i++)
    My<<new fegl::patch1(Figure[i]);        
  My.Run(); 
 } 