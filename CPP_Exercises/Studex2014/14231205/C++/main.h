#ifndef MAIN_H
#define MAIN_H

//--------------vec-------------
class Vec {
private:
  double e[2];

public:
      Vec(void)
      {
         for (int i=0;i<2;i++)
	    e[i] = 0;
      }

      void scan(void);
      void print(void);
      Vec add(Vec u);
      Vec sub(Vec u);
	//      Vec inp(Vec u);
};

//----------mat-----------------
class SqMat {
private:
  double e[2][2];

public:
      SqMat(void)
      {
         for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
	       e[i][j] = 0.0;
      }

      void scan(void);
      void print(void);
      SqMat add(SqMat u);
      SqMat sub(SqMat u);
	//      SqMat inp(SqMat u);
};

#endif
