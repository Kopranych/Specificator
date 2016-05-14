/*
 * Create_spec.h
 *
 *  Created on: 7 мая 2016 г.
 *      Author: Копраныч
 */

#ifndef CREATE_SPEC_H_
#define CREATE_SPEC_H_


#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "logger.h"

typedef struct
{      //Cоздали новый тип данных с именем device представленный ввиде структуры
	char element[20];   //которая имеет имя элемента в виде массива из 20ти ячеек
	int number;			//и порядковый номер
} device;

int device_spec(char *name, int number);//функция которая создает в файле на диске спецификацию для внесения в нее элементов
int complect(char *name, int number); //функция отображающая данные спецификации хранящиеся в файле



#endif /* CREATE_SPEC_H_ */


