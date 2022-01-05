#include "pipex.h"

// Функция открывает файл в двух режимах: input и output
// Для режима input - если файл не найден - работа прерывается
// Для режима output - открывает/создает файл

int	ft_open_file(char *pathname, int flag)
{
	if (flag == 0)
	{
		if (access(pathname, F_OK))
		{
			write(2, "Error: there's not such file\n", 29);
			return (0);
		}
		return (open(pathname, O_RDONLY));
	}
	else
		return (open(pathname, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

//Функция открывает infile и outfile

int	main(int argc, char **argv)
{
	int input_fd;
	int output_fd;

	if (argc == 5)
	{
        input_fd = ft_open_file(argv[1], 0);
        output_fd = ft_open_file(argv[4], 1);
        // dup2(input_fd, 0);
        // dup2(output_fd, 1);
		
	}
	else
		write(2, "Usage : ./pipex infile cmd1 cmd2 outfile\n", 41);
	return (1);
}




//cmd k, cmd c - комментарий
//cmd k, cdm u - раскомментить
