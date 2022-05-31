#ifndef VOXEL_HPP
#define VOXEL_HPP

struct Voxel
{
    float r, g, b, a; // Cores vermelho,verde,azul e Alpha(transparencia) que quando 0 nao aparece nada e quando 100 aparece normalmente
    bool isOn; //inclui ou nao inclui
};

#endif

