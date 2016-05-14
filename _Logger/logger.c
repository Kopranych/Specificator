/*
 * logger.c
 *
 *  Created on: 13 апр. 2016 г.
 *      Author:  опраныч
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"

static char * file_name; //глобальный указатель на статическую переменную

Log* get_logger(char* name)
{
	file_name = name; //сохран€ем им€ файла-журнала
	static _Bool is_init; //обь€вл€ем статическую Ѕулеву переменную is_init
	Log* logger; //обь€вл€ем указатель на структуру типа Log
	if (!is_init) //если журнал открыт впервые т.е. is_init не проинициализирована равна нулю
	{ //то инициализируем нашу структуру присваива€ функции записи сообщений указателем
		logger = malloc(sizeof(Log)); //выдел€ем в куче пам€ть дл€ структуры
		logger->debug = write_debug; //
		logger->info = write_info; //
		logger->warning = write_warning; //
		logger->error = write_error; //
		is_init = 1; //при последующем вызове функции инициализаци€ не потребуетс€

	}

	return logger; //возвращаем проинициализированный указатель на структуру типа Log
}

static void write_debug(const char* message)
{
	static char prefix[120] = "Debug - ";//создаем статическое им€ которое будет сохранено в течении выполнени€ программы
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
	FILE* ptr; //создаем указатель на структуру типа фаил
	time_t lt; //обь€вл€ем переменную типа lt дл€ функции ctime
	lt = time(NULL); //присваиваем lt значентие времени в системе
	const char *postfix = ".txt";//задаем расширение файла журнала
	if ((ptr = fopen(strcat(file_name, postfix), "a+")) == NULL) //открываем журнал и провер€ем правильность его открыти€
	{
		printf("Error\n"); //если ошибка
		exit(1); //выходим
	}
	fprintf(ptr, "%s %s\n", ctime(&lt), strcat(prefix, message)); //записываем в фаил журнал врем€ событи€ его тип(prefix) и само событие
	printf("%s %s\n", ctime(&lt), strcat(prefix, message)); //плюс выводим это сообщениена экран консоли
	fclose(ptr); //закрываем поток файла
}

