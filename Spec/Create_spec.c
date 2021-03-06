/*
 * Create_spec.c
 *
 *  Created on: 7 ��� 2016 �.
 *      Author: ��������
 */

#include "Create_spec.h"

#define INPUT_ARRAY_LEN 40
#define TYPE_INT 4
#define SIZE_ELEMENT 20

int device_spec(char *name, int number)
{
	Log *logger = get_logger("Logger_spec.txt");
	FILE *sp; // ������� ��������� �� ��������� ���� FILE
	assert(strlen(name) < INPUT_ARRAY_LEN);
	int check_size = sizeof(number);
	assert(check_size == TYPE_INT);
	device specif[number]; //������� ������ �������� ���� device � ������ specif � �������� size_struct
	int i = 0; // ��������� ������� ����������
	const char *extention = ".txt"; //��������� ���������� �������� ����� ������������

	if ((sp = fopen(strcat(name, extention), "a+")) == NULL) //�������/�������� ���� � ������ ������/������ � ������ � ����������� ��� ����������
	{ //� ������� ������� strcat(������� ���������� ���������� ���������� �����)���� ���� �������� ��� ������ �� ����������,�����
		logger->error("Error opening file\n");
		printf("ERROR\n");          //����� ��������� ������
		exit(1);          //�������
	}

	while (i < number)   // ������ ������ �������� ��������� � ������������
	{

		scanf("%s %d", specif[i].element, &(specif[i].number)); //���� ��������� i-��� ���������
		assert(strlen(specif[i].element) < SIZE_ELEMENT);
		logger->info("Enter elements\n");
		int check_size = sizeof(specif[i].number);
		assert(check_size == TYPE_INT);

		if (!(strcmp("commit_spec", specif[i].element))) //��������� ���� ���� �� ��������� �������� "commit_spec"
		{
			logger->info("finished typing\n");
			break;          // �� ����������� ���� ������
		}
		else          //�����
		{
			logger->info("Write data in file\n");
			fprintf(sp, "%s %d\n", specif[i].element, specif[i].number); //������� ������ � ����
			assert(sp);
		}
		i++;          //��������� � ��������� i-��� ���������
	}

	printf("spec was commited\n"); //����� ��������� ������� ������ �������� �� ����� "spec was commited"
	fclose(sp);          //��������� ����� ������
	return 0;          //
}

int complect(char *name, int number)
{
	Log *logger = get_logger("Logger_spec.txt");
	FILE *sp;
	int i = 0;
	const char *extention = ".txt"; //��������� ���������� �������� ����� ������������

	if ((sp = fopen(strcat(name, extention), "a+")) == NULL)
	{
		logger->error("Error opening file\n");
		printf("ERROR\n");
		exit(1);
	}
	device specif[number];
	while (fscanf(sp, "%s %d", specif[i].element, &(specif[i].number)) != EOF)
	{
		logger->info("Read elements\n");
		fprintf(stdout, "%s %d", specif[i].element, specif[i].number);
		fprintf(stdout, "\r\n");
		i++;
	}
	fclose(sp);
	return 0;
}
