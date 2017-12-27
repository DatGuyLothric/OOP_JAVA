#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

int p_sort(void);
int h_sort(void);
int *func(int *mass, int lt, int rt);

int main()
{
    setlocale(LC_ALL, "Rus");
    int c_work = 1;
    int c_work_2 = 1;
    int c_work_3 = 1;
    int p_s_w;
    int h_s_w;
    int e_line, e_line_2, i = 0, i2 = 0;
    char c;
    printf("Добро пожаловать в программу для сортировки массивов заданного количества элементов!\n");
    while (c_work)
    {
        printf("Выберите метод сортировки:\nВведите '1' для сортировки пузырьком,\nВведите '2' для сортировки Хоара.\n");
        c_work_2 = 1;
        while (c_work_2)
        {
            i2 = 0;
            c = getchar();
            while (c != '\n')
            {
                e_line = c - '0';
                i2++;
                if (c == ' ')
                    --i2;
                c = getchar();
            }
            if (i2 != 1)
                e_line = 0;
            if (e_line == 1)
            {
                p_s_w = p_sort();
                c_work_2 = 0;
            }
            else
                if (e_line == 2)
                {
                    h_s_w = h_sort();
                    c_work_2 = 0;
                }
                else
                {
                    printf("Ошибка! Вы ввели неверное значение!\nВведите '1' для сортировки пузырьком,\nВведите '2' для сортировки Хоара.\n");
                    c_work_2 = 1;
                }
        }
        printf("Если хотите продолжить, введите '1'.\nЕсли хотите выйти из программы, введите '2'\n");
        c_work_3 = 1;
        while (c_work_3)
        {
            i2 = 0;
            c = getchar();
            while (c != '\n')
            {
                e_line_2 = c - '0';
                i2++;
                if (c == ' ')
                    --i2;
                c = getchar();
            }
            if (i2 != 1)
                e_line_2 = 0;
            if (e_line_2 == 1)
            {
                c_work = 1;
                c_work_2 = 1;
                c_work_3 = 0;
            }
            else
                if (e_line_2 == 2)
                {
                    c_work = 0;
                    c_work_3 = 0;
                }
                else
                {
                    printf("Ошибка! Вы ввели неверное значение!\nЕсли хотите продолжить, введите '1'.\nЕсли хотите выйти из программы, введите '2'.\n");
                    c_work_3 = 1;
                }
        }
    }
    return 0;
}

