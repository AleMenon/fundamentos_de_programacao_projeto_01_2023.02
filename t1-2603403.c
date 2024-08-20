/*============================================================================================================================*/
/*Alexandre Alberto Menon                                                                                                     */
/*RA: 2603403                                                                                                                 */
/*============================================================================================================================*/
#include "trabalho1.h"
#include<math.h>

int calculaInterseccao (int n_retangulos)
{
    int i=0, YSEinterseccao, XSEinterseccao, YIDinterseccao, XIDinterseccao, flaginterseccao, area, largura, altura;
/*============================================================================================================================*/
/*Inicializa as variáveis de intersecção*/
    YSEinterseccao=pegaYSE(i);
    XSEinterseccao=pegaXSE(i);
    YIDinterseccao=pegaYID(i);
    XIDinterseccao=pegaXID(i);
    i++;
/*============================================================================================================================*/

    while (i<n_retangulos)
    {
/*============================================================================================================================*/
/*Compara as variáveis*/
        if(YSEinterseccao<=pegaYID(i) || YIDinterseccao>=pegaYSE(i))
        {
            return 0;
        }
        else if(XSEinterseccao>=pegaXID(i) || XIDinterseccao<=pegaXSE(i))
        {
            return 0;
        }
        else
        {
            flaginterseccao=1;
        }
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Substitui os valores nas variáveis de intersecção*/
        if(flaginterseccao)
        {
            if(YSEinterseccao>pegaYSE(i))
            {
                YSEinterseccao=pegaYSE(i);
            }
            if(YIDinterseccao<pegaYID(i))
            {
                YIDinterseccao=pegaYID(i);
            }
            if(XSEinterseccao<pegaXSE(i))
            {
                XSEinterseccao=pegaXSE(i);
            }
            if(XIDinterseccao>pegaXID(i))
            {
                XIDinterseccao=pegaXID(i);
            }
        }
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Reinicia a flag e adiciona valor ao contador*/
        flaginterseccao=0;
        i++;
/*============================================================================================================================*/
    }
/*============================================================================================================================*/
/*Calcula a área da intersecção final*/
    largura=XIDinterseccao-XSEinterseccao;
    altura=YSEinterseccao-YIDinterseccao;
    area=largura*altura;
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Transforma o valor da área em positivo, caso algum dos valores da intersecção seja negativo*/
    area=pow(area, 2);
    area=sqrt(area);
/*============================================================================================================================*/
    return area;
}

unsigned int encontraParMaisProximo (int n_retangulos)
{
    int i=0, j=1, posicao1, posicao2;
    unsigned int result;
    float Xcentro_1, Ycentro_1, Xcentro_2, Ycentro_2, distancia_menor, distancia_variavel;
/*============================================================================================================================*/
/*Inicializa as variáveis com os valores do centro de cada retângulo*/
    Xcentro_1=pegaXSE(i)+((pegaXID(i)-pegaXSE(i))/2.0);
    Ycentro_1=pegaYID(i)+((pegaYSE(i)-pegaYID(i))/2.0);
    posicao1=i;
    Xcentro_2=pegaXSE(j)+((pegaXID(j)-pegaXSE(j))/2.0);
    Ycentro_2=pegaYID(j)+((pegaYSE(j)-pegaYID(j))/2.0);
    posicao2=j;
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Inicializa as variáveis de distância entre os dois primeiros retângulos*/
    distancia_menor=pow(Ycentro_1-Ycentro_2, 2)+pow(Xcentro_1-Xcentro_2, 2);
    distancia_menor=sqrt(distancia_menor);
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Calcula a distância entre o centro de todos os retângulos*/
    while(i<n_retangulos)
    {
        for(j=i+1; j<n_retangulos; j++)
        {
            Xcentro_2=pegaXSE(j)+((pegaXID(j)-pegaXSE(j))/2.0);
            Ycentro_2=pegaYID(j)+((pegaYSE(j)-pegaYID(j))/2.0);

            distancia_variavel=pow(Ycentro_1-Ycentro_2, 2)+pow(Xcentro_1-Xcentro_2, 2);
            distancia_variavel=sqrt(distancia_variavel);
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*Substitui o valor da distância, caso ela seja menor*/
            if(distancia_variavel<distancia_menor)
            {
                distancia_menor=distancia_variavel;
                posicao1=i;
                posicao2=j;
            }
/*-----------------------------------------------------------------------------------------------------------------------------*/
        }
        i++;
        Xcentro_1=pegaXSE(i)+((pegaXID(i)-pegaXSE(i))/2.0);
        Ycentro_1=pegaYID(i)+((pegaYSE(i)-pegaYID(i))/2.0);
    }
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Transforma as posições em hexadecimal e "soma" para retornar os valores desejados*/
    result=(posicao1<<16)+posicao2;
/*============================================================================================================================*/
    return result;
}
