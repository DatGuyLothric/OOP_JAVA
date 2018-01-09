#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int p_sort(void);
int h_sort(void);
int *func(int *mass, int lt, int rt);
int prov_1(void);
int prov_2(void);
int prov_3(void);
int prov_4(void);
int prov_5(void);
int prov_6(void);
int prov_7(int e_m_num);

int main () /* Основная функция программы */
{
    setlocale(LC_ALL, "Rus");
    int c_work = 1, choice_1 = -1, p_s_w, choice_2 = -1;
    printf("Добро пожаловать в программу для сортировки массивов заданного количества элементов!\n");
    while (c_work)
    {
        printf("Выберите метод сортировки:\nВведите '1' для сортировки пузырьком,\nВведите '2' для сортировки Хоара.\n");
        choice_1 = prov_1();
        if (choice_1 == 1)
        {
            p_s_w = p_sort();
        }
        else
            if (choice_1 == 2)
            {
                p_s_w = h_sort();
            }
        printf("Если хотите продолжить, введите '1'.\nЕсли хотите выйти из программы, введите '2'\n");
        choice_2 = prov_2();
        if (choice_2 == 2)
        {
            c_work = 0;
        }
    }
    return 0;
}

int prov_1(void) /* Функция проверки ввода данных с клавиатуры */
{
    int e_line = 0;
    char *c, *p;
    while (1)
    {
        c = malloc(1024*sizeof(char));
        scanf("%s", c);
        e_line = atoi(c);
        strtol(c, &p, 10);
        if (*p != '\0')
        {
            e_line = 0;
        }
        if ((e_line == 1) || (e_line == 2))
        {
            return e_line;
        }
        else
        {
            printf("Ошибка! Вы ввели неверное значение!\nВведите '1' для сортировки пузырьком,\nВведите '2' для сортировки Хоара.\n");
        }
        free(c);
    }
}

int prov_2(void)
{
    int e_line = 0;
    char *c, *p;
    while (1)
    {
        c = malloc(1024*sizeof(char));
        scanf("%s", c);
        e_line = atoi(c);
        strtol(c, &p, 10);
        if (*p != '\0')
        {
            e_line = 0;
        }
        if ((e_line == 1) || (e_line == 2))
        {
            return e_line;
        }
        else
        {
            printf("Ошибка! Вы ввели неверное значение!\nЕсли хотите продолжить, введите '1'.\nЕсли хотите выйти из программы, введите '2'.\n");
        }
        free(c);
    }
}

int p_sort(void) /* Фнкция для сортировки пузырьком */
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int choice_1 = -1, choice_2 = -1, e_m_num, i, j, j2, *mass = malloc(1024 * sizeof(int)), m_auto = 0, m, n;
    printf("Введите количество элементов массива. Помните, что размер массива не должен превышать 100 элементов!\n");
    e_m_num = prov_3();
    printf("Для заполнения массива вручную введите '1',\nДля автоматического заполнения массива введите '2'.\n");
    m_auto = prov_4();
    if (m_auto == 2)
    {
        i = 0;
        while (i < e_m_num) /* Авт заполнение массива */
        {
            mass[i] = rand();
            i++;
        }
        printf("Произвольный массив создан!\n");
    }
    else
    {
        i = 0;
        printf("Введите элементы массива. Важно! Каждый елемент отделяйте клавишей 'Enter'. Пустой элемент будет записан как 0!\n");
        while (i < e_m_num)
        {
            mass[i] = prov_5(); /* Ручное заполнения массива */
            i++;
        }
        printf("Массив записан успешно!\n");
    }
    printf("Производится сортировка пузырьком...\n");
    int p_elem;
    for (i = 0; i < e_m_num; i++) /* Сортировка */
    {
        for (j = 0; j < (e_m_num - 1); j++)
        {
            p_elem = mass[j];
            if (mass[j] > mass[j+1])
            {
                mass[j] = mass[j+1];
                mass[j+1] = p_elem;
            }
        }
    }
    printf("Введите '1', если хотите удалить повторяющиеся элементы. В противном случае введите '2'.\n");
    choice_1 = prov_6();
    if (choice_1 == 1)
    {
        for (j = 0; j < (e_m_num - 1); j++) /* Удаление повторяющихся элементов */
        {
             while (mass[j] == mass[j+1])
             {
                --e_m_num;
                for (j2 = j; j2 < e_m_num; j2++)
                {
                    mass[j2] = mass[j2+1];
                }
                if (j == (e_m_num - 1))
                {
                    break;
                }
             }
        }
    }
    printf("Сортировка пузырьком проведена успешно!\nОтсортированный массив:\n");
    for (i = 0; i < e_m_num; i++)
    {
            printf("%d ", mass[i]);
    }
    printf("\nКакой максимум вы бы хотели узнать?\n");
    m = prov_7(e_m_num);
    printf("Какой минимум вы бы хотели узнать?\n");
    n = prov_8(e_m_num);
    printf("Искомый максимум: %d,\n", mass[e_m_num - m]);
    printf("Искомый минимум: %d.\n", mass[n - 1]);
    printf("Работа программы завершена.\n");
    return 0;
    free(mass);
}

