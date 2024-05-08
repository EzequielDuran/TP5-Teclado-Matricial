#include "libreriaTecladoMarcial.h"
#include "MKL2574"

int fila[4] = {1, 2, 3, 4};
int columnas[4] = {5, 6, 7, 8};
char caracteres[4][4] = {
    {1, 2, 3, A},
    {4, 5, 6, B},
    {7, 8, 9, C},
    { *, 0, #, D}};
char tecladoMarcial()
{
    for (int i = 0; i < 4; i++)
    {
        PTA->PSOR |= (0u << fila[i]);
        for (int i = 0; i < 4; i++)
        {
            if(PTA -> PDIR&(1<<columnas[i]) == 0){
                return caracteres[fila[i]][columnas[i]];
            }
        }
        PTA->PSOR |= (1u << fila[i]);
    }
}
void inicializar() {
    SIM -> SCGC5|= SIM_SCGC5_PORTA_MASK;
    for (int i = 0; i < 4; i++){
        PORTA ->PCR[fila[i]]=PORT_PCR_MUX(1);
        PORTA ->PCR[columnas[i]]=PORT_PCR_MUX(0);
    }
}