#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int k;
	ssize_t nrd, nwr;
	char *file;

	if (!filename)
		return (0);

	k = open(filename, O_RDONLY);

	if (k == -1)
		return (0);

	file = malloc(sizeof(char) * (letters));
	if (!file)
		return (0);

	nrd = read(k, file, letters);
	nwr = write(STDOUT_FILENO, file, nrd);

	close(k);

	free(file);

	return (nwr);
}
