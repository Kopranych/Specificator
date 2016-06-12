/*
 * executable.c
 *
 *  Created on: 7 ��� 2016 �.
 *      Author: ��������
 */
//��������� ������� ������������ ��� ������ ���� ������� � ������������ ������ � ��� ������ ���������� ���������
//� ��������� ��� �� ���� � ����

#include "Create_spec.h"
#define INPUT_ARRAY_LEN 40
#define TYPE_INT 4



int main(int argc, char* argv[])
{
	Log *logger = get_logger("Logger_spec.txt");//������� ������ �������������� ��� � ���� ��� ���
	logger->info("getting started program\n");//������ ������ � ������: ��������� ����������
	char command[INPUT_ARRAY_LEN], name[INPUT_ARRAY_LEN];//������� ��� ����� ������� � ����� ������������
	int numeral;//���������� ��������� � ������������
	char p[] = "rtt";
	int i = strlen(p);
	for (;;)//����������� ����
	{
		printf("Enter command!\n");//

		scanf("%s %s %d", command, name, &numeral);//������ ������� ��� ������������ � ���������� ���������
		logger->info("Enter spec\n");//
		assert (strlen(command) < INPUT_ARRAY_LEN);//
		assert (strlen(name) < INPUT_ARRAY_LEN);//
		int check_size = sizeof(numeral);//
		assert (check_size == TYPE_INT);//
		if (!strcmp("Create", command))//���� ����� "Create"
		{
			printf("spec %s was create\n", name);//�� ������� ������������
			logger->info("Create spec\n");//
			printf("Enter the elements and their quantity \n");//������ �������� � ���������� ���������
			device_spec(name, numeral);//� ��������� ������������ � �����
		}
		else if (!strcmp("Complect", command))//���� ����� "Complect"
		{
			printf("Your spec %s\n", name);//�� ���������� ������������
			logger->info("Spec read\n");//� ������������� ������
			complect(name, numeral);//� �������� � ��� ��������
		}
		else//����� ���� ����� �� ���������� �������
		{
			printf("Enter the correct name order\n");//�� ������ ������ ������
			logger->warning("You entered wrong command\n");//
		}
		logger->info("Done\n");//
		printf("Done\n");//������� ��������� ��������� � ����� ������� �� ���� ������ ������������ �� ����� ���������
	}
}
