/*
 * logger.c
 *
 *  Created on: 13 ���. 2016 �.
 *      Author: ��������
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"

static char * file_name; //���������� ��������� �� ����������� ����������

Log* get_logger(char* name)
{
	file_name = name; //��������� ��� �����-�������
	static _Bool is_init; //��������� ����������� ������ ���������� is_init
	static Log* logger; //��������� ��������� �� ��������� ���� Log
	if (!is_init) //���� ������ ������ ������� �.�. is_init �� ������������������� ����� ����
	{ //�� �������������� ���� ��������� ���������� ������� ������ ��������� ����������
		logger = malloc(sizeof(Log)); //�������� � ���� ������ ��� ���������
		logger->debug = write_debug; //
		logger->info = write_info; //
		logger->warning = write_warning; //
		logger->error = write_error; //
		is_init = 1; //��� ����������� ������ ������� ������������� �� �����������

	}

	return logger; //���������� ��������������������� ��������� �� ��������� ���� Log
}

static void write_debug(const char* message)
{
	static char prefix[120] = "Debug - ";//������� ����������� ��� ������� ����� ��������� � ������� ���������� ���������
	write_message((char*) prefix, message);

}

static void write_info(const char* message)
{
	static char prefix[120] = "Info - ";
	write_message(prefix, message);
}
static void write_warning(const char* message)
{
	static char prefix[120] = "Warning - ";
	write_message(prefix, message);
}
static void write_error(const char* message)
{
	static char prefix[120] = "Error - ";
	write_message(prefix, message);
}

static void write_message(char* prefix, const char* message)
{
	FILE* ptr; //������� ��������� �� ��������� ���� ����
	time_t lt; //��������� ���������� ���� lt ��� ������� ctime
	lt = time(NULL); //����������� lt ��������� ������� � �������
//	const char *postfix = ".txt";//������ ���������� ����� �������
	if ((ptr = fopen(file_name, "a+")) == NULL) //��������� ������ � ��������� ������������ ��� ��������
	{
		printf("Error\n"); //���� ������
		exit(1); //�������
	}
	fprintf(ptr, "%s %s\n", ctime(&lt), strcat(prefix, message)); //���������� � ���� ������ ����� ������� ��� ���(prefix) � ���� �������

	fclose(ptr); //��������� ����� �����
// ���������� �.�. ��� ���������� printf ����� � ����	printf("%s %s\n", ctime(&lt), strcat(prefix, message)); //���� ������� ��� ����������� ����� �������
}

