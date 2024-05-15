#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_list.h" // Подключаем заголовочный файл с объявлением функций для работы с очередью на основе вектора
#include "queue_vector.h"

#define MAX_PASSENGERS 100 // Максимальное количество пассажиров

// Структура для хранения информации о пассажире
struct Passenger {
    char id;
    int arrival_time;
    int service_time;
};

int main() {
    do {
        system("chcp 1251");

        int choice;
        void** counters = NULL;

        int num_counters; // Количество стоек регистрации
        printf("Enter the number of registration counters: ");
        while (scanf("%d", &num_counters) != 1) {
            printf("Incorrect input\n");
            scanf("%*s");
            printf("Enter the number of registration counters: ");
        }

        // Считываем информацию о пассажирах
        struct Passenger passengers[MAX_PASSENGERS];
        int num_passengers = 0;
        char input[MAX_PASSENGERS * 10]; // Предполагаем, что каждая запись о пассажире содержит не более 10 символов
        printf("Enter passenger information: ");
        scanf(" %[^\n]", input);

        // Какой метод мы используем
        printf("Run through a list or vector (0 - list, 1 - vector)?\n");
        while (scanf("%d", &choice) != 1 || (choice != 0 && choice != 1)) {
            printf("Incorrect input. Please enter 0 or 1: ");
            while (getchar() != '\n'); // Очистить буфер ввода
        }

        
        //struct Queue** counters = (struct Queue**)malloc(num_counters * sizeof(struct Queue*));
        // Инициализация очередей для каждой стойки регистрации в зависимости от выбора
        // Выделение памяти для массива указателей на структуры очередей
        counters = (void**)malloc(num_counters * sizeof(void*));
        for (int i = 0; i < num_counters; i++) {
            if (!choice)
                counters[i] = (void*)list_createQueue(); // Преобразование указателя к типу void*
            else
                counters[i] = (void*)vector_createQueue();
        }
        if (counters == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Обработка введенной информации о пассажирах
        char* token = strtok(input, " ");
        while (token != NULL) {
            sscanf(token, "%c/%d/%d", &passengers[num_passengers].id, &passengers[num_passengers].arrival_time, &passengers[num_passengers].service_time);
            num_passengers++;
            token = strtok(NULL, " ");
        }

        if (!choice) {
            // Обработка пассажиров по алгоритму Round-Robin
            int current_time = 0;
            int passenger_index = 0;
            while (1) {
                printf("%d: ", current_time);
                // Распределение пассажиров по стойкам регистрации
                for (int i = 0; i < num_counters; i++) {
                    if (!list_isEmpty(counters[i])) {
                        printf("№%d ", i + 1);
                        list_printQueue(counters[i]);
                        char id = list_front(counters[i]);

                        for (int j = 0; j < passenger_index; j++) {
                            if (id == passengers[j].id) {
                                passengers[j].service_time -= 1;
                                if (passengers[j].service_time == 0) {
                                    list_deQueue(counters[i]);
                                }
                            }
                        }
                    }
                    else {
                        printf("№%d ", i + 1);
                    }
                }
                printf("\n");

                // Добавление пассажиров в очереди стоек регистрации
                while (passenger_index < num_passengers && passengers[passenger_index].arrival_time - 1 <= current_time) {
                    list_enQueue(counters[passenger_index % num_counters], passengers[passenger_index].id);
                    passenger_index++;
                }

                // Проверка, завершились ли обработка всех пассажиров
                int all_counters_empty = 1;
                for (int i = 0; i < num_counters; i++) {
                    if (!list_isEmpty(counters[i])) {
                        all_counters_empty = 0;
                        break;
                    }
                }
                if (all_counters_empty && passenger_index >= num_passengers) {
                    break; // Если все стойки регистрации пусты и обработаны все пассажиры, завершаем цикл
                }

                current_time++;
            }
        }
        else {
            // Обработка пассажиров по алгоритму Round-Robin
            int current_time = 0;
            int passenger_index = 0;
            while (1) {
                printf("%d: ", current_time);
                // Распределение пассажиров по стойкам регистрации
                for (int i = 0; i < num_counters; i++) {
                    if (!vector_isEmpty(counters[i])) {
                        printf("№%d ", i + 1);
                        vector_printQueue(counters[i]);
                        char id = vector_front(counters[i]);

                        for (int j = 0; j < passenger_index; j++) {
                            if (id == passengers[j].id) {
                                passengers[j].service_time -= 1;
                                if (passengers[j].service_time == 0) {
                                    vector_deQueue(counters[i]);
                                }
                            }
                        }
                    }
                    else {
                        printf("№%d ", i + 1);
                    }
                }
                printf("\n");

                // Добавление пассажиров в очереди стоек регистрации
                while (passenger_index < num_passengers && passengers[passenger_index].arrival_time - 1 <= current_time) {
                    vector_enQueue(counters[passenger_index % num_counters], passengers[passenger_index].id);
                    passenger_index++;
                }

                // Проверка, завершились ли обработка всех пассажиров
                int all_counters_empty = 1;
                for (int i = 0; i < num_counters; i++) {
                    if (!vector_isEmpty(counters[i])) {
                        all_counters_empty = 0;
                        break;
                    }
                }
                if (all_counters_empty && passenger_index >= num_passengers) {
                    break; // Если все стойки регистрации пусты и обработаны все пассажиры, завершаем цикл
                }

                current_time++;
            }
        }



        // Освобождение памяти, выделенной для массива указателей на структуры очередей
        for (int i = 0; i < num_counters; i++) {
            free(counters[i]);
        }
        free(counters);

        printf("To exit, write 0, continue 1: ");
        int exit;
        while (scanf("%d", &exit) != 1 || (exit != 0 && exit != 1)) {
            printf("Incorrect input. Please enter 0 or 1: ");
            while (getchar() != '\n'); // Очистить буфер ввода
        }

        if (!exit) {
            return 0;
        }

    } while (1);

    return 0;
}