int prov_3(void) /* Проверка ввода */
{
    char *p;
    int c_w_err, m_num;
    char *e_m_num;
    while (1)
    {
        c_w_err = 0;
        e_m_num = malloc(1024*sizeof(char));
        scanf("%s", e_m_num);
        m_num = atoi(e_m_num);
        strtol(e_m_num, &p, 10);
        if (*p != '\0')
        {
            c_w_err = 1;
        }
        if (c_w_err == 0)
        {
            if ((m_num < 1) || (m_num > 100))
            {
                printf("Введенное значени выходит за установленные границы [1, 100]. Попробуйте ввести значение снова.\n");
            }
            else
            {
                return m_num;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
        }
        free(e_m_num);
    }
}

int prov_4(void) /* Проверка ввода */
{
    int e_line;
    char *c, *p;
    while (1)
    {
        c = malloc(1024*sizeof(char));
        scanf("%s", c);
        e_line = atoi(c);
        strtol(c, &p, 10);
        if (*p != '\0')
        {
            e_line = 0;
        }
        if ((e_line == 1) || (e_line == 2))
        {
            return e_line;
        }
        else
        {
            printf("Ошибка! Вы ввели неверное значение!\nДля заполнения массива вручную введите '1',\nДля автоматического заполнения массива введите '2'.\n");
        }
        free(c);
    }
}

int prov_5(void) /* Зполнение массива */
{
    int c_w_err = 0, mass;
    float cc, massf;
    long int bb = 2147483646, bbm = -2147483647;
    char c, *m_elem, *p;
    while(1)
    {
        c_w_err = 0;
        m_elem = malloc(1024*sizeof(char));
        scanf("%s", m_elem);
        massf = atof(m_elem);
        strtol(m_elem, &p, 10);
        if (*p != '\0')
        {
            c_w_err = 1;
        }
        if (c_w_err == 0)
        {
            if ((massf > bb) || (massf < bbm))
            {
                printf("Введенное значени выходит за установленные границы интеджера [-2147483648, 2147483648]. Попробуйте ввести значение снова.\n");
            }
            else
            {
                mass = atoi(m_elem);
                return mass;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
        }
        free(m_elem);
    }
}

int prov_6(void) /* Проверка ввода */
{
    int i2 = 0, e_line;
    char *c, *p;
    while (1)
    {
        c = malloc(1024*sizeof(char));
        scanf("%s", c);
        e_line = atoi(c);
        strtol(c, &p, 10);
        if (*p != '\0')
        {
            e_line = 0;
        }
        if ((e_line == 1) || (e_line == 2))
        {
            return e_line;
        }
        else
        {
            printf("Ошибка! Вы ввели неверное значение!\nВведите '1', если хотите удалить повторяющиеся элементы. В противном случае введите '2'.\n");
        }
        free(c);
    }
}

int prov_7(int e_m_num) /* Проверка ввода */
{
    int c_w_err = 0, m, m_num = e_m_num;
    char *p, *mx_el = malloc(1024*sizeof(char));
    while (1)
    {
        c_w_err = 0;
        mx_el = malloc(1024*sizeof(char));
        scanf("%s", mx_el);
        m = atoi(mx_el);
        strtol(mx_el, &p, 10);
        if (*p != '\0')
        {
            c_w_err = 1;
        }
        if (c_w_err == 0)
        {
            if ((m < 1) || (m_num < m))
            {
                printf("Введенное значени выходит за установленные границы [1, %d]. Попробуйте ввести значение снова.\n", m_num);
            }
            else
            {
                return m;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
        }
        free(mx_el);
    }
}

int prov_8(int e_m_num) /* Проверка ввода */
{
    int m_num = e_m_num, n, c_w_err;
    char *p, *mn_el = malloc(1024*sizeof(char));
    while (1)
    {
        c_w_err = 0;
        mn_el = malloc(1024*sizeof(char));
        scanf("%s", mn_el);
        n = atoi(mn_el);
        strtol(mn_el, &p, 10);
        if (*p != '\0')
        {
            c_w_err = 1;
        }
        if (c_w_err == 0)
        {
            if ((n < 1) || (m_num < n))
            {
                printf("Введенное значени выходит за установленные границы [1, %d]. Попробуйте ввести значение снова.\n", m_num);
            }
            else
            {
                return n;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
        }
        free(mn_el);
    }
}

int h_sort(void) /* Сортировка Хоара */
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int choice_1, choice_2, e_m_num, i, j, j2, *mass = malloc(1024 * sizeof(int)), m_auto = 0, m, n;
    printf("Введите количество элементов массива. Помните, что размер массива не должен превышать 100 элементов!\n");
    e_m_num = prov_3();
    printf("Для заполнения массива вручную введите '1',\nДля автоматического заполнения массива введите '2'.\n");
    m_auto = prov_4();
    if (m_auto == 2)
    {
        i = 0;
        while (i < e_m_num)
        {
            mass[i] = rand();
            i++;
        }
        printf("Произвольный массив создан!\n");
    }
    else
    {
        i = 0;
        printf("Введите элементы массива. Важно! Каждый елемент отделяйте клавишей 'Enter'.\n");
        while (i < e_m_num)
        {
            mass[i] = prov_5();
            i++;
        }
        printf("Массив записан успешно!\n");
    }
    printf("Производится сортировка Хоара...\n");
    func(mass, 0, (e_m_num - 1)); /* Вызов функции сортировки */
    printf("Введите '1', если хотите удалить повторяющиеся элементы. В противном случае введите '2'.\n");
    choice_1 = prov_6();
    if (choice_1 == 1)
    {
        for (j = 0; j < (e_m_num - 1); j++)
        {
             while (mass[j] == mass[j+1])
             {
                --e_m_num;
                for (j2 = j; j2 < e_m_num; j2++)
                {
                    mass[j2] = mass[j2+1];
                }
                if (j == (e_m_num - 1))
                {
                    break;
                }
             }
        }
    }
    printf("Сортировка Хоара проведена успешно!\nОтсортированный массив:\n");
    for (i = 0; i < e_m_num; i++)
    {
            printf("%d ", mass[i]);
    }
    printf("\nКакой максимум вы бы хотели узнать?\n");
    m = prov_7(e_m_num);
    printf("Какой минимум вы бы хотели узнать?\n");
    n = prov_8(e_m_num);
    printf("Искомый максимум: %d,\n", mass[e_m_num - m]);
    printf("Искомый минимум: %d.\n", mass[n - 1]);
    printf("Работа программы завершена.\n");
    return 0;
    free(mass);
}

int *func(int *mass, int lt, int rt) /* Функция сортировки */
{
    int i = lt, j = rt;
    int el, x = mass[(lt + rt) / 2];
    do
    {
        while (mass[i] < x)
            i++;
        while (mass[j] > x)
            --j;
        if (i <= j)
        {
            if (i < j)
            {
                el = mass[i];
                mass[i] = mass[j];
                mass[j] = el;
            }
            i++;
            --j;
        }
    } while (i <= j);
    if (i < rt)
        func(mass, i, rt);
    if (lt < j)
        func(mass, lt, j);
    return mass;
}
