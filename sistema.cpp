/*5147233*/
/*
  Módulo de implementación de `sistema'.

  Laboratorio de Programación 3.
  InCo-FIng-UDELAR
 */

#include "../include/sistema.h"

matriz_t max_datos_procesados(nat n, nat* datos, nat* rendimiento) {
	matriz_t OPT = crear_matriz(n+1, n+1);

	for(nat j=1; j<=n; j++){
		if(datos[n]<rendimiento[j])
			OPT[n][j]=datos[n];
		else 
			OPT[n][j]=rendimiento[j];
	}

	for(nat i=n-1; i>=1; i--){
		for(nat j=i; j>=1; j--){
			nat aux;
			if(datos[i] < rendimiento[j])
				aux = datos[i];
			else 
				aux = rendimiento[j];

			if( (aux + OPT[i+1][j+1]) > OPT[i+1][1] )
				OPT[i][j] = aux + OPT[i+1][j+1];
			else 
				OPT[i][j] = OPT[i+1][1];
		}
	}
	
	return OPT;
}

Lista planificacion_optima(nat n, matriz_t OPT) {
	Lista reinicios = crear_lista();

	nat j=1;
	for(nat i=1; i<=n-1;i++){
		if(OPT[i][j] == OPT[i+1][1]){
			insertar_al_final(i, reinicios);
			j=1;
		} else {
			j++;
		}
	
	}
	return reinicios;
}

