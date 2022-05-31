#include<iostream>
#include"sculptor.h"

using namespace std;

int main(){

      Sculptor monitor (50 , 50 , 50 );

    monitor .setColor ( 0 , 0 , 0 , 1);//Seleciona cor preta
    monitor .putBox(9,32,9,21,9,11);    //caixa do monitor

    monitor .putBox(9,32,9,21,9,10); // corta centro do monitor
    monitor .setColor ( 1 , 1 , 1 , 1); //seleciona cor branca
    monitor .putBox(10,31,10,20,10,11); // tela branca do monitor


monitor .setColor ( 0 , 0 , 0 , 1);//seleciona cor preta
monitor .putBox(20,21,7,10,9,10); // liga base ao monitor
monitor .putEllipsoid(20,7,10,4,1,4); // elipsoid
monitor .setColor ( 0 , 1 , 0 , 1);// seleciona cor verde pra teste
monitor .cutBox(16,17,7,8,7,14);//corta sobra
monitor  .cutBox(17,24,7,8,6,7);//corta sobra


monitor.setColor (0.19,0.19,0.19,1); //SELECIONA COR CINZA

//-------- ESCREVE O L ------------/

monitor  .putBox(15,16,12,18,10,11);//L
monitor  .putBox(16,19,12,13,10,11);//L

//------------ ESCREVE O G ----------------//


monitor .putVoxel(25,16,10);
monitor .putVoxel(25,17,10);//
monitor .putVoxel(24,17,10);
monitor .putVoxel(23,17,10);
monitor .putVoxel(22,17,10);
monitor .putVoxel(21,17,10);//
monitor .putVoxel(21,16,10);
monitor .putVoxel(21,15,10);
monitor .putVoxel(21,14,10);
monitor .putVoxel(21,13,10);
monitor .putVoxel(21,12,10);//
monitor .putVoxel(22,12,10);
monitor .putVoxel(23,12,10);
monitor .putVoxel(24,12,10);
monitor .putVoxel(25,12,10);
monitor .putVoxel(25,13,10);
monitor .putVoxel(25,14,10);
monitor .putVoxel(24,14,10);
monitor .putVoxel(23,14,10);




      monitor .writeOFF("Monitor.off");


return 0;






}








































