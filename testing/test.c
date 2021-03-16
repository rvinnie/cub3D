#include "../includes/cub3d.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
			j--;

		}
		i++;
	}
}


int		main()
{
	int size = 4;
	int i = 0;
	int arr[size];

	arr[0] = 4;
	arr[1] = 3;
	arr[2] = 2;
	arr[3] = 1;
	bubble_sort(arr, size);
	while (i < size)
		printf("%d\n", arr[i++]);
}

// void bubbleSort(int *num, int size)
// {
//   // Для всех элементов
//   for (int i = 0; i < size - 1; i++)
//   {
//     for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
//     {
//       if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
//       {
//         int temp = num[j - 1]; // меняем их местами
//         num[j - 1] = num[j];
//         num[j] = temp;
//       }
//     }
//   }
// }