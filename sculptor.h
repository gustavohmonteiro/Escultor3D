#ifndef SCULPTOR_HPP
#define SCULPTOR_HPP
#include "voxel.h"

class Sculptor {
protected:
  Voxel ***v;
   // 3D matrix
  int nx,ny,nz; // Dimensões
  float r,g,b,a; // Cor do desenho atual
public:
  Sculptor(int _nx, int _ny, int _nz); //Construtor
  ~Sculptor(); //Destrutor
  void setColor(float r, float g, float b, float alpha);//Retorna valor de cores
  void putVoxel(int x, int y, int z);//Gera um Quadrado na Posição escolhida
  void cutVoxel(int x, int y, int z);//Apaga o Quadrado na posição escolhida
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);//
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(const char* filename);
};

#endif
