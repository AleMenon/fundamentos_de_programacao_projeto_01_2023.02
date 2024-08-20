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
/*Inicializa as vari�veis de intersec��o*/
    YSEinterseccao=pegaYSE(i);
    XSEinterseccao=pegaXSE(i);
    YIDinterseccao=pegaYID(i);
    XIDinterseccao=pegaXID(i);
    i++;
/*============================================================================================================================*/

    while (i<n_retangulos)
    {
/*============================================================================================================================*/
/*Compara as vari�veis*/
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
/*Substitui os valores nas vari�veis de intersec��o*/
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
/*Calcula a �rea da intersec��o final*/
    largura=XIDinterseccao-XSEinterseccao;
    altura=YSEinterseccao-YIDinterseccao;
    area=largura*altura;
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Transforma o valor da �rea em positivo, caso algum dos valores da intersec��o seja negativo*/
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
/*Inicializa as vari�veis com os valores do centro de cada ret�ngulo*/
    Xcentro_1=pegaXSE(i)+((pegaXID(i)-pegaXSE(i))/2.0);
    Ycentro_1=pegaYID(i)+((pegaYSE(i)-pegaYID(i))/2.0);
    posicao1=i;
    Xcentro_2=pegaXSE(j)+((pegaXID(j)-pegaXSE(j))/2.0);
    Ycentro_2=pegaYID(j)+((pegaYSE(j)-pegaYID(j))/2.0);
    posicao2=j;
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Inicializa as vari�veis de dist�ncia entre os dois primeiros ret�ngulos*/
    distancia_menor=pow(Ycentro_1-Ycentro_2, 2)+pow(Xcentro_1-Xcentro_2, 2);
    distancia_menor=sqrt(distancia_menor);
/*============================================================================================================================*/
/*============================================================================================================================*/
/*Calcula a dist�ncia entre o centro de todos os ret�ngulos*/
    while(i<n_retangulos)
    {
        for(j=i+1; j<n_retangulos; j++)
        {
            Xcentro_2=pegaXSE(j)+((pegaXID(j)-pegaXSE(j))/2.0);
            Ycentro_2=pegaYID(j)+((pegaYSE(j)-pegaYID(j))/2.0);

            distancia_variavel=pow(Ycentro_1-Ycentro_2, 2)+pow(Xcentro_1-Xcentro_2, 2);
            distancia_variavel=sqrt(distancia_variavel);
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*Substitui o valor da dist�ncia, caso ela seja menor*/
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
/*Transforma as posi��es em hexadecimal e "soma" para retornar os valores desejados*/
    result=(posicao1<<16)+posicao2;
/*============================================================================================================================*/
    return result;
}