int p_sort(void)
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int m_num, c_work = 1, c_work_2 = 1, c_w_err = 0, i, j, i2 = 0, j2, *mass = malloc(1024 * sizeof(int)), m_auto = 0, e_line, m, n, c_work_3, *mx = malloc(1024 * sizeof(int)), *mn = malloc(1024 * sizeof(int));
    char c, *e_m_num = malloc(1024 * sizeof(char)), *m_elem = malloc(1024 * sizeof(char)), *mx_el = malloc(1024 * sizeof(char)), *mn_el = malloc(1024 * sizeof(char));
    printf("Введите количество элементов массива. Помните, что размер массива не должен превышать 100 элементов!\n");
    c_work = 1;
    while (c_work)
    {
        c = getchar();
        i2 = 0;
        while (c != '\n')
        {
            if (((c - '0') > 9) || ((c - '0') < 0))
            {
                c_w_err = 1;
            }
            e_m_num [i2] = c;
            i2++;
            c = getchar();
        }
        if (c_w_err == 0)
        {
            m_num = atoi(e_m_num);
            c_work = 0;
            if ((m_num < 1) || (m_num > 100))
            {
                printf("Введенное значени выходит за установленные границы [1, 100]. Попробуйте ввести значение снова.\n");
                c_work = 1;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            c_work = 1;
        }
    }
    printf("Для заполнения массива вручную введите '1',\nДля автоматического заполнения массива введите '2'.\n");
    c_work_2 = 1;
    while (c_work_2)
    {
        i2 = 0;
        c = getchar();
        while (c != '\n')
        {
            e_line = c - '0';
            i2++;
            if (c == ' ')
                --i2;
            c = getchar();
        }
        if (i2 != 1)
            e_line = 0;
        if (e_line == 1)
        {
            m_auto = 0;
            c_work_2 = 0;
        }
        else
            if (e_line == 2)
            {
                m_auto = 1;
                c_work_2 = 0;
            }
            else
            {
                printf("Ошибка! Вы ввели неверное значение!\nДля заполнения массива вручную введите '1',\nДля автоматического заполнения массива введите '2'.\n");
                c_work_2 = 1;
            }
    }
    if (m_auto == 1)
    {
        i = 0;
        while (i < m_num)
        {
            mass[i] = rand();
        }
        printf("Произвольный массив создан!\n");
    }
    else
    {
        i = 0;
        printf("Введите элементы массива. Важно! Каждый елемент отделяйте клавишей 'Enter'.\n");
        while (i < m_num)
        {
            m_elem = malloc(1024 * sizeof(char));
            c_w_err = 0;
            i2 = 0;
            c = getchar();
            while (c != '\n')
            {
                if ((((c - '0') > 9) || ((c - '0') < 0)) && ((c - '0') != -3))
                {
                    c_w_err = 1;
                }
                m_elem[i2] = c;
                i2++;
                c = getchar();
            }
            if (c_w_err == 0)
            {
                mass[i] = atoi(m_elem);
                i++;
                if ((((i2 > 9) && (m_elem[0] == '-')) && ((m_elem[1] - '0') > 2)) || ((i2 > 8) && ((m_elem[0] - '0') > 2)))
                {
                    printf("Введенное значени выходит за установленные границы интеджера [-2147483648, 2147483648]. Попробуйте ввести значение снова.\n");
                    --i;
                }
            }
            else
            {
                printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            }
            free(m_elem);
        }
        printf("Массив записан успешно!\n");
    }
    printf("Производится сортировка пузырьком...\n");
    int p_elem;
    for (i = 0; i < m_num; i++)
    {
        for (j = 0; j < (m_num - 1); j++)
        {
            p_elem = mass[j];
            if (mass[j] == mass[j+1])
            {
                --m_num;
                for (j2 = j; j2 < m_num; j2++)
                {
                    mass[j2] = mass[j2+1];
                }
            }
            if (mass[j] > mass[j+1])
            {
                mass[j] = mass[j+1];
                mass[j+1] = p_elem;
            }
        }
    }
    printf("Сортировка пузырьком проведена успешно!\nОтсортированный массив:\n");
    for (i = 0; i < (m_num); i++)
    {
            printf("%d ", mass[i]);
    }
    printf("\nКакой максимум вы бы хотели узнать?\n");
    c_work_3 = 1;
    while (c_work_3)
    {
        c = getchar();
        i2 = 0;
        while (c != '\n')
        {
            if (((c - '0') > 9) || ((c - '0') < 0))
            {
                c_w_err = 1;
            }
            mx_el [i2] = c;
            i2++;
            c = getchar();
        }
        if (c_w_err == 0)
        {
            m = atoi(mx_el);
            c_work_3 = 0;
            if ((m < 1) || (m_num < m))
            {
                printf("Введенное значени выходит за установленные границы [1, %d]. Попробуйте ввести значение снова.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            c_work_3 = 1;
        }
    }
    printf("Какой минимум вы бы хотели узнать?\n");
    c_work_3 = 1;
    while (c_work_3)
    {
        c = getchar();
        i2 = 0;
        while (c != '\n')
        {
            if (((c - '0') > 9) || ((c - '0') < 0))
            {
                c_w_err = 1;
            }
            mn_el [i2] = c;
            i2++;
            c = getchar();
        }
        if (c_w_err == 0)
        {
            n = atoi(mn_el);
            c_work_3 = 0;
            if ((n < 1) || (m_num < n))
            {
                printf("Введенное значени выходит за установленные границы [1, %d]. Попробуйте ввести значение снова.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            c_work_3 = 1;
        }
    }
    printf("Искомый максимум: %d,\n", mass[m_num - m + 1]);
    printf("Искомый минимум: %d.\n", mass[n - 1]);
    printf("Работа программы завершена.\n");
    free (mass);
    free (mx_el);
    free (mn_el);
    free (mx);
    free (mn);
    return 0;
}

int h_sort(void)
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int m_num, c_work = 1, c_work_2 = 1, c_w_err = 0, i, j, i2 = 0, j2, *mass = malloc(1024 * sizeof(int)), m_auto = 0, e_line, m, n, c_work_3, *mx = malloc(1024 * sizeof(int)), *mn = malloc(1024 * sizeof(int));
    char c, *e_m_num = malloc(1024 * sizeof(char)), *m_elem = malloc(1024 * sizeof(char)), *mx_el = malloc(1024 * sizeof(char)), *mn_el = malloc(1024 * sizeof(char));
    printf("Введите количество элементов массива. Помните, что размер массива не должен превышать 100 элементов!\n");
    c_work = 1;
    while (c_work)
    {
        c = getchar();
        i2 = 0;
        while (c != '\n')
        {
            if (((c - '0') > 9) || ((c - '0') < 0))
            {
                c_w_err = 1;
            }
            e_m_num [i2] = c;
            i2++;
            c = getchar();
        }
        if (c_w_err == 0)
        {
            m_num = atoi(e_m_num);
            c_work = 0;
            if ((m_num < 1) || (m_num > 100))
            {
                printf("Введенное значени выходит за установленные границы [1, 100]. Попробуйте ввести значение снова.\n");
                c_work = 1;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            c_work = 1;
        }
    }
    printf("Для заполнения массива вручную введите '1',\nДля автоматического заполнения массива введите '2'.\n");
    c_work_2 = 1;
    while (c_work_2)
    {
        i2 = 0;
        c = getchar();
        while (c != '\n')
        {
            e_line = c - '0';
            i2++;
            if (c == ' ')
                --i2;
            c = getchar();
        }
        if (i2 != 1)
            e_line = 0;
        if (e_line == 1)
        {
            m_auto = 0;
            c_work_2 = 0;
        }
        else
            if (e_line == 2)
            {
                m_auto = 1;
                c_work_2 = 0;
            }
            else
            {
                printf("Ошибка! Вы ввели неверное значение!\nДля заполнения массива вручную введите '1',\nДля автоматического заполнения массива введите '2'.\n");
                c_work_2 = 1;
            }
    }
    if (m_auto == 1)
    {
        i = 0;
        while (i < m_num)
        {
            mass[i] = rand();
        }
        printf("Произвольный массив создан!\n");
    }
    else
    {
        i = 0;
        printf("Введите элементы массива. Важно! Каждый елемент отделяйте клавишей 'Enter'.\n");
        while (i < m_num)
        {
            m_elem = malloc(1024 * sizeof(char));
            c_w_err = 0;
            i2 = 0;
            c = getchar();
            while (c != '\n')
            {
                if ((((c - '0') > 9) || ((c - '0') < 0)) && ((c - '0') != -3))
                {
                    c_w_err = 1;
                }
                m_elem[i2] = c;
                i2++;
                c = getchar();
            }
            if (c_w_err == 0)
            {
                mass[i] = atoi(m_elem);
                i++;
                if ((((i2 > 9) && (m_elem[0] == '-')) && ((m_elem[1] - '0') > 2)) || ((i2 > 8) && ((m_elem[0] - '0') > 2)))
                {
                    printf("Введенное значени выходит за установленные границы интеджера [-2147483648, 2147483648]. Попробуйте ввести значение снова.\n");
                    --i;
                }
            }
            else
            {
                printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            }
            free(m_elem);
        }
        printf("Массив записан успешно!\n");
    }
    printf("Производится сортировка Хоара...\n");
    func(mass, 0, (m_num - 1));
    for (i = 0; i < (m_num - 1); i++)
    {
        if (mass[i] == mass[i+1])
        {
            --m_num;
            for (j = i; j < (m_num - 1); j++)
            {
                mass[j] = mass[j+1];
            }
        }
    }
    printf("Сортировка Хоара проведена успешно!\nОтсортированный массив:\n");
    for (i = 0; i < (m_num); i++)
    {
            printf("%d ", mass[i]);
    }
    printf("\nКакой максимум вы бы хотели узнать?\n");
    c_work_3 = 1;
    while (c_work_3)
    {
        c = getchar();
        i2 = 0;
        while (c != '\n')
        {
            if (((c - '0') > 9) || ((c - '0') < 0))
            {
                c_w_err = 1;
            }
            mx_el [i2] = c;
            i2++;
            c = getchar();
        }
        if (c_w_err == 0)
        {
            m = atoi(mx_el);
            c_work_3 = 0;
            if ((m < 1) || (m_num < m))
            {
                printf("Введенное значени выходит за установленные границы [1, %d]. Попробуйте ввести значение снова.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            c_work_3 = 1;
        }
    }
    printf("Какой минимум вы бы хотели узнать?\n");
    c_work_3 = 1;
    while (c_work_3)
    {
        c = getchar();
        i2 = 0;
        while (c != '\n')
        {
            if (((c - '0') > 9) || ((c - '0') < 0))
            {
                c_w_err = 1;
            }
            mn_el [i2] = c;
            i2++;
            c = getchar();
        }
        if (c_w_err == 0)
        {
            n = atoi(mn_el);
            c_work_3 = 0;
            if ((n < 1) || (m_num < n))
            {
                printf("Введенное значени выходит за установленные границы [1, %d]. Попробуйте ввести значение снова.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("Ошибка! Неверный формат ввода данных! Попробуйте ввести значение снова.\n");
            c_work_3 = 1;
        }
    }
    printf("Искомый максимум: %d,\n", mass[m_num - m + 1]);
    printf("Искомый минимум: %d.\n", mass[n - 1]);
    printf("Работа программы завершена.\n");
    free (mass);
    free (mx_el);
    free (mn_el);
    free (mx);
    free (mn);
    return 0;
}

int *func(int *mass, int lt, int rt)
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
