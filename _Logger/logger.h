/*
 * logger.h

 *
 *  Created on: 13 ���. 2016 �.
 *      Author: ��������
 */
//���������-������ ������� ���������� � ��������� ���� ��� ������� ������������ ��� ���������� ������ ���������

#ifndef LOG_H
#define LOG_H


typedef struct //������� ����� ��� � ���� ��������� � ������ Log
{ //��������� ����� 4 ��������� �� 4 �������
	void (*debug)(const char* message); //
	void (*info)(const char* message); //
	void (*warning)(const char* message); //
	void (*error)(const char* message); //
}Log;

////////////////////////////////�������///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Log* get_logger(char *file_name); //��������� ������� ������� �������������� ��������� ���� Log ��������� ������ � ���� � ���������� ��������� �� ��� ���������
static void write_message(char* prefix, const char* message); //������� ���������� � ������ �������� ��������� � ��������� ���� ��������� � �������� ������ ����� ���������
static void write_debug(const char* message); //��������� � ��������� ��������� �������(debug, info, warning, error) ������ ���� ��� ���������
static void write_info(const char* message); //� �������� ������� ������ � ������
static void write_warning(const char* message); //��������� � ��������� ��������� �������(debug, info, warning, error) ������ ���� ��� ���������
static void write_error(const char* message); //� �������� ������� ������ � ������

#endif

