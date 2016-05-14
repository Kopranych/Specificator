/*
 * Create_spec.h
 *
 *  Created on: 7 ��� 2016 �.
 *      Author: ��������
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
{      //C������ ����� ��� ������ � ������ device �������������� ����� ���������
	char element[20];   //������� ����� ��� �������� � ���� ������� �� 20�� �����
	int number;			//� ���������� �����
} device;

int device_spec(char *name, int number);//������� ������� ������� � ����� �� ����� ������������ ��� �������� � ��� ���������
int complect(char *name, int number); //������� ������������ ������ ������������ ���������� � �����



#endif /* CREATE_SPEC_H_ */


