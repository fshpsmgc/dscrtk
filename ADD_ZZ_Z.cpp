DM_Z ADD_ZZ_Z (DM_Z X1, DM_Z X2)
{
    DM_N X1_ncopy;
    DM_N X2_ncopy;
    DM_N nSum;
    DM_Z zSum;

    if (X1.b==0 && X2.b==0 || X1.b==1 && X2.b==1)
      {
        X1_ncopy = ABS_Z_N(X1);
        X2_ncopy = ABS_Z_N(X2);
        nSum = ADD_NN_N(X1_ncopy, X2_ncopy);

        if (X1.b==0 && X2.b==0)
            return TRANS_N_Z(nSum);
        if (X1.b==1 && X2.b==1)
            {
              zSum = TRANS_N_Z(nSum);
              MUL_Zm_Z(*zSum);
              return (zSum);
            }
      }
    else
    if (X1.b=1 && X2.b=0 || X1.b=0 && X2.b=1 )
      {
        X1_ncopy = ABS_Z_N(X1);
        X2_ncopy = ABS_Z_N(X2);
        nSum = SUB_NN_N (X1_ncopy, X2_ncopy);
        if ((COM_NN_D(X1_ncopy, X2_ncopy) == 2) && X1.b=1  ||  (COM_NN_D(X1_ncopy, X2_ncopy) == 1) && X2.b=1)
          {
            zSum = TRANS_N_Z(nSum);
            MUL_Zm_Z(*zSum);
            return zSum;
          }
        else
        if ((COM_NN_D(X1_ncopy, X2_ncopy) == 1) && X1.b=1  ||  (COM_NN_D(X1_ncopy, X2_ncopy) == 2) && X2.b=1)
          {
             nSum = SUB_NN_N (X1_ncopy, X2_ncopy);
             return TRANS_N_Z(nSum);
          }
         else
         if ((COM_NN_D(X1_ncopy, X2_ncopy) == 1)=0)
         {
            zSum.n=1;
            zSum.a[0]=0;
            return zSum;
         }

      }
}
