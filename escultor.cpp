#include<cstdlib>
#include<iostream>
#include"sculptor.h"
#include<vector>
#include<fstream>
#include<cmath>

using namespace std;

// Definição do construtor da classe Sculptor
Sculptor::Sculptor(int _nx, int _ny, int _nz){

    this->nx = _nx;
    this->ny = _ny;
    this->nz = _nz;
    this->r = 0.0;
    this->g = 0.0;
    this->b = 0.0;
    this->a = 0.0;

    v = new Voxel **[_nx];

    for(int i = 0; i < _nx; i++ ){

        v[i] = new Voxel *[_ny];
        for(int j = 0; j < _ny; j++){

            v[i][j] = new Voxel [_nz];
            for(int k = 0; k < _nz; k++){

                    this->v[i][j][k].r = 0.0;
                    this->v[i][j][k].g = 0.0;
                    this->v[i][j][k].b = 0.0;
                    this->v[i][j][k].a = 0.0;
                    this->v[i][j][k].isOn = false;

            }
        }
    }

}

//definição do destrutor da minha classe Sculptor
Sculptor::~Sculptor(){

    for(int i = 0; i < nx; i++ ){

        for(int j = 0; j < ny; j++){

           delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;

}

//agora vxlamos definir a funçao setColor da classe Sculptor
void Sculptor::setColor(float r, float g, float b, float alpha){

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;

}

//definição da função putvxloxel
void Sculptor::putVoxel(int x, int y, int z){


    this->v[x][y][z].isOn = true;
    this->v[x][y][z].r = this->r;
    this->v[x][y][z].g = this->g;
    this->v[x][y][z].b = this->b;
    this->v[x][y][z].a = this->a;

}

//definição de cutvxloxel
void Sculptor::cutVoxel(int x, int y, int z){
    this->v[x][y][z].isOn = false;
}

//definição da função putBox
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    //verifica se a minha Box Está dentro da dimensão
    x0 = (x0 < 0) ? 0 : x0;
    x1 = (x1 > this->nx) ? this->nx : x1;
    y0 = (y0 < 0) ? 0 : y0;
    y1 = (y1 > this->ny) ? this->ny : y1;
    z0 = (z0 < 0) ? 0 : z0;
    z1 = (z1 > this->nz) ? this->nz : z1;

    //atribui o voxel dentro dos intervalos [x0,x1],[y0,y1] e [z0,z1]
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){

                this->putVoxel(i,j,k);
            }
        }
    }
}

//definiçao cutBox
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    //Desativa os voxels da Box da minha matrix
    for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){

                this->cutVoxel(i,j,k);
            }
        }
    }
}

//Definição minha função putSphere
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    //Cria minha esfera
    putEllipsoid(xcenter,ycenter,zcenter,radius,radius,radius);
}

//Definição minha função putSphere
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    cutEllipsoid(xcenter,ycenter,zcenter,radius,radius,radius);
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    //verifica se os valores do elipsóide estão dentro da dimensão
    int x0 = (xcenter - rx < 0) ? 0 : xcenter - rx;
    int x1 = (xcenter + rx > this->nx) ? this->nx : xcenter + rx;
    int y0 = (ycenter - ry < 0) ? 0 : ycenter - ry;
    int y1 = (ycenter + ry > this->ny) ? this->ny : ycenter + ry;
    int z0 = (zcenter - rz < 0) ? 0 : zcenter - rz;
    int z1 = (zcenter + rz > this->nz) ? this->nz : zcenter + rz;

     for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){

                if(pow((i - xcenter)/rx, 2) + pow((j - ycenter)/ry, 2) + pow((k - zcenter)/rz, 2) == 1){

                    this->putVoxel(i,j,k);
                }


            }
        }
    }


}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    //verifica se os valores do elipsóide estão dentro da dimensão
    int x0 = (xcenter - rx < 0) ? 0 : xcenter - rx;
    int x1 = (xcenter + rx > this->nx) ? this->nx : xcenter + rx;
    int y0 = (ycenter - ry < 0) ? 0 : ycenter - ry;
    int y1 = (ycenter + ry > this->ny) ? this->ny : ycenter + ry;
    int z0 = (zcenter - rz < 0) ? 0 : zcenter - rz;
    int z1 = (zcenter + rz > this->nz) ? this->nz : zcenter + rz;

     for(int i = x0; i < x1; i++){
        for(int j = y0; j < y1; j++){
            for(int k = z0; k< z1; k++){

                if(pow(((i - xcenter)/rx), 2) + pow(((j - ycenter)/ry), 2) + pow(((k - zcenter)/rz), 2) == 1 ){

                    this->cutVoxel(i,j,k);
                }


            }
        }
    }

}

void Sculptor::writeOFF(const char *filename){

    ofstream myFile(filename);
    //Inicia o stream
    if (!myFile.is_open())
    {
        cout << "Error while open file: "<< filename << endl;
        exit(1);
    }
    //Conta quantos voxels tem
    int vOn = 0, i, j, k;
    for (i = 0; i < nx; i++)
    {
        for (j = 0; j < ny; j++)
        {
            for (k = 0; k < nz; k++)
            {
                if (this->v[i][j][k].isOn)
                {
                    vOn++;
                }
            }
        }
    }

    ////////////////////////////////
    //(Re)Escreve no Formato OFF ///
    ////////////////////////////////
    myFile << "OFF" << endl;
    myFile << 8 * vOn << " " << 6 * vOn << " 0" << endl;

    for (i = 0; i < nx; i++)
    {
        for (j = 0; j < ny; j++)
        {
            for (k = 0; k < nz; k++)
            {
                if (this->v[i][j][k].isOn)
                {
                    // mais stream
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    myFile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    myFile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    myFile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }
    int contVOn = 0;
    for (i = 0; i < nx; i++)
    {
        for (j = 0; j < ny; j++)
        {
            for (k = 0; k < nz; k++)
            {
                if (this->v[i][j][k].isOn)
                {
                    myFile << "4 " << contVOn * 8 + 0 << " " << contVOn * 8 + 3 << " " << contVOn * 8 + 2 << " " << contVOn * 8 + 1 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 4 << " " << contVOn * 8 + 5 << " " << contVOn * 8 + 6 << " " << contVOn * 8 + 7 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 0 << " " << contVOn * 8 + 1 << " " << contVOn * 8 + 5 << " " << contVOn * 8 + 4 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 0 << " " << contVOn * 8 + 4 << " " << contVOn * 8 + 7 << " " << contVOn * 8 + 3 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 3 << " " << contVOn * 8 + 7 << " " << contVOn * 8 + 6 << " " << contVOn * 8 + 2 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    myFile << "4 " << contVOn * 8 + 1 << " " << contVOn * 8 + 2 << " " << contVOn * 8 + 6 << " " << contVOn * 8 + 5 << " " << this->v[i][j][k].r << ".0 " << this->v[i][j][k].g << ".0 " << this->v[i][j][k].b << ".0 " << this->v[i][j][k].a << ".0" << endl;
                    contVOn++;
                }
            }
        }
    }
    // Fecha o arquivo
    myFile.close();
}
