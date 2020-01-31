#include <iostream>
#include <vector>
using namespace std;

vector<vector<float> > p;
vector<vector<float> > q;
vector<vector<float> > mean_array(3,vector<float>(3));
vector<vector<float> > matrix1(3,vector<float>(3));
vector<vector<float> > matrix3(3,vector<float>(3));

void quest(vector<vector<float> >&,vector<vector<float> >&);
vector<vector<float> > mean(vector<vector<float> >&);
vector<vector<float> > transpose(vector<vector<float> >&);
vector<vector<float> > repmat(vector<vector<float> >&);
vector<vector<float> > subtract_matrix(vector<vector<float> >&,vector<vector<float> >&);
vector<vector<float> > addition_matrix(vector<vector<float> >& ,vector<vector<float> >&);
vector<vector<float> > matrix_mult(vector<vector<float> >&,vector<vector<float> >&);
vector<vector<float> > trace(vector<vector<float> >&);
vector<vector<float> > Det_matrix(vector<vector<float> >&);
vector<vector<float> > Adjofloat(vector<vector<float> >&);
vector<vector<float> > matrix_square(vector<vector<float> >&);
vector<vector<float> > scalar_mult(vector<vector<float> >& ,float );
vector<vector<float> > eye(float);

int main()
{
    int random=3;

    vector<vector<float> > pp(3,vector<float>(random));
    vector<vector<float> > qq(3,vector<float>(random));
    cout<<"Input values"<<endl;
    cout<<"matrix containing elements in such format"<<endl;
    cout<<"a b c"<<endl;
    cout<<"d e f"<<endl;
    cout<<"g h i"<<endl;
    cout<<"will take input in such format : a d g b e h c f i"<<endl;
    cout<<"in total there are 2 matrices , will take 18 inputs in total"<<endl;
    for(int i =0;i<3;i++)
    {
        for (int j =0;j<3;j++)
        {
            cin>>pp[j][i];
        }
    }
    for(int i =0;i<3;i++)
    {
        for (int j =0;j<3;j++)
        {
            cin>>qq[j][i];
        }
    }
    for(int i =0;i<3;i++)
    {
        for (int j =0;j<3;j++)
        {
            cout<<pp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"q"<<endl;
    for(int i =0;i<3;i++)
    {
        for (int j =0;j<3;j++)
        {
            cout<<qq[i][j]<<" ";
        }
        cout<<"\n";
    }
    quest(pp,qq);

    return 0;
}
vector<vector<float> > mean(vector<vector<float> >& array1)
{
        for(int i = 0 ; i< 3 ; i++)
        {
            float sum=0;
            for (unsigned int j=0;j<array1[i].size();j++)
            {
                sum+=array1[i][j];
            }
            mean_array[i][0]=sum/3.0;
        }
return  mean_array;
}
vector<vector<float> > transpose(vector<vector<float> >& matrix2)
{
    for (int i = 0 ; i <3 ;i++)
    {
        for (int j = 0 ; j <3 ;j++)
        {
           matrix3[j][i]=matrix2[i][j];
        }
    }
    return matrix3;
}
vector<vector<float> > repmat(vector<vector<float> >& matrix)
{
   for (int i=0;i<3;i++)
   {
       for(unsigned int j=0;j<3;j++)
       {
           matrix1[i][j]=matrix[i][0];
       }
   }
   return matrix1;
}
vector<vector<float> > subtract_matrix(vector<vector<float> >& matrixt1,vector<vector<float> >& matrixt2)
{
   for (int i=0;i<3;i++)
   {
       for(unsigned int j=0;j<3;j++)
       {
           matrix1[i][j]=matrixt1[i][j]-matrixt2[i][j];
       }
   }
   return matrix1;
}
vector<vector<float> > addition_matrix(vector<vector<float> >& matrixt1,vector<vector<float> >& matrixt2)
{
   for (int i=0;i<3;i++)
   {
       for(unsigned int j=0;j<3;j++)
       {
           matrix1[i][j]=matrixt1[i][j]+matrixt2[i][j];
       }
   }
   return matrix1;
}
vector<vector<float> > matrix_mult(vector<vector<float> >& matrixt1,vector<vector<float> >& matrixt2)
{
   matrix1[0][0]=matrixt1[0][0]*matrixt2[0][0] + matrixt1[0][1]*matrixt2[1][0] + matrixt1[0][2]*matrixt2[2][0];
   matrix1[0][1]=matrixt1[0][0]*matrixt2[0][1] + matrixt1[0][1]*matrixt2[1][1] + matrixt1[0][2]*matrixt2[2][1];
   matrix1[0][2]=matrixt1[0][0]*matrixt2[0][2] + matrixt1[0][1]*matrixt2[1][2] + matrixt1[0][2]*matrixt2[2][2];
   matrix1[1][0]=matrixt1[1][0]*matrixt2[0][0] + matrixt1[1][1]*matrixt2[1][0] + matrixt1[1][2]*matrixt2[2][0];
   matrix1[1][1]=matrixt1[1][0]*matrixt2[0][1] + matrixt1[1][1]*matrixt2[1][1] + matrixt1[1][2]*matrixt2[2][1];
   matrix1[1][2]=matrixt1[1][0]*matrixt2[0][2] + matrixt1[1][1]*matrixt2[1][2] + matrixt1[1][2]*matrixt2[2][2];
   matrix1[2][0]=matrixt1[2][0]*matrixt2[0][0] + matrixt1[2][1]*matrixt2[1][0] + matrixt1[2][2]*matrixt2[2][0];
   matrix1[2][1]=matrixt1[2][0]*matrixt2[0][1] + matrixt1[2][1]*matrixt2[1][1] + matrixt1[2][2]*matrixt2[2][1];
   matrix1[2][2]=matrixt1[2][0]*matrixt2[0][2] + matrixt1[2][1]*matrixt2[1][2] + matrixt1[2][2]*matrixt2[2][2];
   return matrix1;
}
vector<vector<float> > scalar_mult(vector<vector<float> >& matrixt1,float value)
{
   matrix1[0][0]=matrixt1[0][0]*value;
   matrix1[0][1]=matrixt1[0][1]*value;
   matrix1[0][2]=matrixt1[0][2]*value;
   matrix1[1][0]=matrixt1[1][0]*value;
   matrix1[1][1]=matrixt1[1][1]*value;
   matrix1[1][2]=matrixt1[1][2]*value;
   matrix1[2][0]=matrixt1[2][0]*value;
   matrix1[2][1]=matrixt1[2][1]*value;
   matrix1[2][2]=matrixt1[2][2]*value;
   return matrix1;
}
vector<vector<float> > matrix_square(vector<vector<float> >& matrixt1)
{
   matrix1[0][0]=matrixt1[0][0]*matrixt1[0][0] + matrixt1[0][1]*matrixt1[1][0] + matrixt1[0][2]*matrixt1[2][0];
   matrix1[0][1]=matrixt1[0][0]*matrixt1[0][1] + matrixt1[0][1]*matrixt1[1][1] + matrixt1[0][2]*matrixt1[2][1];
   matrix1[0][2]=matrixt1[0][0]*matrixt1[0][2] + matrixt1[0][1]*matrixt1[1][2] + matrixt1[0][2]*matrixt1[2][2];
   matrix1[1][0]=matrixt1[1][0]*matrixt1[0][0] + matrixt1[1][1]*matrixt1[1][0] + matrixt1[1][2]*matrixt1[2][0];
   matrix1[1][1]=matrixt1[1][0]*matrixt1[0][1] + matrixt1[1][1]*matrixt1[1][1] + matrixt1[1][2]*matrixt1[2][1];
   matrix1[1][2]=matrixt1[1][0]*matrixt1[0][2] + matrixt1[1][1]*matrixt1[1][2] + matrixt1[1][2]*matrixt1[2][2];
   matrix1[2][0]=matrixt1[2][0]*matrixt1[0][0] + matrixt1[2][1]*matrixt1[1][0] + matrixt1[2][2]*matrixt1[2][0];
   matrix1[2][1]=matrixt1[2][0]*matrixt1[0][1] + matrixt1[2][1]*matrixt1[1][1] + matrixt1[2][2]*matrixt1[2][1];
   matrix1[2][2]=matrixt1[2][0]*matrixt1[0][2] + matrixt1[2][1]*matrixt1[1][2] + matrixt1[2][2]*matrixt1[2][2];
   return matrix1;
}
vector<vector<float> > trace(vector<vector<float> >& matrixt1)
{
    vector<vector<float> > sum(3,vector<float>(3));
    sum[0][0]=matrixt1[0][0]+matrixt1[1][1]+matrixt1[2][2];
    return sum;
}
vector<vector<float> > Det_matrix(vector<vector<float> >& m)
{
    vector<vector<float> > sums(3,vector<float>(3));
    sums[0][0]=m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1])-m[0][1]*(m[1][0]*m[2][2]-m[2][0]*m[1][2])+m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
    return sums;
}
vector<vector<float> > Adjoint(vector<vector<float> >& matrixt1)
{
   matrix1[0][0]=matrixt1[1][1]*matrixt1[2][2] - matrixt1[2][1]*matrixt1[1][2];
   matrix1[1][0]=-(matrixt1[1][0]*matrixt1[2][2] - matrixt1[2][0]*matrixt1[1][2]);
   matrix1[2][0]=matrixt1[1][0]*matrixt1[2][1] - matrixt1[1][1]*matrixt1[2][0];
   matrix1[0][1]=-(matrixt1[0][1]*matrixt1[2][2] - matrixt1[2][1]*matrixt1[0][2]);
   matrix1[1][1]=matrixt1[0][0]*matrixt1[2][2] - matrixt1[0][2]*matrixt1[2][0];
   matrix1[2][1]=-(matrixt1[0][0]*matrixt1[2][1] - matrixt1[0][1]*matrixt1[2][0]);
   matrix1[0][2]=matrixt1[0][1]*matrixt1[1][2] - matrixt1[0][2]*matrixt1[1][1];
   matrix1[1][2]=-(matrixt1[0][0]*matrixt1[1][2] - matrixt1[1][0]*matrixt1[0][2]);
   matrix1[2][2]=matrixt1[0][0]*matrixt1[1][1] - matrixt1[0][1]*matrixt1[1][0];

   return matrix1;
}
vector<vector<float> > eye(float value)
{
    for(int i=0;i<value;i++)
    {
        for(int j=0;j<value;j++)
        {
            if(i==j)
            {
                matrix1[i][j]=1;
            }
            else
                {
                    matrix1[i][j]=0;
                }
        }
    }
    return matrix1;
}
void quest(vector<vector<float> >& p,vector<vector<float> >& q)
{

    float col1 =sizeof(p[0])/sizeof(float);
    float row1 =3;
    float row2 =3;
    float col2 =sizeof(q[0])/sizeof(float);
    cout<<"col1:"<<col1<<" "<<"row1:"<<row1<<" "<<"col2:"<<col2<<" "<<"row2:"<<row2<<"\n";

     if (col1!=col2)
     {
         std::cout<<"Point sets must be of the same size";
     }

     else if ((row1!=3) || (row2!=3))
     {
         std::cout<<"Supplied points should be of dimension three";
     }

     else if (col1<3)
     {
         std::cout<<"At least three point pairs needed";
     }
     else
        {

     vector<vector<float> > pC;
     vector<vector<float> > qC;
     vector<vector<float> > ptrans;
     vector<vector<float> > qtrans;
     vector<vector<float> > ztrans;
     vector<vector<float> > prep;
     vector<vector<float> > qrep;
     vector<vector<float> > prep_new;
     vector<vector<float> > qrep_new;
     vector<vector<float> > qrep_new_trans;
     vector<vector<float> > qrep_new_trans_mult;
     vector<vector<float> > trqrep;
     vector<vector<float> > prep_new_trans;
     vector<vector<float> > prep_new_trans_mult;
     vector<vector<float> > trprep;
     vector<vector<float> > qprep_add;
     vector<vector<float> > lam;
     vector<vector<float> > lam_square;
     vector<vector<float> > lam_ab_sub;
     vector<vector<float> > lam_ab_sub_lam;
     vector<vector<float> > lam_c;
     vector<vector<float> > lam_c_lam;
     vector<vector<float> > lam_cnst;
     vector<vector<float> > cnst_lam;
     vector<vector<float> > cnst_lam_sub;
     vector<vector<float> > cnstt_lam_sub;
     vector<vector<float> > cnstt_lam;
     vector<vector<float> > cnstt_c;
     vector<vector<float> > B;
     vector<vector<float> > B_new;
     vector<vector<float> > S;
     vector<vector<float> > Z(3,vector<float>(3));
     vector<vector<float> > trb;
     vector<vector<float> > trs;
     vector<vector<float> > DetS;
     vector<vector<float> > AdjS;
     vector<vector<float> > a;
     vector<vector<float> > b;
     vector<vector<float> > c;
     vector<vector<float> > d;
     vector<vector<float> > trb_square;
     vector<vector<float> > z_mult;
     vector<vector<float> > ab_mult;
     vector<vector<float> > ctrb_mult;
     vector<vector<float> > z_mult_s;
     vector<vector<float> > z_mult_s_z;
     vector<vector<float> > z_mult_s_s;
     vector<vector<float> > cnst;
     vector<vector<float> > ab_ctrb_add;
     vector<vector<float> >lamprev(3,vector<float>(3,0.0));
     vector<vector<float> > ab_add;
     vector<vector<float> > ans_div;
     vector<vector<float> > alpha;
     vector<vector<float> > mult_alpha;
     vector<vector<float> > alpha_sub;
     vector<vector<float> > beta;
     vector<vector<float> > gamma;
     vector<vector<float> > add_lam_trb;
     vector<vector<float> > alpha_eye;
     vector<vector<float> > bets_s;
     vector<vector<float> > s_square;
     vector<vector<float> > add_ab;
     vector<vector<float> > add_bs;
     vector<vector<float> > x;
     vector<vector<float> > Eye;
     vector<vector<float> > beta_s;
     vector<vector<float> > gamma_square;
     vector<vector<float> > xtrans;
     vector<vector<float> > x_mult;
     vector<vector<float> > R_pc;
     vector<vector<float> > t;
     vector<vector<float> > nrmsq;
     vector<vector<float> > quat(4,vector<float>(4));
     float qw,qx,qy,qz,s,xs,ys,zs,wx,wy,wz,xx,xy,xz,yy,yz,zz;
     vector<vector<float> > R(3,vector<float>(3));

     //compute centroids and center points on them//

     pC=mean(p);
     qC=mean(q);

     prep=repmat(pC);
     qrep=repmat(qC);

     prep_new=subtract_matrix(p,prep);
     qrep_new=subtract_matrix(q,qrep);

     B=matrix_mult(qrep_new,prep_new=transpose(prep_new));

     S=addition_matrix(B,B_new=transpose(B));

     Z[0][0]=B[1][2]-B[2][1];
     Z[1][0]=B[2][0]-B[0][2];
     Z[2][0]=B[0][1]-B[1][0];

     trb=trace(B);

     DetS=Det_matrix(S);
     cout<<"DetS:"<<DetS[0][0]<<"\n";

     AdjS=Adjoint(S);

     trb_square=matrix_square(trb);

     trs=trace(AdjS);

     a=subtract_matrix(trb_square,trs);
     cout<<"a:"<<a[0][0]<<"\n";

    ztrans=transpose(Z);
    z_mult=matrix_mult(ztrans,Z);
    b=subtract_matrix(trb_square,z_mult);
    cout<<"b:"<<b[0][0]<<"\n";

    z_mult_s=matrix_mult(ztrans,S);
    z_mult_s_z=matrix_mult(z_mult_s,Z);
    c=addition_matrix(DetS,z_mult_s_z);
    cout<<"c:"<<c[0][0]<<"\n";

    z_mult_s_s=matrix_mult(z_mult_s,S);
    d=matrix_mult(z_mult_s_s,Z);
    cout<<"d:"<<d[0][0]<<"\n";

    ab_mult=matrix_mult(a,b);
    ctrb_mult=matrix_mult(c,trb);
    ab_ctrb_add=addition_matrix(ab_mult,ctrb_mult);
    cnst=subtract_matrix(ab_ctrb_add,d);
    cout<<"cnst:"<<cnst[0][0]<<"\n";

    qrep_new_trans=transpose(qrep_new);
    qrep_new_trans_mult=matrix_mult(qrep_new,qrep_new_trans);
    trqrep=trace(qrep_new_trans_mult);

    prep_new_trans=transpose(prep_new);
    prep_new_trans_mult=matrix_mult(prep_new,prep_new_trans);
    trprep=trace(prep_new_trans_mult);

    qprep_add=addition_matrix(trqrep,trprep);

    lam=scalar_mult(qprep_add,0.5);
    cout<<"lam"<<lam[0][0]<<"\n";
    cout<<"Newton-Rhapson"<<"\n";

    while(lamprev[0][0]!=lam[0][0])
    {
        lamprev[0][0]=lam[0][0];
        /*
        lam_square=matrix_square(lam);
        ab_add=addition_matrix(a,b);
        lam_ab_sub=subtract_matrix(lam_square,ab_add);
        lam_ab_sub_lam=matrix_mult(lam_ab_sub,lam);
        lam_c=subtract_matrix(lam_ab_sub_lam,c);
        lam_c_lam=matrix_mult(lam_c,lam);
        lam_cnst=addition_matrix(lam_c_lam,cnst);
        cnst_lam=scalar_mult(lam_square,2.0);
        cnst_lam_sub=subtract_matrix(cnst_lam,ab_add);
        cnstt_lam_sub=scalar_mult(cnst_lam_sub,2.0);
        cnstt_lam=matrix_mult(cnstt_lam_sub,lam);
        cnstt_c=subtract_matrix(cnstt_lam,c);
        ans_div[0][0]=lam_cnst[0][0]/cnstt_c[0][0];
        */
        lam[0][0]=lam[0][0] - (((lam[0][0]*lam[0][0] - (a[0][0]+b[0][0]))*lam[0][0] - c[0][0])*lam[0][0] + cnst[0][0])/(2*(2*lam[0][0]*lam[0][0] - (a[0][0]+b[0][0]))*lam[0][0] - c[0][0]);
        cout<<lam[0][0]<<"\n";
    }
    cout<<"compute optimum quaternion"<<"\n";

    //Compute optimal quaternion
    lam_square=matrix_square(lam);
    alpha_sub=subtract_matrix(lam_square,trb_square);
    alpha=addition_matrix(alpha_sub,trs);
    cout<<"alpha:"<<alpha[0][0]<<"\n";

    beta=subtract_matrix(lam,trb);
    cout<<"beta:"<<beta[0][0]<<"\n";

    add_lam_trb=addition_matrix(lam,trb);
    mult_alpha=matrix_mult(alpha,add_lam_trb);
    gamma=subtract_matrix(mult_alpha,DetS);
    cout<<"gamma:"<<gamma[0][0]<<"\n";

    Eye=eye(3.0);
    alpha_eye=matrix_mult(alpha,Eye);
    beta_s=matrix_mult(beta,S);
    s_square=matrix_square(S);
    add_ab=addition_matrix(alpha_eye,beta_s);
    add_bs=addition_matrix(add_ab,s_square);
    x=matrix_mult(add_bs,Z);

    gamma_square=matrix_square(gamma);
    xtrans=transpose(x);
    x_mult=matrix_mult(xtrans,x);
    nrmsq=addition_matrix(gamma_square,x_mult);

    cout<<nrmsq[0][0]<<"\n";

    if (nrmsq[0][0]>1.0e-10)
    {
        quat[0][0]=-gamma[0][0];
        quat[1][0]=x[0][0];
        quat[2][0]=x[1][0];
        quat[3][0]=x[2][0];
        cout<<"quat"<<"\n";
        for(int i =0;i<4;i++)
        {
        for (unsigned int j =0;j<4;j++)
        {
            cout<<quat[i][j]<<" ";
        }
        cout<<"\n";
        }
    qw=quat[0][0];qx=quat[1][0];qy=quat[2][0];qz=quat[3][0];
    s=2.0/nrmsq[0][0];
    xs=qx*s; ys=qy*s; zs=qz*s;
    wx=qw*xs;wy=qw*ys;wz=qw*zs;
    xx=qx*xs;xy=qx*ys;xz=qx*zs;
    yy=qy*ys;yz=qy*zs;zz=qz*zs;

    R[0][0]=1.0-yy-zz;
    R[0][1]=xy-wz;
    R[0][2]=xz+wy;
    R[1][0]=xy+wz;
    R[1][1]=1.0-xx-zz;
    R[1][2]=yz-wx;
    R[2][0]=xz-wy;
    R[2][1]=yz+wx;
    R[2][2]=1.0-xx-yy;
    cout<<"Rotation Matrix"<<"\n";
    for(int i =0;i<3;i++)
    {
        for (unsigned int j =0;j<3;j++)
        {
            cout<<R[i][j]<<" ";
        }
        cout<<"\n";
    }
    }
    else
        {
            cout<<"Singular rotation!"<<nrmsq[0][0]<<"\n";
        }
    R_pc=matrix_mult(R,pC);
    t=subtract_matrix(qC,R_pc);
    cout<<"t(3x1 rotation matrix)"<<"\n";
    for(int i =0;i<3;i++)
    {
        for (unsigned int j =0;j<3;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    }
}





