#include <stdio.h>
#include <stdlib.h>

int BuscadorMaximo();
int BuscadorMinimo();

int main()
{
    int Numero=0;
    int max;
    int min;
    int contador=0;



    while (Numero!=-1)
    {

        printf("Ingrese un numero: ");
        scanf("%d",&Numero);

        if (contador==0 && Numero>-1)
        {
            max=Numero;
            min=Numero;
        }

        max=BuscadorMaximo(Numero, max);

        min=BuscadorMinimo(Numero, min);

        contador++;
    }

    printf("\nEl numero maximo es: %d", max);
    printf("\nEl numero minimo es: %d", min);


    return 0;
}

int BuscadorMaximo (int num, int maximo)
{
    if(maximo<num)
    {
        maximo=num;
    }

    return maximo;
}

int BuscadorMinimo(int num, int minimo)
{
    if(minimo>num && num>0)
    {
        minimo=num;
    }

    return minimo;

}







