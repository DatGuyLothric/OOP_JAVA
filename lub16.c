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
    printf("����� ���������� � ��������� ��� ���������� �������� ��������� ���������� ���������!\n");
    while (c_work)
    {
        printf("�������� ����� ����������:\n������� '1' ��� ���������� ���������,\n������� '2' ��� ���������� �����.\n");
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
                    printf("������! �� ����� �������� ��������!\n������� '1' ��� ���������� ���������,\n������� '2' ��� ���������� �����.\n");
                    c_work_2 = 1;
                }
        }
        printf("���� ������ ����������, ������� '1'.\n���� ������ ����� �� ���������, ������� '2'\n");
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
                    printf("������! �� ����� �������� ��������!\n���� ������ ����������, ������� '1'.\n���� ������ ����� �� ���������, ������� '2'.\n");
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
    printf("������� ���������� ��������� �������. �������, ��� ������ ������� �� ������ ��������� 100 ���������!\n");
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
                printf("��������� ������� ������� �� ������������� ������� [1, 100]. ���������� ������ �������� �����.\n");
                c_work = 1;
            }
        }
        else
        {
            printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            c_work = 1;
        }
    }
    printf("��� ���������� ������� ������� ������� '1',\n��� ��������������� ���������� ������� ������� '2'.\n");
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
                printf("������! �� ����� �������� ��������!\n��� ���������� ������� ������� ������� '1',\n��� ��������������� ���������� ������� ������� '2'.\n");
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
        printf("������������ ������ ������!\n");
    }
    else
    {
        i = 0;
        printf("������� �������� �������. �����! ������ ������� ��������� �������� 'Enter'.\n");
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
                    printf("��������� ������� ������� �� ������������� ������� ��������� [-2147483648, 2147483648]. ���������� ������ �������� �����.\n");
                    --i;
                }
            }
            else
            {
                printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            }
            free(m_elem);
        }
        printf("������ ������� �������!\n");
    }
    printf("������������ ���������� ���������...\n");
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
    printf("���������� ��������� ��������� �������!\n��������������� ������:\n");
    for (i = 0; i < (m_num); i++)
    {
            printf("%d ", mass[i]);
    }
    printf("\n����� �������� �� �� ������ ������?\n");
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
                printf("��������� ������� ������� �� ������������� ������� [1, %d]. ���������� ������ �������� �����.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            c_work_3 = 1;
        }
    }
    printf("����� ������� �� �� ������ ������?\n");
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
                printf("��������� ������� ������� �� ������������� ������� [1, %d]. ���������� ������ �������� �����.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            c_work_3 = 1;
        }
    }
    printf("������� ��������: %d,\n", mass[m_num - m + 1]);
    printf("������� �������: %d.\n", mass[n - 1]);
    printf("������ ��������� ���������.\n");
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
    printf("������� ���������� ��������� �������. �������, ��� ������ ������� �� ������ ��������� 100 ���������!\n");
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
                printf("��������� ������� ������� �� ������������� ������� [1, 100]. ���������� ������ �������� �����.\n");
                c_work = 1;
            }
        }
        else
        {
            printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            c_work = 1;
        }
    }
    printf("��� ���������� ������� ������� ������� '1',\n��� ��������������� ���������� ������� ������� '2'.\n");
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
                printf("������! �� ����� �������� ��������!\n��� ���������� ������� ������� ������� '1',\n��� ��������������� ���������� ������� ������� '2'.\n");
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
        printf("������������ ������ ������!\n");
    }
    else
    {
        i = 0;
        printf("������� �������� �������. �����! ������ ������� ��������� �������� 'Enter'.\n");
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
                    printf("��������� ������� ������� �� ������������� ������� ��������� [-2147483648, 2147483648]. ���������� ������ �������� �����.\n");
                    --i;
                }
            }
            else
            {
                printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            }
            free(m_elem);
        }
        printf("������ ������� �������!\n");
    }
    printf("������������ ���������� �����...\n");
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
    printf("���������� ����� ��������� �������!\n��������������� ������:\n");
    for (i = 0; i < (m_num); i++)
    {
            printf("%d ", mass[i]);
    }
    printf("\n����� �������� �� �� ������ ������?\n");
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
                printf("��������� ������� ������� �� ������������� ������� [1, %d]. ���������� ������ �������� �����.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            c_work_3 = 1;
        }
    }
    printf("����� ������� �� �� ������ ������?\n");
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
                printf("��������� ������� ������� �� ������������� ������� [1, %d]. ���������� ������ �������� �����.\n", m_num);
                c_work_3 = 1;
            }
        }
        else
        {
            printf("������! �������� ������ ����� ������! ���������� ������ �������� �����.\n");
            c_work_3 = 1;
        }
    }
    printf("������� ��������: %d,\n", mass[m_num - m + 1]);
    printf("������� �������: %d.\n", mass[n - 1]);
    printf("������ ��������� ���������.\n");
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
