/*
 * executable.c
 *
 *  Created on: 7 мая 2016 г.
 *      Author: Копраныч
 */
//Программа создает спецификацию для какого либо изделия и пользователь вводит в нее нужное количество элементов
//и сохраняет все на диск в фаил

#include "Create_spec.h"
#define INPUT_ARRAY_LEN 40
#define TYPE_INT 4



int main(int argc, char* argv[])
{
	Log *logger = get_logger("Logger_spec.txt");//создаем журнал инициализируем его и даем ему имя
	logger->info("getting started program\n");//первая запись в журнал: программа стартовала
	char command[INPUT_ARRAY_LEN], name[INPUT_ARRAY_LEN];//массивы для ввода комманд и имени спецификаций
	int numeral;//количество элементов в спецификации
	char p[] = "rtt";
	int i = strlen(p);
	for (;;)//бесконечный цикл
	{
		printf("Enter command!\n");//

		scanf("%s %s %d", command, name, &numeral);//вводим команду имя спецификации и количество элементов
		logger->info("Enter spec\n");//
		assert (strlen(command) < INPUT_ARRAY_LEN);//
		assert (strlen(name) < INPUT_ARRAY_LEN);//
		int check_size = sizeof(numeral);//
		assert (check_size == TYPE_INT);//
		if (!strcmp("Create", command))//если ввели "Create"
		{
			printf("spec %s was create\n", name);//то создаем спецификацию
			logger->info("Create spec\n");//
			printf("Enter the elements and their quantity \n");//вводим название и количество элементов
			device_spec(name, numeral);//и сохраняем спецификацию в файле
		}
		else if (!strcmp("Complect", command))//если ввели "Complect"
		{
			printf("Your spec %s\n", name);//то покацываем спецификацию
			logger->info("Spec read\n");//с запрашиваемым именем
			complect(name, numeral);//и входящие в нее элементы
		}
		else//иначе если ввели не правельную команду
		{
			printf("Enter the correct name order\n");//то просим ввести заново
			logger->warning("You entered wrong command\n");//
		}
		logger->info("Done\n");//
		printf("Done\n");//задание выполнили закончили и опять перешли на ввод нужной спецификации по кругу бесконено
	}
}
